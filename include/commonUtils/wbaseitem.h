#ifndef WBASEITEM_H
#define WBASEITEM_H

#include "WBaseWidget.h"

class WBaseItem : public WBaseWidget
{
	Q_OBJECT

public:
	WBaseItem(QWidget *parent = 0);

	virtual ~WBaseItem();

    //�Զ�������϶��¼�
    void mousePressEvent(QMouseEvent* pMouseEvent);

    //�������¼�
    void enterEvent(QEvent *);

    //����뿪�¼�
    void leaveEvent(QEvent *);

protected:
    //����widget��С
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
