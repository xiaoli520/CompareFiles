#ifndef WBASEITEM_H
#define WBASEITEM_H

#include "WBaseWidget.h"

class WBaseItem : public WBaseWidget
{
	Q_OBJECT

public:
	WBaseItem(QWidget *parent = 0);

	virtual ~WBaseItem();

    //自定义鼠标拖动事件
    void mousePressEvent(QMouseEvent* pMouseEvent);

    //鼠标进入事件
    void enterEvent(QEvent *);

    //鼠标离开事件
    void leaveEvent(QEvent *);

protected:
    //调整widget大小
   virtual void adjuestWidgetPos();

signals:
	void itemClicked(WBaseItem* item);

protected:
    QString leaveQssName;
    QString enterQssName;
    QLabel* selectLabel;
    int     selectLabelX;


};

#endif // WBASEITEM_H
