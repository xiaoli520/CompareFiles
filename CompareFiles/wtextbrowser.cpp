#include "wtextbrowser.h"
#include <QFileInfo>

WTextBrowser::WTextBrowser(QScrollBar* scrollbar, QWidget*parent):QTextBrowser(parent)
{
    m_scrollBar=scrollbar;
    setAcceptDrops( true );
    setAcceptRichText( false );

    setFrameShadow( Plain );
    setFrameShape( NoFrame );
    setLineWidth( 0 );

    setLineWrapMode( NoWrap );
    setAutoFillBackground( true );

    if(m_scrollBar != NULL)
        initScrollBar();
}

WTextBrowser::~WTextBrowser()
{

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
        clear();
        return false;
    }

    if(!fileInfo.isFile())
    {
        clear();
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
