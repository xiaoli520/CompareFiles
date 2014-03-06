#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = 0);   
    ~LineEdit();
    void setLineEditText(QString string);
signals:
    void leaveOutEvent();

protected:
    void focusOutEvent(QFocusEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QString memoryText;
};

#endif // LINEEDIT_H
