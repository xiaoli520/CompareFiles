#-------------------------------------------------
#
# Project created by QtCreator 2014-03-06T22:27:04
#
#-------------------------------------------------
win32:CONFIG(release, debug|release){
TARGET = CompareFiles
}else:win32:CONFIG(debug, debug|release){
TARGET = CompareFilesd
}

QT       += core gui widgets
DESTDIR = $$PWD/../bin/CompareFiles/

TEMPLATE = app

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/../include/widgetsPlugin
INCLUDEPATH += $$PWD/../include/commonUtils

LIBS += -L$$PWD/../lib/widgetsPlugin/
LIBS += -L$$PWD/../lib/commonUtils/
win32:CONFIG(release, debug|release) {
    LIBS += -lWidgetsPlugin
    LIBS += -lCommonUtils
}
else:win32:CONFIG(debug, debug|release) {
    LIBS += -lWidgetsPlugind
    LIBS += -lCommonUtilsd
}
else:unix{

}

SOURCES += main.cpp\
        mainwindow.cpp \
        wmidwidget.cpp \
        wtopwidget.cpp \
        wappcomm.cpp \
    wnavigationbar.cpp


HEADERS  += mainwindow.h \
            wmidwidget.h \
            wtopwidget.h \
            wappcomm.h \
            singleton.h \
    wnavigationbar.h


FORMS    += mainwindow.ui \
            wmidwidget.ui \
            wtopwidget.ui \
    wnavigationbar.ui


RC_FILE += \
    comparefiles.rc

