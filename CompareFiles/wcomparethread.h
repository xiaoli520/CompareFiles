#ifndef WCOMPARETHREAD_H
#define WCOMPARETHREAD_H

#include <QThread>


class WCompareThread : public QThread
{
    Q_OBJECT
public:
    explicit WCompareThread(QObject *parent = 0);
    void setFileName(QString leftFile,QString rightFile);

protected:
    virtual void run();
signals:

public slots:

private:
    QString m_leftFileName;
    QString m_rightFileName;


};

#endif // WCOMPARETHREAD_H
