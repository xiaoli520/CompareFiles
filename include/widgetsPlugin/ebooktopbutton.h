#ifndef EBOOKTOPBUTTON_H
#define EBOOKTOPBUTTON_H

#include <QPushButton>

class EBookTopButton : public QPushButton
{
    Q_OBJECT

public:
    EBookTopButton(QWidget *parent = 0);
    ~EBookTopButton();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:
    void enterEBookTopButton();
    void leaveEBookTopButton();

};

#endif // EBOOKTOPBUTTON_H
