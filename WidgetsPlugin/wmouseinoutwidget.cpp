#include "wmouseinoutwidget.h"
#include <QVBoxLayout>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QDebug>

WMouseInOutWidget::WMouseInOutWidget(QWidget *parent) :
    QWidget(parent)
{
   setAttribute(Qt::WA_TranslucentBackground, true);

   m_timeId=0;
   m_timeout = 3000;
   m_childWidget= NULL;
   m_isAudoHide=true;
   m_oldRect.setWidth(0);
   m_isAutoScrollOffset = false;
   m_scrollOffsetWidth = 0;

}

/**
 * @brief startShowAutoHide 设置自动显示时间
 * @param time
 */
void WMouseInOutWidget::startShowAutoHide(int time)
{
    if(!m_childWidget)
        return;

    m_childWidget->setVisible(true);
    if(time == 0)
        m_timeId = startTimer(m_timeout);
    else
        m_timeId = startTimer(time);

}

/**
 * @brief setIsAutoHide 设置是否自动隐藏
 * @param autoHide
 */
void WMouseInOutWidget::setIsAutoHide(bool autoHide)
{
    m_isAudoHide=autoHide;
    if(m_isAudoHide)
        m_timeId = startTimer(m_timeout);
    else
        m_childWidget->setVisible(true);
}

/**
 * @brief setChildWidget 设置控件是否居中显示
 * @param childWidget
 * @param isCenter
 */
void WMouseInOutWidget::setChildWidget(QWidget* childWidget,bool isCenter)
{
    m_childWidget = childWidget;
    QVBoxLayout* lay = new QVBoxLayout(this);
    if(!isCenter)
        lay->addWidget(m_childWidget);
    else
    {
        QHBoxLayout* hlay = new QHBoxLayout(this);
        hlay->addWidget(m_childWidget);
        hlay->setAlignment(hlay,Qt::AlignHCenter);
        lay->addLayout(hlay);
        lay->setAlignment(lay,Qt::AlignVCenter);
    }
    lay->setContentsMargins(0,0,0,0);
    setLayout(lay);
    m_childWidget->setVisible(false);
}

	

WMouseInOutWidget::~WMouseInOutWidget()
{

}

void WMouseInOutWidget::timerEvent(QTimerEvent * pevent)
{
    if(pevent->timerId() == m_timeId)
    {
        if(m_childWidget)
            m_childWidget->setVisible(false);
        killTimer(m_timeId);
        m_timeId=0;
        emit mouseOutWidget();
    }
}

void WMouseInOutWidget::setHideTime(int time)
{
    m_timeout = time;
}

void WMouseInOutWidget::leaveEvent(QEvent * pevent)
{
    Q_UNUSED(pevent);

    if(m_timeId != 0)
    {
        killTimer(m_timeId);
        m_timeId=0;

    }

    if(m_isAudoHide)
    {
        if(m_timeout == 0)
            m_childWidget->setVisible(false);
        else
        {
            m_timeId = startTimer(m_timeout);
            return;
        }
    }
}

//设置遇到滚动条自动偏移
void WMouseInOutWidget::setAutoScrollOffset(bool isAuto,int offsetWidth)
{
	m_isAutoScrollOffset=isAuto;
	m_scrollOffsetWidth=offsetWidth;
}
void WMouseInOutWidget::enterEvent(QEvent * pevent)
{
     Q_UNUSED(pevent);

	 if(m_isAutoScrollOffset)
	 {
		int mouse_x = QCursor::pos().x();//鼠标点击处横坐标
		int mouse_y = QCursor::pos().y();//鼠标点击处纵坐标
		QPoint temp=this->mapFromGlobal(QPoint(mouse_x,mouse_y));
		qDebug()<<__FUNCTION__<<"x="<<temp.x()<<"y="<<temp.y()<<"width="<<m_oldRect.width();
		if(m_oldRect.width()-temp.x() < m_scrollOffsetWidth)
		  {
			QRect tempRect=m_oldRect;
			tempRect.setWidth(m_oldRect.width()-m_scrollOffsetWidth);
			setGeometry(tempRect);
			 m_childWidget->setVisible(false);
			return;
		}

		if(rect().width()+ m_scrollOffsetWidth == m_oldRect.width())
			setGeometry(m_oldRect);
	 }

    if(m_childWidget)
        m_childWidget->setVisible(true);

    if(m_timeId != 0)
    {
        killTimer(m_timeId);
        m_timeId=0;
    }
    emit mouseInWidget();
}

void WMouseInOutWidget::resizeEvent(QResizeEvent *pevent)
{
	if(m_isAutoScrollOffset)
	{
		QSize size=pevent->size();
		if(m_oldRect.width()==0 || size.width() + m_scrollOffsetWidth != m_oldRect.width())
		{
			m_oldRect=rect();
			m_oldRect.setWidth(size.width());
		}
	}
}

/**
 * @brief setChildShow  设置子窗口是否显示
 * @param isshow
 */
void WMouseInOutWidget::setChildShow(bool isshow)
{
    if(m_timeId != 0)
    {
        killTimer(m_timeId);
        m_timeId=0;
    }

    m_childWidget->setVisible(isshow);
    if(m_isAudoHide && isshow)
        m_timeId = startTimer(m_timeout);

    if(isshow)
        emit mouseInWidget();
    else
        emit mouseOutWidget();

}
