#include "weventcontroller.h"
#include <QMutexLocker>
#include <QApplication>
#include "wdiffinfoevent.h"
#include <QEvent>

WEventController::WEventController()
{
}

WEventController::~WEventController()
{
    QMutexLocker locker( &m_mutex );
    m_eventRegister.clear();
}


/**
 * @brief installListenEvent 注册监听事件
 * @param obj   对象
 * @param eventId 事件ID
 * @return
 */
bool WEventController::installListenEvent(QObject* obj,int eventId)
{
    QMutexLocker locker(&m_mutex);
    bool ret = true;
    if( exists(obj, eventId ) ) {
       ret = false;
    }
    else {
       EventsRegister::iterator it = m_eventRegister.find(eventId);
       if( it != m_eventRegister.end() ) {
          ret = it->second.insert(obj).second;
       }
    }
    return ret;
}

/**
 * @brief removeListenEvent 移除监听事件
 * @param obj
 * @return
 */
void WEventController::removeListenEvent(QObject* obj)
{
    QMutexLocker locker(&m_mutex);
    if( !m_eventRegister.empty() ) {
       EventsRegister::iterator it = m_eventRegister.begin();
       const EventsRegister::iterator end = m_eventRegister.end();
       while( it != end ) {
          it->second.erase( obj );
          ++it;
       }
    }
}

/**
 * @brief postEvent 以POST 方式投递事件
 * @param eventId
 */
void WEventController::postEvent(int eventId)
{
    QMutexLocker locker(&m_mutex);
    const EventsRegister::const_iterator rit = m_eventRegister.find(eventId);
    if( rit != m_eventRegister.end()) {
       Objects::const_iterator it = rit->second.begin();
       const Objects::const_iterator end = rit->second.end();
       while( it != end ) {
           QApplication::postEvent( *it, new WBaseEvent(eventId));
          ++it;
       }
    }
}

 void WEventController::postEvent(int eventId,QEvent* pevent)
 {
     QMutexLocker locker(&m_mutex);
     const EventsRegister::const_iterator rit = m_eventRegister.find(eventId);
     if( rit != m_eventRegister.end()) {
        Objects::const_iterator it = rit->second.begin();
        const Objects::const_iterator end = rit->second.end();
        while( it != end ) {
            if(pevent->type() > QEvent::User)
            {
                if(pevent->type() == WBaseEvent::TYPE_COMPARE_FILE_OVER)
                {
                    WDiffInfoEvent* temp=(WDiffInfoEvent*)pevent;
                    WDiffInfoEvent* postEvent= new WDiffInfoEvent(WBaseEvent::TYPE_COMPARE_FILE_OVER,temp->getDiffDataList());
                    QApplication::postEvent( *it,postEvent);
                }
                else
                {
                    WBaseEvent* temp= (WDiffInfoEvent*)pevent;
                    WBaseEvent* postEvent= new WBaseEvent(temp->type(),temp->getMapData());
                    QApplication::postEvent( *it,postEvent);
                }
            }
           ++it;
        }
     }
 }

void WEventController::postEvent(int eventId,QMap<QString,QVariant> data)
{
    QMutexLocker locker(&m_mutex);
    const EventsRegister::const_iterator rit = m_eventRegister.find(eventId);
    if( rit != m_eventRegister.end()) {
       Objects::const_iterator it = rit->second.begin();
       const Objects::const_iterator end = rit->second.end();
       while( it != end ) {
           QApplication::postEvent( *it, new WBaseEvent(eventId,data));
          ++it;
       }
    }
}

/**
 * @brief sendEvent 以SEND 方式投递事件
 * @param eventId
 */
void WEventController::sendEvent(int eventId)
{
    QMutexLocker locker(&m_mutex);
    const EventsRegister::const_iterator rit = m_eventRegister.find(eventId);
    if( rit != m_eventRegister.end()) {
       Objects::const_iterator it = rit->second.begin();
       const Objects::const_iterator end = rit->second.end();
       while( it != end ) {
           QApplication::sendEvent( *it, new WBaseEvent(eventId));
          ++it;
       }
    }
}

void WEventController::sendEvent(int eventId,QMap<QString,QVariant> data)
{
    QMutexLocker locker(&m_mutex);
    const EventsRegister::const_iterator rit = m_eventRegister.find(eventId);
    if( rit != m_eventRegister.end()) {
       Objects::const_iterator it = rit->second.begin();
       const Objects::const_iterator end = rit->second.end();
       while( it != end ) {
           QApplication::sendEvent( *it, new WBaseEvent(eventId,data));
          ++it;
       }
    }
}

/**
* @brief exists  是否已经存在
* @param obj
* @param eventId
* @return
*/
bool WEventController::exists( QObject* obj, int eventId)
{
    bool ret = false;

    const EventsRegister::const_iterator it = m_eventRegister.find(eventId);
    if(it != m_eventRegister.end())
    {
       if( it->second.find(obj) != it->second.end() ) {
          ret = true;
       }
    }
    else
    {
       m_eventRegister.insert(EventsRegister::value_type(eventId, Objects()));
    }
    return ret;
}
