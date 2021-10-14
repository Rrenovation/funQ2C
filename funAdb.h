#ifndef __FUNADB__
#define __FUNADB__

#include <QAxFactory>

#include "../functionQ/scrcpy/adbprocess.h"

class FunAdb : public Adbprocess
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74666}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE6}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055F6}")
public:
    explicit FunAdb(QObject *parent = nullptr);
    ~FunAdb();
signals:

public slots:
    void SetPatch(QString patch);
    void SetSerial(QString serial);

    void StartApplication(QString application); //adb shell am start -n 包名/类名 adb shell am start -n 包名/包名.MainActivity
    void KillApplication(QString application);  //adb shell am force-stop 包名

    bool AutoConnect();
    bool ConnectDevice();
    void Reverse(QString deviceSocketName, quint16 localPort);
    bool Push(QString local, QString remote);
    bool Appprocess(QString fps = "5");

    QString Uiautomator();
    QString UiFind(QString text, int type = 1);
    QString UiGetBounds(QString text, int type = 1);

private:
};

#endif