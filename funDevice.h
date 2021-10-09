#ifndef _FUNDEVICE_H
#define _FUNDEVICE_H

#include <QAxFactory>
#include <QPixmap>
#include "../functionQ/scrcpy/device.h"
#include "../functionQ/scrcpy/controller/action.h"
#include "../functionQ/scrcpy/adbprocess.h"

class FunDevice : public Device
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74667}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE7}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055F7}")
public:
    explicit FunDevice(QObject *parent = nullptr);

private:
    Action *action = Q_NULLPTR;
public slots:
    void Name(QString deviceName);
    QString getName();

    QPixmap getPixmap();
    uint &getFrameData();
    int getFrameWidth();
    int getFrameHeight();

    void goHome();
};

#endif