/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "Window.hpp"

int Window::WindowWidth (0);
int Window::WindowHeight (0);


Window::Window(QScreen *screen)
    : QWindow(screen)

{
    setSurfaceType(QSurface::OpenGLSurface);

    // Get desktop screen parameters
    QDesktopWidget DW;


    if (DW.screenCount() > 1)
    {
        //qDebug() << "Number of screens: " << DW.screenCount();
        int PrimaryScreen = DW.primaryScreen();
        QRect QR = DW.availableGeometry(PrimaryScreen);
        resize(QR.width(),QR.height());
    }

    else

    {
        //qDebug() << "Primary Screen Width and Height: " << DW.width() << DW.height();
        resize(DW.width(),DW.height());
    }

    Window::WindowWidth = DW.width();
    Window::WindowHeight = DW.height();

    QSurfaceFormat format;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        format.setVersion(4, 3);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize( 24 );
    format.setSamples( 4 );
    format.setStencilBufferSize(8);
    setFormat(format);
    create();
}

Window::~Window()
{
}

void Window::keyPressEvent( QKeyEvent* e )
{
    switch ( e->key() )
    {
        case Qt::Key_Escape:
            this->close();
            break;

        default:
            QWindow::keyPressEvent( e );
    }
}

void Window::Exit (void)
{
    this->close();
}
