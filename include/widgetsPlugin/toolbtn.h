#ifndef TOOLBTN_H
#define TOOLBTN_H

#include <QToolButton>
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT ToolBtn : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolBtn(QWidget *parent = 0);

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    
signals:
    void enterBtn(int posX, int posY);
    void leaveBtn();
    
    
};

#endif // TOOLBTN_H
