#ifndef _FUNQ2C_H
#define _FUNQ2C_H

#include <QAxFactory>

class FunDevice;
class Server;

class FunQ2C : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74669}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE0}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055FF}")
public:
    explicit FunQ2C(QObject *parent = nullptr);
    ~FunQ2C();
signals:


public slots:
    QString ver() const;
    bool startServer(int port=37321);
    FunDevice* pushNewDevice(QString deviceName);
    void popDevice(QString deviceName);
private:
    const QString Version = "1.0.1";
    Server *mServer = Q_NULLPTR;
    QMap<QString,FunDevice*> Devices;
};

#endif // _FUNQ2C_H