#ifndef WBASEEVENT_H
#define WBASEEVENT_H

#include <QEvent>
#include <QVariant>
#include <vector>

/**
 * @brief The WBaseEvent class 事件自定义基础类
 */
class WBaseEvent : public QEvent
{
public:
   enum {
      UNKNOWN = QEvent::User,
      TYPE_OPEN_LEFT_FILE,
      TYPE_OPEN_RIGHT_FILE
   };

public:

   explicit WBaseEvent( int const eventId )
   : QEvent( static_cast<QEvent::Type>( eventId ) )
   {

   }

   explicit WBaseEvent(const int eventId,const QMap<QString,QVariant> data)
   : QEvent( static_cast<QEvent::Type>( eventId ) )
   {
       m_data = data;
   }

   QVariant getData(QString key)
   {
       return m_data[key];
   }

private:
   QMap<QString,QVariant> m_data;
};

#endif // WBASEEVENT_H
