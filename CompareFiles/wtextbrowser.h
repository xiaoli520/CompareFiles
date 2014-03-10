#ifndef WTEXTBROWSER_H
#define WTEXTBROWSER_H

#include <QScrollBar>
#include <QTextBrowser>

/**
 * @brief The WTextBrowser class 文本浏览
 */
class WTextBrowser: public QTextBrowser
{
    Q_OBJECT
public:
  WTextBrowser(QScrollBar* scrollBar, QWidget* parent= 0 );
   ~WTextBrowser();

  /**
   * @brief readFile  读取文件
   * @param filename
   * @return
   */
  bool readFile(QString filename);

  void initScrollBar();

private slots:
   void setScrollRange(int min, int max);
   void setScrollValue(int value);
private:
  QScrollBar* m_scrollBar;
  QString     m_fileName;
};

#endif // WTEXTBROWSER_H
