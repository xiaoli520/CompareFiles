﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QList>
#include <QMap>
#include <QStackedLayout>
#include "wbaseqsswidget.h"
#include "wtopwidget.h"
#include "wmouseinoutwidget.h"
#include <QBitmap>
#include <QRegion>
class LoadStateWidget;

namespace Ui {
class MainWindow;
}

class WStoreMain;

#define  W    990
#define  H    680
#define  R    7
#define  C1   4
#define  C2   130


class MainWindow : public WBaseQssWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:

    void resizeEvent(QResizeEvent *);

public slots:

     void showMaxSize();

     void showNormalSize();

     void closeWindows();

     void showSpaceLabel();
     void hideSpaceLabel();

private:
    Ui::MainWindow *ui;
    WTopWidget*     m_topWidget;
    QLabel*         m_footLabel;
    QLabel*         m_midLabel;
    QLabel*         m_spaceLabel;
    QVBoxLayout*    m_vBoxLayout;
    QBitmap m_bit;
    QRect  m_mRect;
    QRegion m_regTopLeft;
    QRegion m_regTopRight;
    QRegion m_regBottomLeft;
    QRegion m_regBottomRight;

    WMouseInOutWidget* m_mouseInOut;
};

#endif // MAINWINDOW_H
