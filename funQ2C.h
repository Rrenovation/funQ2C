#ifndef _FUNQ2C_H
#define _FUNQ2C_H

#include <QAxFactory>
#include "FunDevice.h"

#include "../functionQ/scrcpy/server.h"

class FunQ2C : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74669}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE0}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055FF}")
public:
    explicit FunQ2C(QObject *parent = nullptr);
signals:
    void onsingal();

public slots:
    QString ver() const;
    void startServer();
    void pushNewDevice(FunDevice *device);

private:
    Server *mServer = Q_NULLPTR;
};

#endif // _FUNQ2C_H