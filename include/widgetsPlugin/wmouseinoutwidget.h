#ifndef WMOUSEINOUTWIDGET_H
#define WMOUSEINOUTWIDGET_H
#include "WidgetsPlugin_global.h"

#include <QWidget>

class WIDGETSPLUGINSHARED_EXPORT WMouseInOutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WMouseInOutWidget(QWidget *parent = 0);
    ~WMouseInOutWidget();

    //isCenter 是否居中显示
    void setChildWidget(QWidget* childWidget,bool isCenter=false);

    void startShowAutoHide(int time=0);

    void setIsAutoHide(bool autoHide);

    //time == 0  立即隐藏 默认3秒
    void setHideTime(int time);

	//设置遇到滚动条自动偏移
	void setAutoScrollOffset(bool isAuto,int offsetWidth=30);

    virtual void leaveEvent(QEvent * pevent);

    virtual void enterEvent(QEvent * pevent);

    virtual void timerEvent(QTimerEvent * pevent);

    virtual void resizeEvent(QResizeEvent *pevent);
signals:
    void mouseInWidget();
    void mouseOutWidget();

private:
   QWidget* m_childWidget;
   int      m_timeId;
   int      m_timeout;
   bool     m_isAudoHide;
   bool     m_isFilterEvent;
   bool     m_isAutoScrollOffset;
   int      m_scrollOffsetWidth;
   QRect    m_oldRect;
};

#endif // WMOUSEINOUTWIDGET_H
