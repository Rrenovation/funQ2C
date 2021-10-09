#include "funDevice.h"

FunDevice::FunDevice(QObject *parent) : Device(parent)
{
}

void FunDevice::Name(QString deviceName)
{
    setDeviceName(deviceName);
    action = getAction();
}

QString FunDevice::getName()
{
    return getDeviceName();
}

void FunDevice::goHome()
{
    action->goHome();
}

uint &FunDevice::getFrameData()
{
    auto frame = getFrame();
    return (uint &)frame->data;
}

QPixmap FunDevice::getPixmap()
{
    auto frame = getFrame();
    QImage img(frame->data, frame->width, frame->height, QImage::Format_RGB888);
    return QPixmap::fromImage(img);
}
int FunDevice::getFrameWidth()
{
    auto frame = getFrame();
    return frame->width;
}
int FunDevice::getFrameHeight()
{
    auto frame = getFrame();
    return frame->height;
}