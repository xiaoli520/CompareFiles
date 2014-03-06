#ifndef WSTACKEDWIDGET_H
#define WSTACKEDWIDGET_H

#include <QWidget>
#include <QList>
#include "WidgetsPlugin_global.h"

class QHBoxLayout;

class WIDGETSPLUGINSHARED_EXPORT WStackedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WStackedWidget(QWidget *parent = 0);
    void addWidget(QWidget *w);
    void removeWidget(QWidget *w);
    void setCurrentWidget(QWidget *w);
    void setCurrentIndex(int index);
    QWidget *currentWidget()const;
    int currentIndex();



private:
    QList<QWidget*> stackedWidgets;
    QWidget *currWidget;
    QHBoxLayout *layout;
};

#endif // WSTACKEDWIDGET_H
