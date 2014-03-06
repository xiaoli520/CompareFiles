#ifndef WNAVIGATIONBAR_H
#define WNAVIGATIONBAR_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include "WidgetsPlugin_global.h"

//class QHBoxLayout;

class WNavigationButton :public QToolButton
{
    Q_OBJECT
public:
    enum ButtonStyle
    {
        IconOnly,
        IconBackground,
        TextBackground
    };

public:
    WNavigationButton(QWidget *parent = 0, int eventId = 0, const QString &text = "", const QString &icon = "",
                      const QString &iconClicked = "", const QString &background = "", ButtonStyle style = IconOnly);

    void setEventId(int eventId);
    int eventId() const;

private:
    int _eventId;
    QString _text;
    QString _icon;
    QString _iconClicked;
    QString _background;
    ButtonStyle _style;
};

class WNavigationSeparator :public QWidget
{
    Q_OBJECT
public:
    WNavigationSeparator(QWidget *parent = 0);
    QSize sizeHint() const;
    void paintEvent(QPaintEvent *);
};

class WIDGETSPLUGINSHARED_EXPORT WNavigationBar : public QWidget
{
    Q_OBJECT
public:
    explicit WNavigationBar(QWidget *parent = 0);

    void addButton(int eventId = 0, const QString &text = "", const QString &icon = "", const QString &iconClicked = "",
                   const QString &background = "", WNavigationButton::ButtonStyle style = WNavigationButton::IconOnly);
    void addSpaceing(int size);
    void addStretch(int stretch = 0);
    void addSeparator();
    QSize sizeHint() const;
    void paintEvent(QPaintEvent *);


signals:
    void triggerEvent(int eventId);
    
private slots:
    void subButtonClicked();

private:
    QHBoxLayout *_horizontalLayout;
};



#endif // WNAVIGATIONBAR_H
