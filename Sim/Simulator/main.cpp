/*!
  \title New Simulator

  The new simulator is used to provide.

*/

#include "SimGlobals.hpp"

int main(int argc, char* argv[])
{
    //QGuiApplication Start(argc, argv);
    QApplication Start(argc, argv);

    //Start initializing the scene
    Initialize *Init = new Initialize();
    Init->id();


    Start.closeAllWindows();

    return (true);




}


