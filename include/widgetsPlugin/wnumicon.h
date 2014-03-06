#ifndef WNUMICON_H
#define WNUMICON_H

#include "WidgetsPlugin_global.h"
#include "QWidget"
#include <QRect>
#include <QPixmap>
class QPushButton;

class WIDGETSPLUGINSHARED_EXPORT WNumIcon : public QWidget
{
    Q_OBJECT
public:
    explicit WNumIcon(const QString &image = "", int number = 0, QWidget *parent = 0);
    void setBackgroudImage(const QString &image);

    void draw(QPainter *painter, const QRect &rect);
    void paintEvent(QPaintEvent *);
    int getIconNum(){return num;}
    void setValue(int value){isHide = value;}

public slots:
    void setNumber(int number);
    int number()const {return num;}
    
private:
    int num;
    QPixmap pixmap;
    int isHide;
};

class WIDGETSPLUGINSHARED_EXPORT WNumButton :public QWidget
{
    Q_OBJECT
public:
    explicit WNumButton(QWidget *parent = 0);
    void setNumber(int num);

private:
    QPushButton *numBtn;
};

#endif // WNUMICON_H
