#ifndef WDIFFINFOEVENT_H
#define WDIFFINFOEVENT_H
#include "wbaseevent.h"
#include "defines.h"
#include <QVector>
class WDiffInfoEvent:public WBaseEvent
{
public:
    explicit  WDiffInfoEvent( const  int  eventId ,QVector<sDiffInfo>& diff)
    : WBaseEvent( static_cast<QEvent::Type>( eventId ) )
    {
        m_diffDataList=diff;
    }



    QVector<sDiffInfo> getDiffDataList(){ return m_diffDataList;}
private:
    QVector<sDiffInfo> m_diffDataList;
};

#endif // WDIFFINFOEVENT_H
