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

    m_vBoxLayout = new QVBoxLayout(this);
    m_topWidget  = new WTopWidget(this);
    m_topWidget->setObjectName("topbg");
    connect(m_topWidget, SIGNAL(triggerClose()), this, SLOT(closeWindows()));
    m_footLabel  = new QLabel(this);
    m_footLabel->setObjectName("footbg");
    m_spaceLabel = new QLabel(this);

    WMidWidget* midWidget=new WMidWidget(this);
    m_vBoxLayout->addWidget(m_topWidget);
    m_vBoxLayout->addWidget(m_spaceLabel);
    m_vBoxLayout->addWidget(midWidget);
    m_vBoxLayout->addWidget(m_footLabel);
    m_vBoxLayout->setMargin(0);
    m_vBoxLayout->setSpacing(0);
    setLayout(m_vBoxLayout);

    QString fileName=PTR_WAPP_COMM->getQssFilePath("mainwindow.qss");
    loadStyleSheetFromFile(fileName);

    //init mask
    QRegion regTop(QBitmap(PTR_WAPP_COMM->getImagePath("topbg_mask.png")));
    QRegion regBottom(QBitmap(PTR_WAPP_COMM->getImagePath("footerbg_mask.png")));
    QRect rectTop = regTop.boundingRect();
    QRect rectBottom = regBottom.boundingRect();
    m_regTopLeft = regTop.intersected(QRect(rectTop.topLeft(), QSize(10,10)));
    m_regTopRight = regTop.intersected(QRect(rectTop.topRight()-QPoint(10,0), QSize(10,10)));
    m_regBottomLeft = regBottom.intersected(QRect(rectBottom.bottomLeft()-QPoint(0,10), QSize(10,10)));
    m_regBottomRight = regBottom.intersected(QRect(rectBottom.bottomRight()-QPoint(10,10), QSize(10,10)));
    resize(997,720);

    m_mouseInOut = new WMouseInOutWidget(this);
    WNavigationBar* bar= new WNavigationBar(m_mouseInOut);
    connect(bar,SIGNAL(setAutoHide(bool)),m_mouseInOut,SLOT(setIsAutoHide(bool)));
    m_mouseInOut->setMinimumHeight(50);
    m_mouseInOut->setChildWidget(bar,true);
    m_mouseInOut->setIsAutoHide(true);
    m_mouseInOut->startShowAutoHide();
    m_mouseInOut->setAutoScrollOffset(false);
    m_spaceLabel->setMinimumHeight(50);

    connect(m_mouseInOut,SIGNAL(mouseInWidget()),this,SLOT(showSpaceLabel()));
    connect(m_mouseInOut,SIGNAL(mouseOutWidget()),this,SLOT(hideSpaceLabel()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMaxSize()
{
    m_mRect = normalGeometry();
    QRect tempRect = QApplication::desktop()->availableGeometry();
    this->setGeometry(tempRect);
    m_vBoxLayout->setContentsMargins(0,0,0,0);
}

void MainWindow::showNormalSize()
{
    if (!m_mRect.isNull())
    {
        this->setGeometry(m_mRect);
        m_vBoxLayout->setContentsMargins(5,5,5,5);
    }
}

void MainWindow::closeWindows()
{
    QApplication::closeAllWindows();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    if(m_mouseInOut)
    {
       QRect rect=m_topWidget->rect();
       m_mouseInOut->setGeometry(rect.left(),rect.bottom(),this->rect().width(),m_mouseInOut->rect().height());
    }
       // set mask
       if (!m_regTopLeft.isEmpty() && !m_regTopRight.isEmpty() && !m_regBottomLeft.isEmpty() && !m_regBottomRight.isEmpty())
       {
           QRect rectTopLeft = m_regTopLeft.boundingRect();
           QRect rectTopRight = m_regTopRight.boundingRect();
           QRect rectBottomLeft = m_regBottomLeft.boundingRect();
           QRect rectBottomRight = m_regBottomRight.boundingRect();

           m_regTopRight.translate(rect().width()-rectTopRight.width()-rectTopRight.x(), 0);
           m_regBottomLeft.translate(0, rect().height()-rectBottomLeft.height()-rectBottomLeft.y());
           m_regBottomRight.translate(rect().width()-rectBottomRight.width()-rectBottomRight.x(),
                                    rect().height()-rectBottomRight.height()-rectBottomRight.y());

           rectTopRight = m_regTopRight.boundingRect();
           rectBottomLeft = m_regBottomLeft.boundingRect();
           rectBottomRight = m_regBottomRight.boundingRect();

           QRegion regMask(QRect(rectTopLeft.bottomLeft(), rectBottomRight.topRight()));
           regMask = regMask.united(QRect(rectTopLeft.topRight(), rectBottomRight.bottomLeft()));
           regMask = regMask.united(m_regTopLeft);
           regMask = regMask.united(m_regTopRight);
           regMask = regMask.united(m_regBottomLeft);
           regMask = regMask.united(m_regBottomRight);
           setMask(regMask);
       }
       else
           clearMask();

       m_vBoxLayout->setMargin(0);
}

void MainWindow::showSpaceLabel()
{
    m_spaceLabel->setVisible(true);
}

void MainWindow::hideSpaceLabel()
{
     m_spaceLabel->setVisible(false);
}
