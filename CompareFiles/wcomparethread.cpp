#include "wcomparethread.h"
#include <QFile>
#include "uhashtool.h"
#include <QVector>
#include "weventcontroller.h"
#include "defines.h"
#include "wdiffinfoevent.h"
#include <QDebug>

WCompareThread::WCompareThread(QObject *parent):
    QThread(parent)
{

}

void WCompareThread::setFileName(QString leftFile,QString rightFile)
{
    m_leftFileName=leftFile;
    m_rightFileName=rightFile;
}

void WCompareThread::run()
{
    QFile leftFile(m_leftFileName);
    QFile rightFile(m_rightFileName);
    if(!leftFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<__FUNCTION__<<"left file open error filename="<<m_leftFileName;
        leftFile.close();
        return;
    }

    if(!rightFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<__FUNCTION__<<"left file open error filename="<<m_rightFileName;
        rightFile.close();
        return;
    }

    QVector<sDiffInfo> diffInfo;
    int lineNumber=1;
    while(true)
    {
        QByteArray leftline;
        if(!leftFile.atEnd())
            leftline=leftFile.readLine();

        QByteArray rightline;
        if(!rightFile.atEnd())
            rightline =rightFile.readLine();

        bool equal=true;
        if(!leftline.isEmpty() && !rightline.isEmpty())
        {
            size_t left = UHashTool::BKDRHash(leftline.data(),leftline.length());
            size_t right= UHashTool::BKDRHash(rightline.data(),rightline.length());
            if(left != right)
                equal=false;
        }
        else if(!leftline.isEmpty() || !rightline.isEmpty())
        {
            equal=false;
        }

        sDiffInfo info;
        info.m_isEqual = equal;
        info.m_leftLineCount = leftline.count();
        info.m_rightLineCount = rightline.count();
        info.m_lineNumber = lineNumber;
        lineNumber++;

        diffInfo.append(info);

        if(leftFile.atEnd() && rightFile.atEnd())
            break;
    }

    leftFile.close();
    rightFile.close();


    WDiffInfoEvent event(WBaseEvent::TYPE_COMPARE_FILE_OVER,diffInfo);
    PTR_EVENT_CTL->postEvent(WBaseEvent::TYPE_COMPARE_FILE_OVER,&event);
}
