#ifndef HELM_HPP
#define HELM_HPP

#include <QWidget>
#include <Qt3DRender>
#include <QTextToSpeech>
#include <QMessageBox>

#include "Setup.hpp"
#include "PositionOrientation.hpp"
#include "RCS2000.hpp"
#include "RCS1000.hpp"

class Helm : public QWidget
{
    Q_OBJECT

public:
    explicit Helm(QWidget *parent = nullptr);
    //~Helm();

    bool LoadHelm (Qt3DRender::QCamera *CameraEntity);
    bool UnLoadHelm (Qt3DRender::QCamera *CameraEntity);

public slots:
    void ExitHelm (void);

signals:
    void CloseHelm();

private:
     QTextToSpeech *Verbalize = new QTextToSpeech;

};

#endif // HELM_HPP
