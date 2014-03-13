#ifndef WEVENTCONTROLLER_H
#define WEVENTCONTROLLER_H
#include <QObject>
#include <map>
#include <QMutex>
#include <set>
#include "singleton.h"
#include "wbaseevent.h"

/**
 * @brief The WEventController class 事件投递控制类
 */
class WEventController
{
public:
    /**
     * @brief installListenEvent 注册监听事件
     * @param obj   对象
     * @param eventId 事件ID
     * @return
     */
    bool installListenEvent(QObject* obj,int eventId);

    /**
     * @brief removeListenEvent 移除监听事件
     * @param obj
     * @return
     */
    void removeListenEvent(QObject* obj);

    /**
     * @brief postEvent 以POST 方式投递事件
     * @param eventId
     */
    void postEvent(int eventId);
    void postEvent(int eventId,QMap<QString,QVariant> data);

    /**
     * @brief postEvent
     * @param eventId
     * @param obj  此参数若是new出来的需自己释放
     */
    void postEvent(int eventId,QEvent* obj);


    /**
     * @brief sendEvent 以SEND 方式投递事件
     * @param eventId
     */
    void sendEvent(int eventId);
    void sendEvent(int eventId,QMap<QString,QVariant> data);


    WEventController();
    ~WEventController();
private:

    /**
    * @brief exists  是否已经存在
    * @param obj
    * @param eventId
    * @return
    */
   bool exists( QObject* obj, int eventId);

private:
   typedef std::set<QObject*> Objects;
   typedef std::map<int, Objects> EventsRegister;

   EventsRegister m_eventRegister;
   QMutex         m_mutex;

};

#define PTR_EVENT_CTL Singleton<WEventController>::getInstance()

#endif // WEVENTCONTROLLER_H
