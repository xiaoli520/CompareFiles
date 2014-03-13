#include "wtextbrowsernum.h"
#include "ui_wtextbrowsernum.h"
#include "wappcomm.h"
#include <QTextLine>
#include <QPainter>
#include <QTextBlock>
#include <QDebug>

WTextBrowserNum::WTextBrowserNum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTextBrowserNum)
{
    ui->setupUi(this);
    m_textBrowser = (WTextBrowser*)parent;
    setMaximumWidth(30);
    setMinimumWidth(30);
    setFont(PTR_WAPP_COMM->getDiffShowFont());
}

WTextBrowserNum::~WTextBrowserNum()
{
    delete ui;
}

 void WTextBrowserNum::updateLineNumber()
 {
     setGeometry(QRect( 0, 0,rect().width(), m_textBrowser->viewport()->height() ) );
     update();
 }

 void WTextBrowserNum::paintEvent(QPaintEvent *e)
 {
     QWidget::paintEvent(e);
     QPainter p(this);
     QTextBlock block = m_textBrowser->document()->begin();
     int linenum=0;
     QColor backColor = QColor(255,255,255);
     p.fillRect(rect(),backColor);

     while( block.isValid() ) {
         for( int i = 0 ; i < block.lineCount(); i ++)
         {
             QRect textRect=rect();
             textRect.setTop(block.layout()->position().y());
             QTextLine line = block.layout()->lineAt(i);
             textRect.setHeight(line.height());
             QString lineText=QString::number(linenum+1);
             QPen pen;
             if(linenum < m_textBrowser->m_difList.size())
             {
                 sDiffInfo info=m_textBrowser->m_difList.at(linenum);
                 if(!info.m_isEqual)
                     pen.setColor(PTR_WAPP_COMM->getNotDiffNumberLineColor());
             }
             else
                 pen.setColor(PTR_WAPP_COMM->getDiffNumberLineColor());

             p.setPen(pen);
             p.drawText(textRect.x(),textRect.y(),textRect.width(),textRect.height(),Qt::AlignHCenter|Qt::AlignVCenter,lineText);
             linenum ++;
         }
         block = block.next();
     }
     p.end();

 }
