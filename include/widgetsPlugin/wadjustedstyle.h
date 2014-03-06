#ifndef WADJUSTEDSTYLE_H
#define WADJUSTEDSTYLE_H

#include <QProxyStyle>
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT WAdjustedStyle : public QProxyStyle
{
    Q_OBJECT
public:
    WAdjustedStyle(QStyle *style = 0);
    WAdjustedStyle(const QString &key);

    void drawControl(ControlElement element,
                     const QStyleOption * option,
                     QPainter * painter,
                     const QWidget * widget = 0)const;

    void drawPrimitive(PrimitiveElement element,
                       const QStyleOption * option,
                       QPainter * painter,
                       const QWidget * widget = 0)const;
};

#endif // WADJUSTEDSTYLE_H
