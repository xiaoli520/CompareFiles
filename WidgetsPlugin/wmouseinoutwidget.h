#ifndef WMOUSEINOUTWIDGET_H
#define WMOUSEINOUTWIDGET_H
#include "WidgetsPlugin_global.h"

#include <QWidget>
/**
 * @brief The WMouseInOutWidget class 鼠标移动自动消失控件
 */

class WIDGETSPLUGINSHARED_EXPORT WMouseInOutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WMouseInOutWidget(QWidget *parent = 0);
    ~WMouseInOutWidget();

	void setAutoScrollOffset(bool isAuto,int offsetWidth=30);

    virtual void leaveEvent(QEvent * pevent);

    virtual void enterEvent(QEvent * pevent);

    virtual void timerEvent(QTimerEvent * pevent);

    virtual void resizeEvent(QResizeEvent *pevent);

public slots:

    /**
     * @brief setChildWidget 设置控件是否居中显示
     * @param childWidget
     * @param isCenter
     */
    void setChildWidget(QWidget* childWidget,bool isCenter=false);

    /**
     * @brief startShowAutoHide 设置自动显示时间
     * @param time
     */
    void startShowAutoHide(int time=0);

    /**
     * @brief setIsAutoHide 设置是否自动隐藏
     * @param autoHide
     */
    void setIsAutoHide(bool autoHide);

    /**
     * @brief setHideTime 设置自动隐藏时间
     * @param time
     */
    void setHideTime(int time);

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
