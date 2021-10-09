#include "funQ2C.h"

FunQ2C::FunQ2C(QObject *parent) : QObject(parent)
{
    mServer = new Server();
}

QString FunQ2C::ver() const
{
    return "1.0";
}
void FunQ2C::startServer()
{
    mServer->startServer();
}
void FunQ2C::pushNewDevice(FunDevice *device)
{
    mServer->pushDevice(QPointer<Device>(device));
};