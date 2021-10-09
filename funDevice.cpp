#include "funDevice.h"

FunDevice::FunDevice(QObject *parent) : Device(parent)
{
    
}

void FunDevice::deviceName(QString deviceName)
{
    this->setDeviceName(deviceName);
    action = this->getAction();
}

QString FunDevice::getName()
{
    return this->getDeviceName();
}

void FunDevice::goHome()
{
    action->goHome();
}