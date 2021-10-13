#include "funQ2C.h"
#include "FunDevice.h"
#include "../functionQ/scrcpy/server.h"

FunQ2C::FunQ2C(QObject *parent) : QObject(parent)
{
    mServer = new Server();
}

FunQ2C::~FunQ2C()
{
    for (auto device : Devices)
    {
        mServer->popDevice(device->getName());
        delete device;
    }
}

QString FunQ2C::ver() const
{
    return Version;
}
void FunQ2C::startServer()
{
    mServer->startServer();
}

FunDevice *FunQ2C::pushNewDevice(QString deviceName)
{
    if (Devices.find(deviceName) == Devices.end())
    {
        FunDevice *device = new FunDevice();
        if (device != Q_NULLPTR)
        {
            device->setName(deviceName);
            mServer->pushDevice(device);
        }
        Devices[deviceName] = device;
    }
    return Devices[deviceName];
};

void FunQ2C::popDevice(QString deviceName)
{
    if (Devices.find(deviceName) != Devices.end())
    {
        mServer->popDevice(deviceName);
        delete Devices[deviceName];
        Devices.remove(deviceName);
    }
}
