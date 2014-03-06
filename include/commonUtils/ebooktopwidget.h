#ifndef EBOOKTOPWIDGET_H
#define EBOOKTOPWIDGET_H

#include <QWidget>
#include "wbaseqsswidget.h"

class EBookTopWidget : public WBaseQssWidget
{
    Q_OBJECT
public:
    EBookTopWidget(WBaseQssWidget *parent = 0);
    ~EBookTopWidget();
//    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    
signals:
//    void enterEBookTopWidget();
    void leaveEBookTopWidget();

public slots:
    
};

#endif // EBOOKTOPWIDGET_H
