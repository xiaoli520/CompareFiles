#include "wmidwidget.h"
#include "ui_wmidwidget.h"
#include "wappcomm.h"
#include "weventcontroller.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QFileInfo>

WMidWidget::WMidWidget(QWidget *parent) :
    WBaseQssWidget(parent),
    ui(new Ui::WMidWidget)
{
    ui->setupUi(this);
    PTR_EVENT_CTL->installListenEvent(this,WBaseEvent::TYPE_OPEN_LEFT_FILE);
    PTR_EVENT_CTL->installListenEvent(this,WBaseEvent::TYPE_OPEN_RIGHT_FILE);
    PTR_EVENT_CTL->installListenEvent(this,WBaseEvent::TYPE_SAVE_TO_FILE);

    m_leftScrollBar = new QScrollBar();
    m_rightScrollBar = new QScrollBar();
    m_leftScrollBar->setObjectName("leftScrollBar");
    m_rightScrollBar->setObjectName("rightScrollBar");

    m_leftTextBrowser = new WTextBrowser(1,m_leftScrollBar,this);
    m_leftTextBrowser->setObjectName("leftTextBrowser");
    m_rightTextBrowser = new WTextBrowser(2,m_rightScrollBar,this);
    m_rightTextBrowser->setObjectName("rightTextBrowser");


    //左边布局
    QHBoxLayout*  leftLayout= new QHBoxLayout;
    leftLayout->setSpacing( 0 );
    leftLayout->setMargin( 0 );
    leftLayout->addWidget( m_leftScrollBar );
    leftLayout->addWidget( m_leftTextBrowser );
    QFrame*  leftContainer = new QFrame;
    leftContainer->setFrameShadow( QFrame::Sunken );
    leftContainer->setFrameShape( QFrame::StyledPanel );
    leftContainer->setLineWidth( 1 );
    leftContainer->setLayout(leftLayout);

    //右边布局
    QHBoxLayout*  rightLayout= new QHBoxLayout;
    rightLayout->setSpacing( 0 );
    rightLayout->setMargin( 0 );
    rightLayout->addWidget( m_rightTextBrowser );
    rightLayout->addWidget( m_rightScrollBar );
    QFrame*  rightContainer = new QFrame;
    rightContainer->setFrameShadow( QFrame::Sunken );
    rightContainer->setFrameShape( QFrame::StyledPanel );
    rightContainer->setLineWidth( 1 );
    rightContainer->setLayout(rightLayout);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addWidget(leftContainer);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(rightContainer);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout( mainLayout );

    m_compareThread = new WCompareThread(this);

}

WMidWidget::~WMidWidget()
{
    delete ui;
    PTR_EVENT_CTL->removeListenEvent(this);
    if(m_compareThread->isRunning())
    {
        m_compareThread->quit();
        m_compareThread->wait();
        delete m_compareThread;
    }
}

void WMidWidget::customEvent(QEvent *event)
{
    WBaseEvent* const selfEvent = dynamic_cast<WBaseEvent*>(event);
    const int type = static_cast< int >( selfEvent->type() );
    switch(type)
    {
       case WBaseEvent::TYPE_OPEN_LEFT_FILE:
          {
              QString filename=selfEvent->getData("filename").toString();
              qDebug()<<__FUNCTION__<<"filename="<<filename;
              if(m_leftTextBrowser)
                  m_leftTextBrowser->readFile(filename);

              startCompareFile();
              break;
          }
       case WBaseEvent::TYPE_OPEN_RIGHT_FILE:
       {
            QString filename=selfEvent->getData("filename").toString();
            qDebug()<<__FUNCTION__<<"filename="<<filename;
            if(m_rightTextBrowser)
                m_rightTextBrowser->readFile(filename);

            startCompareFile();
            break;
       }
    case WBaseEvent::TYPE_SAVE_TO_FILE:
    {
        QString filename=selfEvent->getData("filename").toString();
        qDebug()<<__FUNCTION__<<"filename="<<filename;
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate|QFile::Text))
         {
            qDebug()<<__FUNCTION__<<"open file error name="<<filename;
            break;
        }
        QTextStream out(&file);
        QVector<sDiffInfo> diflist=m_leftTextBrowser->getDiffInfo();
        for(int i=0; i < diflist.size(); i++)
        {
            if(!diflist[i].m_isEqual)
            {
                //只写不相等的行
                QString str=diflist[i].toString();
                out<<str<<"\n";
            }
        }
        file.close();
        break;
    }
    default:
        break;
    }
}

void WMidWidget::startCompareFile()
{
   if(!m_leftTextBrowser || m_leftTextBrowser->getFilePath().isEmpty())
        return;

   if(!m_rightTextBrowser || m_rightTextBrowser->getFilePath().isEmpty())
       return;


    QFileInfo info(m_leftTextBrowser->getFilePath());
    QFileInfo info2(m_rightTextBrowser->getFilePath());


    if(!info.isFile() || !info.exists())
        return;

    if(!info2.isFile() || !info2.exists())
        return;

    if(m_compareThread->isRunning())
    {
        m_compareThread->quit();
        m_compareThread->wait();
    }

    m_compareThread->setFileName(m_leftTextBrowser->getFilePath(),m_rightTextBrowser->getFilePath());

    m_compareThread->start();
}
