/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include <QGuiApplication>
#include <QApplication>

#include "Initialize.hpp"

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


