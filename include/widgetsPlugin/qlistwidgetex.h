#ifndef QLISTWIDGETEX_H
#define QLISTWIDGETEX_H

#include <QListWidget>

namespace Ui {
class QListWidgetEx;
}

class QListWidgetEx : public QListWidget
{
	Q_OBJECT

public:
	QListWidgetEx(QWidget *parent = 0);
	~QListWidgetEx();

private:
    Ui::QListWidgetEx* ui;
};

#endif // QLISTWIDGETEX_H
