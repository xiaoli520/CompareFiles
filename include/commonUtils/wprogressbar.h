#ifndef WPROGRESSBAR_H
#define WPROGRESSBAR_H

#include <QProgressBar>
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT WProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit WProgressBar(QWidget *parent = 0);

    WIDGET_EXTENT_FUN_DECLARE
};

#endif // WPROGRESSBAR_H
