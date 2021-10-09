
#include <QAxFactory>
#include <QCoreapplication>

#include "FunDevice.h"
#include "funQ2C.h"

//! [1]
QAXFACTORY_BEGIN(
    "{EC08F8FC-2754-47AB-8EFE-56A54057F34E}", // type library ID
    "{A095BA0C-224F-4933-A458-2DD7F6B85D8F}") // application ID
QAXCLASS(FunQ2C)
QAXCLASS(FunDevice)
QAXFACTORY_END()
//! [1]


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    if (!QAxFactory::isServer()) {
        // create and show main window
    }
    return app.exec();
}