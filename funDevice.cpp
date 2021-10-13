#include "funDevice.h"

FunDevice::FunDevice(QObject *parent) : Device(parent)
{
}

FunDevice::~FunDevice()
{
    free(bmpBuff);
}

void FunDevice::consumeFrame()
{
    auto frame = getFrame();
    data = frame->data;
    width = frame->width;
    height = frame->height;
    callBackFun();
}

void FunDevice::setName(QString deviceName)
{
    setDeviceName(deviceName);
    action = getAction();
}

QString FunDevice::getName()
{
    return getDeviceName();
}

int FunDevice::getFrameData()
{
    return (int)data;
}

int FunDevice::getWidth()
{
    return width;
}
int FunDevice::getHeight()
{
    return height;
}

int FunDevice::getBmpPicSize()
{

    BmpHead m_BMPHeader = {0};
    InfoHead m_BMPInfoHeader = {0};
    char bfType[2] = {'B', 'M'};
    int header_size = sizeof(bfType) + sizeof(BmpHead) + sizeof(InfoHead);

    m_BMPHeader.imageSize = 3 * width * height + header_size;
    m_BMPHeader.startPosition = header_size;
    m_BMPInfoHeader.Length = sizeof(InfoHead);
    m_BMPInfoHeader.width = width;
    m_BMPInfoHeader.height = height;
    m_BMPInfoHeader.colorPlane = 1;
    m_BMPInfoHeader.bitColor = 24;
    m_BMPInfoHeader.realSize = 3 * width * height;

    if (bmpBuff == Q_NULLPTR)
    {
        bmpBuff = malloc(header_size + width * height * 3);
    }
    else
    {
        bmpBuff = realloc(bmpBuff, header_size + width * height * 3);
    }

    memcpy(bmpBuff, bfType, sizeof(bfType));
    memcpy((uint8_t *)bmpBuff + sizeof(bfType), &m_BMPHeader, sizeof(m_BMPHeader));
    memcpy((uint8_t *)bmpBuff + sizeof(m_BMPHeader) + sizeof(bfType), &m_BMPInfoHeader, sizeof(m_BMPInfoHeader));
    for (int scan = 1; scan < height; scan++)
    {
        memcpy((uint8_t *)bmpBuff + header_size + width * (height - scan) * 3, (uint8_t *)data + width * scan * 3, width * 3);
    }

    return width * height * 3 + header_size;
}

int FunDevice::getBmpPic()
{
    return (int)bmpBuff;
}

void FunDevice::callBack(int callback)
{
    callBackFun = (FUNC)callback;
}

void FunDevice::home()
{
    action->goHome();
}

void FunDevice::copy()
{
    action->onCopy();
}

void FunDevice::back()
{
    action->goBack();
}

void FunDevice::menu()
{
    action->goMenu();
}

void FunDevice::appSwitch()
{
    action->appSwitch();
}

void FunDevice::power()
{
    action->onPower();
}

void FunDevice::clear(int num)
{
    action->onClear(num);
}

void FunDevice::keyCode(int code)
{
    action->postKeyCodeClick(static_cast<AndroidKeycode>(code));
}

void FunDevice::keyCodeHold(int code)
{
    action->postKeyCodeClickHold(static_cast<AndroidKeycode>(code));
}

void FunDevice::keyCodeRelease(int code)
{
    action->postKeyCodeClickRelease(static_cast<AndroidKeycode>(code));
}

void FunDevice::click(int x1, int x2, int id)
{
    action->click(QRect(x1, x2, getWidth(), getHeight()), static_cast<quint64>(id));
}

void FunDevice::clickHold(int x1, int x2, int id)
{
    action->clickHold(QRect(x1, x2, getWidth(), getHeight()), static_cast<quint64>(id));
}

void FunDevice::clickRelease(int x1, int x2, int id)
{
    action->clickRelease(QRect(x1, x2, getWidth(), getHeight()), static_cast<quint64>(id));
}

void FunDevice::move(int x1, int x2, int id)
{
    action->fingerMove(QRect(x1, x2, getWidth(), getHeight()), static_cast<quint64>(id));
}

void FunDevice::sendText(QString text)
{
    action->sendText(text);
}

void FunDevice::sendtextEx(QString text)
{
    action->sendTextEx(text);
}
