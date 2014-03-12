#ifndef WIDGETEXTENTFUN_H
#define WIDGETEXTENTFUN_H

#include <QFile>

#define WIDGET_EXTENT_FUN_DECLARE \
    public: \
        void loadStyleSheetFromFile(const QString&);


#define WIDGET_EXTENT_FUN_IMPLEMENT(WIDGET) \
    void WIDGET::loadStyleSheetFromFile(const QString &filePath) \
    { \
        QFile file(filePath); \
        file.open(QFile::ReadOnly); \
        setStyleSheet(file.readAll()); \
        file.close();                  \
    }

#endif // WIDGETEXTENTFUN_H
