#include "wnavigationbar.h"
#include "ui_wnavigationbar.h"
#include "wappcomm.h"
#include <qfiledialog.h>
#include "weventcontroller.h"
#include <QDebug>

WNavigationBar::WNavigationBar(QWidget *parent) :
    WBaseQssWidget(parent),
    ui(new Ui::WNavigationBar)
{
    ui->setupUi(this);
    QString qss=PTR_WAPP_COMM->getQssFilePath("wnavigationbar.qss");
    loadStyleSheetFromFile(qss);
    this->layout()->setContentsMargins(0,0,0,0);
}

WNavigationBar::~WNavigationBar()
{
    delete ui;
}

void WNavigationBar::on_leftFileBtn_clicked()
{
    emit setAutoHide(false);
    QString filename=QFileDialog::getOpenFileName(this);
    ui->lefitLineEdit->setText(filename);
    if(ui->lefitLineEdit->text().isEmpty() && ui->rightLineEdit->text().isEmpty() ||
            !ui->lefitLineEdit->text().isEmpty() && !ui->rightLineEdit->text().isEmpty())
    {
        emit setAutoHide(true);
    }
    qDebug()<<__FUNCTION__<<"left file name="<<filename;
    QMap<QString,QVariant> data;
    data["filename"]=QVariant(filename);
    PTR_EVENT_CTL->postEvent(WBaseEvent::TYPE_OPEN_LEFT_FILE,data);
}

void WNavigationBar::on_rightFileBtn_clicked()
{
  emit setAutoHide(false);
  QString filename=QFileDialog::getOpenFileName(this);
  ui->rightLineEdit->setText(filename);
  qDebug()<<__FUNCTION__<<"right file name="<<filename;
  if(ui->lefitLineEdit->text().isEmpty() && ui->rightLineEdit->text().isEmpty() ||
          !ui->lefitLineEdit->text().isEmpty() && !ui->rightLineEdit->text().isEmpty())
  {
      emit setAutoHide(true);
  }

  QMap<QString,QVariant> data;
  data["filename"]=QVariant(filename);
  PTR_EVENT_CTL->postEvent(WBaseEvent::TYPE_OPEN_RIGHT_FILE,data);
}
