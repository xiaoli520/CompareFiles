#include <QLineEdit>
#include<QPushButton>
#include <QHBoxLayout>
#include "widgettest.h"

WidgetTest::WidgetTest(QWidget *parent) :
    QWidget(parent)
{
    edit = new QLineEdit;
    button = new QPushButton(tr("Find"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(edit);
    layout->addWidget(button);
    setLayout(layout);
}

