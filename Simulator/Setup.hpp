#pragma once
#ifndef SETUP_HPP
#define SETUP_HPP
#endif // SETUP_HPP

#include <QString>
#include <QDialog>
#include <QVoice>
#include <QtTextToSpeech>

namespace Ui {
class Setup;
}

class Setup : public QDialog
{
    Q_OBJECT

public:
    explicit Setup(QWidget *parent = nullptr);
    ~Setup();

    void SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br);
    void SetAllCorners(int Radius);

    static QString SimType;
    static QString SimBranch;
    static QString SimClass;
    static QString SimQuadrant;
    static QString SimSector;
    static QString SimLocation;
    static QString SimObject;
    static QString SimCraftType;
    static QString SimCraftName;

    static QStringList SimTypeList;
    static QStringList SimBranchList;
    static QStringList SimQuadranList;
    static QStringList SimSectorList;
    static QStringList SimLocationList;
    static QStringList SimObjectList;
    static QStringList SimCraftTypeList;
    static QStringList SimCraftNameList;


private:
        QTextToSpeech *Verbalize = new QTextToSpeech;
        QVector<QVoice> VoiceList;

public slots:

    void Exit(void);

signals:


private:
    Ui::Setup *ui;



private slots:
    void TypeChanged(void);
    void BranchChanged(void);
    void ClassChanged (void);
    void QuadrantChanged(void);
    void SectorChanged(void);
    void LocationChanged(void);
    void ObjectChanged(void);
    void CraftType(void);
    void CraftName(void);

};
