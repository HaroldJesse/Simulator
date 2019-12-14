#pragma once
#ifndef HELM_HPP
#define HELM_HPP
//#endif // HELM_HPP

#include <QWidget>
#include <Qt3DRender>
#include <QTextToSpeech>
#include <QMessageBox>

#include "Setup.hpp"
#include "PositionOrientation.hpp"
#include "RCS2000.hpp"
#include "RCS1000.hpp"

namespace Ui {
class Helm;
}


class Helm : public QWidget
{
    Q_OBJECT

public:
    explicit Helm(QWidget *parent = nullptr);

    ~Helm();

    void ExitHelm ();
    bool LoadHelm (Qt3DRender::QCamera *CameraEntity);
    bool UnLoadHelm (Qt3DRender::QCamera *CameraEntity);

public slots:

signals:
    void Helmoff();
    void CloseHelm();

private:
     QTextToSpeech *Verbalize = new QTextToSpeech;

};

#endif // HELM_HPP
