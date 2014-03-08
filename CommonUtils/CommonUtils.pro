#-------------------------------------------------
#
# Project created by QtCreator 2013-04-01T10:56:37
#
#-------------------------------------------------
win32:CONFIG(release, debug|release){
TARGET = CommonUtils
}else:win32:CONFIG(debug, debug|release){
TARGET = CommonUtilsd
}

QT       += core gui widgets

TEMPLATE = lib

INCLUDEPATH+=$$PWD

DEFINES += COMMONUTILS_LIBRARY

SOURCES += \
    widgettest.cpp

HEADERS +=\
        commonUtils_global.h \
        widgettest.h

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
    QMAKE_POST_LINK += "$$COPY \"$$PWD\\*.h\" \"$$PWD\\..\\include\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.lib\" \"$$PWD\\..\\lib\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.dll\" \"$$PWD\\..\\lib\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\release\\*.dll\" \"$$PWD\\..\\bin\\CompareFiles\" &"
}else:win32:CONFIG(debug, debug|release){
    QMAKE_POST_LINK += "$$COPY \"$$PWD\\*.h\" \"$$PWD\\..\\include\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.lib\" \"$$PWD\\..\\lib\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.dll\" \"$$PWD\\..\\lib\\commonUtils\\\" &"
    QMAKE_POST_LINK += "$$COPY \"$$OUT_PWD\\debug\\*.dll\" \"$$PWD\\..\\bin\\CompareFiles\" &"
}else:unix{

}

