#-------------------------------------------------
#
# Project created by QtCreator 2014-03-06T22:42:37
#
#-------------------------------------------------
win32:CONFIG(release, debug|release){
TARGET = WidgetsPlugin
}else:win32:CONFIG(debug, debug|release){
TARGET = WidgetsPlugind
}

QT       += widgets

TEMPLATE = lib

INCLUDEPATH+=$$PWD

DEFINES += WIDGETSPLUGIN_LIBRARY

SOURCES += \
    wbaseqsswidget.cpp \
    wbaseqssdialog.cpp

HEADERS +=\
    widgetsPlugin_global.h \
    wbaseqsswidget.h \
    wbaseqssdialog.h \
    widgetExtentFun.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


win32{
    COPY = xcopy /D/Y
    MKDIR = mkdir
}else{
    COPY = cp -f
    MKDIR = mkdir -p
}

win32:CONFIG(release, debug|release){
    QMAKE_POST_LINK += "$$COPY \"$$PWD\\*.h\" \"$$PWD\\..\\include\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.lib\" \"$$PWD\\..\\lib\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.dll\" \"$$PWD\\..\\lib\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.dll\" \"$$PWD\\..\\bin\\CompareFiles\" &"
}else:win32:CONFIG(debug, debug|release){
    QMAKE_POST_LINK += "$$COPY \"$$PWD\\*.h\" \"$$PWD\\..\\include\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.lib\" \"$$PWD\\..\\lib\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.dll\" \"$$PWD\\..\\lib\\widgetsPlugin\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.dll\" \"$$PWD\\..\\bin\\CompareFiles\" &"
}else:unix{

}

