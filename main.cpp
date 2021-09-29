
#include <QAxFactory>

class funQ2C : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74669}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE0}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055FF}")
public:
    explicit funQ2C(QObject *parent = nullptr)
        : QObject(parent)
    {
    }

signals:
    void onNewFrame();

public slots:
    QString ver() const
    {
        return "1.0";
    }
};

//! [0]
#include "main.moc"

//! [1]
QAXFACTORY_BEGIN(
    "{EC08F8FC-2754-47AB-8EFE-56A54057F34E}", // type library ID
    "{A095BA0C-224F-4933-A458-2DD7F6B85D8F}") // application ID
QAXCLASS(funQ2C)
QAXFACTORY_END()
//! [1]
