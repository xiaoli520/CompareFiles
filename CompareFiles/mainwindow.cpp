#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBitmap>
#include <QPixmap>
#include <QPainter>
#include <QBrush>
#include <QRectF>
#include <QStylePainter>
#include <QStyleOption>
#include <QDebug>
#include <QMenu>
#include <QDesktopWidget>
#include <QResizeEvent>
#include <QVariantMap>
#include "wmidwidget.h"
#include "wappcomm.h"
#include "wnavigationbar.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    WBaseQssWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
   setWindowState(windowState() | Qt::WindowActive);

    vBoxLayout = new QVBoxLayout(this);
    topWidget  = new WTopWidget(this);
    topWidget->setObjectName("topbg");
    connect(topWidget, SIGNAL(triggerClose()), this, SLOT(closeWindows()));
    footLabel  = new QLabel(this);
    footLabel->setObjectName("footbg");

    WMidWidget* midWidget=new WMidWidget(this);
    vBoxLayout->addWidget(topWidget);
    vBoxLayout->addWidget(midWidget);
    vBoxLayout->addWidget(footLabel);
    vBoxLayout->setMargin(0);
    vBoxLayout->setSpacing(0);
    setLayout(vBoxLayout);

    QString fileName=PTR_WAPP_COMM->getQssFilePath("mainwindow.qss");
    loadStyleSheetFromFile(fileName);

    //init mask
    QRegion regTop(QBitmap(PTR_WAPP_COMM->getImagePath("topbg_mask.png")));
    QRegion regBottom(QBitmap(PTR_WAPP_COMM->getImagePath("footerbg_mask.png")));
    QRect rectTop = regTop.boundingRect();
    QRect rectBottom = regBottom.boundingRect();
    regTopLeft = regTop.intersected(QRect(rectTop.topLeft(), QSize(10,10)));
    regTopRight = regTop.intersected(QRect(rectTop.topRight()-QPoint(10,0), QSize(10,10)));
    regBottomLeft = regBottom.intersected(QRect(rectBottom.bottomLeft()-QPoint(0,10), QSize(10,10)));
    regBottomRight = regBottom.intersected(QRect(rectBottom.bottomRight()-QPoint(10,10), QSize(10,10)));
    resize(997,720);

    mouseInOut = new WMouseInOutWidget(this);
    WNavigationBar* bar= new WNavigationBar(mouseInOut);
    connect(bar,SIGNAL(setAutoHide(bool)),mouseInOut,SLOT(setIsAutoHide(bool)));
    mouseInOut->setMinimumHeight(50);
    mouseInOut->setChildWidget(bar,true);
    mouseInOut->setIsAutoHide(true);
    mouseInOut->startShowAutoHide();
    mouseInOut->setAutoScrollOffset(false);
   // mouseInOut->startTimer(3000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMaxSize()
{
    mRect = normalGeometry();
    QRect tempRect = QApplication::desktop()->availableGeometry();
    this->setGeometry(tempRect);
    vBoxLayout->setContentsMargins(0,0,0,0);
}

void MainWindow::showNormalSize()
{
    if (!mRect.isNull())
    {
        this->setGeometry(mRect);
        vBoxLayout->setContentsMargins(5,5,5,5);
    }
}

void MainWindow::closeWindows()
{
    QApplication::closeAllWindows();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    if(mouseInOut)
    {
       QRect rect=topWidget->rect();
       mouseInOut->setGeometry(rect.left(),rect.bottom(),this->rect().width(),mouseInOut->rect().height());
    }
       // set mask
       if (!regTopLeft.isEmpty() && !regTopRight.isEmpty() && !regBottomLeft.isEmpty() && !regBottomRight.isEmpty())
       {
           QRect rectTopLeft = regTopLeft.boundingRect();
           QRect rectTopRight = regTopRight.boundingRect();
           QRect rectBottomLeft = regBottomLeft.boundingRect();
           QRect rectBottomRight = regBottomRight.boundingRect();

           regTopRight.translate(rect().width()-rectTopRight.width()-rectTopRight.x(), 0);
           regBottomLeft.translate(0, rect().height()-rectBottomLeft.height()-rectBottomLeft.y());
           regBottomRight.translate(rect().width()-rectBottomRight.width()-rectBottomRight.x(),
                                    rect().height()-rectBottomRight.height()-rectBottomRight.y());

           rectTopRight = regTopRight.boundingRect();
           rectBottomLeft = regBottomLeft.boundingRect();
           rectBottomRight = regBottomRight.boundingRect();

           QRegion regMask(QRect(rectTopLeft.bottomLeft(), rectBottomRight.topRight()));
           regMask = regMask.united(QRect(rectTopLeft.topRight(), rectBottomRight.bottomLeft()));
           regMask = regMask.united(regTopLeft);
           regMask = regMask.united(regTopRight);
           regMask = regMask.united(regBottomLeft);
           regMask = regMask.united(regBottomRight);
           setMask(regMask);
       }
       else
           clearMask();

       vBoxLayout->setMargin(0);
}
