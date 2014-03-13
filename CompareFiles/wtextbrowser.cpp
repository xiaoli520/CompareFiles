#include "wtextbrowser.h"
#include <QFileInfo>
#include <QDebug>
#include <QTextLine>
#include <QTextBlock>
#include <QPainter>
#include "weventcontroller.h"
#include "wdiffinfoevent.h"
#include "wappcomm.h"
#include "wtextbrowsernum.h"

WTextBrowser::WTextBrowser(int type,QScrollBar* scrollbar, QWidget*parent):QTextBrowser(parent)
{
    m_type=type;
    m_scrollBar=scrollbar;
    setAcceptDrops( true );
    setAcceptRichText( false );

  //  setFontPointSize(16);
    QFont font=PTR_WAPP_COMM->getDiffShowFont();
    setFont(font);
    setFrameShadow( Plain );
    setFrameShape( NoFrame );
    setLineWrapMode( NoWrap );

    setAutoFillBackground( true );

    PTR_EVENT_CTL->installListenEvent(this,WBaseEvent::TYPE_COMPARE_FILE_OVER);
    if(m_scrollBar != NULL)
        initScrollBar();

    m_textBrowserNum = new WTextBrowserNum(this);
    setViewportMargins(0, 0, 0, 0 );
    m_textBrowserNum->setVisible(false);
}

WTextBrowser::~WTextBrowser()
{

    PTR_EVENT_CTL->removeListenEvent(this);
}

/**
 * @brief readFile  读取文件
 * @param filename
 * @return
 */
bool WTextBrowser::readFile(QString filename)
{
    QFileInfo fileInfo(filename);
    if(!fileInfo.exists())
    {
     //   clear();
        return false;
    }

    if(!fileInfo.isFile())
    {
       // clear();
        return false;
    }

    QFile file( filename);
    if(file.open( QIODevice::ReadOnly ))
    {
       clear();
       QByteArray data = file.readAll();
       setPlainText( QString::fromLocal8Bit( data ) );
       file.close();
       document()->adjustSize();
       m_fileName = filename;
       setViewportMargins(m_textBrowserNum->width(), 0, 0, 0 );
       m_textBrowserNum->setVisible(true);
       m_textBrowserNum->updateLineNumber();
       return true;
    }

    return false;
}

void WTextBrowser::initScrollBar()
{
    m_scrollBar->setMinimum ( verticalScrollBar()->minimum() );
    m_scrollBar->setMaximum ( verticalScrollBar()->maximum() );
    m_scrollBar->setPageStep( verticalScrollBar()->pageStep() );
    m_scrollBar->setValue   ( verticalScrollBar()->value() );

    connect( verticalScrollBar(), SIGNAL( rangeChanged( int, int ) ),
             this               , SLOT  ( setScrollRange( int, int ) ) );
   connect( m_scrollBar            , SIGNAL( valueChanged( int ) ),
             this               , SLOT  ( setScrollValue   ( int ) ) );
    connect( m_scrollBar            , SIGNAL( sliderMoved ( int ) ),
             this               , SLOT  ( setScrollValue   ( int ) ) );

    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    m_scrollBar->setVisible( m_scrollBar->maximum() != 0 );
}

void WTextBrowser::setScrollRange(int min, int max)
{
    m_scrollBar->setRange(min,max);
    m_scrollBar->setPageStep(verticalScrollBar()->pageStep() );
    m_scrollBar->setVisible(max);
}

void WTextBrowser::setScrollValue(int value)
{
    verticalScrollBar()->setValue(value);
}

 void WTextBrowser::customEvent(QEvent *event)
 {
     WBaseEvent* const selfEvent = dynamic_cast<WBaseEvent*>(event);
     const int type = static_cast< int >( selfEvent->type() );
     switch(type)
     {
        case WBaseEvent::TYPE_COMPARE_FILE_OVER:
         {
             WDiffInfoEvent* const diffEvent = dynamic_cast<WDiffInfoEvent*>(event);
             m_difList=diffEvent->getDiffDataList();
             qDebug()<<__FUNCTION__<<" data size="<<m_difList.size();
             document()->adjustSize();
             setViewportMargins(m_textBrowserNum->width(), 0, 0, 0 );
              m_textBrowserNum->setVisible(true);
              m_textBrowserNum->updateLineNumber();
         }
         break;
     }
 }

 void WTextBrowser::paintEvent(QPaintEvent *e)
 {
     if(!m_difList.isEmpty())
     {
         QPainter p( viewport() );
         QTextBlock block = document()->begin();
         int linenum=0;
         while( block.isValid() ) {
             for( int i = 0 ; i < block.lineCount(); i ++)
             {
                 if(linenum < m_difList.size())
                 {
                     sDiffInfo info=m_difList.at(linenum);
                     if(!info.m_isEqual)
                     {
                         QColor pc = PTR_WAPP_COMM->getDiffFillColor();
                         QTextLine line = block.layout()->lineAt(i);
                         p.fillRect(0, block.layout()->position().y(), viewport()->width(), line.height(), pc);
                     }
                 }
                 linenum ++;
             }
             block = block.next();
         }
         p.end();
     }

     QTextBrowser::paintEvent(e);
 }
