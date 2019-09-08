#include "SimGlobals.hpp"
#include <Qt3DExtras/QFirstPersonCameraController>

int main(int argc, char *argv[])
{

    //QApplication inherits QGuiApplication
    QApplication Start(argc, argv);



    Initialize *Init = new Initialize();

    if (Init->isEnabled() == false)
    {
        qDebug() << "Initialization failure";
    }

    //qDebug() << "After Init";
    return true;
}

