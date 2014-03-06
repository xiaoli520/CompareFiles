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

QT       += core gui
DESTDIR = $$PWD/../bin/CompareFiles/
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app


LIBS += -L$$PWD/../lib/widgetsPlugin/
LIBS += -L$$PWD/../lib/mprdevice/
LIBS += -L$$PWD/../lib/mprplayer/ -llibMPRPlayer
LIBS += -L$$PWD/../lib/libMPRLicense/ -llicParser
LIBS += -L$$PWD/../lib/libzip/ -lzip
LIBS += -L$$PWD/../lib/libSymmCrypt/ -lsymm_crypt -llibsm4_s
LIBS += -L$$PWD/../lib/libMPRMimeDataFetcher/ -lMPRMimeDataFetcher
LIBS += -L$$PWD/../lib/fileOperator/
LIBS += -L$$PWD/../lib/qtSingleApplication/
LIBS += -L$$PWD/../lib/common_utilities/
LIBS += -lAdvapi32 -lUser32 -lShell32
win32:CONFIG(release, debug|release) {
    LIBS += -lWidgetsPlugin
    LIBS += -lMPRDeviceAPI_VS2010_MD
    LIBS += -lQtSingleApplication
    LIBS += -lcommon_utilities
    LIBS += -lfileOperator
}
else:win32:CONFIG(debug, debug|release) {
    LIBS += -lWidgetsPlugind
    LIBS += -lMPRDeviceAPI_VS2010_MDD
    LIBS += -lQtSingleApplicationd
    LIBS += -lcommon_utilitiesd
    LIBS += -lfileOperatord
}
else:unix{
    LIBS += -L$$OUT_PWD/../WidgetsPlugin/ -lWidgetsPlugin
}

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
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



