#include "funAdb.h"

FunAdb::FunAdb(QObject *parent) : Adbprocess(parent)
{
}

FunAdb::~FunAdb()
{
}
void FunAdb::SetPatch(QString patch)
{
    setAdbPatch(patch);
}

void FunAdb::SetSerial(QString serial)
{
    setSerial(serial);
}

void FunAdb::StartApplication(QString application)
{
    startapplication(application);
}

void FunAdb::KillApplication(QString application)
{
    killapplication(application);
}

bool FunAdb::AutoConnect()
{
    return autoConnect();
}

bool FunAdb::ConnectDevice()
{
    return connectDevice();
}
void FunAdb::Reverse(QString deviceSocketName, quint16 localPort)
{
    reverse(deviceSocketName, localPort);
}

bool FunAdb::Push(QString local, QString remote)
{
    return push(local, remote);
}


bool FunAdb::Appprocess(QString fps)
{
    return appprocess(fps);
}

QString FunAdb::Uiautomator()
{
    QString ret;
    auto newData = uiautomator();
    for (auto list : newData)
    {
        for (auto vaule : list)
        {
            ret.push_back(vaule);
            ret.push_back("|");
        }
        ret.push_back("\r\n");
    }
    return ret;
}

QString FunAdb::UiFind(QString text, int type)
{
    QString ret;
    auto newData = uiFind(text, static_cast<Adbprocess::AutoMator>(type));
    for (auto list : newData)
    {
        for (auto value : list)
        {
            ret.push_back(value);
            ret.push_back("|");
        }
        ret.push_back("\r\n");
    }
    return ret;
}

QString FunAdb::UiGetBounds(QString text, int type)
{
    QString ret;
    auto newData = uiGetBounds(text, static_cast<Adbprocess::AutoMator>(type));
    for (auto list : newData)
    {
        for (auto value : list)
        {
            ret.push_back(QString::number(value));
            ret.push_back("|");
        }
        ret.push_back("\r\n");
    }
    return ret;
}
