#ifndef MAINWINDOW_H
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

private:
    Ui::MainWindow *ui;
    WTopWidget*     topWidget;
    QStackedLayout* stackLayout;
    QLabel*         footLabel;
    QLabel*         midLabel;
    QVBoxLayout*    vBoxLayout;
    QBitmap bit;
    QRect  mRect;
    QRegion regTopLeft;
    QRegion regTopRight;
    QRegion regBottomLeft;
    QRegion regBottomRight;
};

#endif // MAINWINDOW_H
