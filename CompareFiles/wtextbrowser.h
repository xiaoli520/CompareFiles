#ifndef WTEXTBROWSER_H
#define WTEXTBROWSER_H

#include <QScrollBar>
#include <QTextBrowser>
#include <QVector>
#include "defines.h"

class WTextBrowserNum;
/**
 * @brief The WTextBrowser class 文本浏览
 */
class WTextBrowser: public QTextBrowser
{
    Q_OBJECT
public:
  WTextBrowser(int type,QScrollBar* scrollBar, QWidget* parent= 0 );
   ~WTextBrowser();

  /**
   * @brief readFile  读取文件
   * @param filename
   * @return
   */
  bool readFile(QString filename);

  QString getFilePath(){ return m_fileName;}

  void initScrollBar();

  void customEvent(QEvent *event);

  void paintEvent(QPaintEvent *e);

private slots:
   void setScrollRange(int min, int max);
   void setScrollValue(int value);
private:
  QScrollBar* m_scrollBar;
  QString     m_fileName;
  WTextBrowserNum* m_textBrowserNum;
  int         m_type;
  QVector<sDiffInfo> m_difList;

  friend class WTextBrowserNum;
};

#endif // WTEXTBROWSER_H
