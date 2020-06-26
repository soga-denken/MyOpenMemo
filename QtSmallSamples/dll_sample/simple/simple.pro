# qmakeに関する日本語の情報
# http://cdn2.hubspot.net/hubfs/149513/Japan/2015_Japan_Summit_Presentations/QtJS15_qmake_Intro_JQUG.pdf

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# Qt Creatorに実行ボタンが表示されない場合は次の2行が必要っぽい？
TARGET = simple
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# pathを定義する
# x86,x64を分けて定義する。

win32 {

    ## 32/64bitで共通となるbuild設定
    INCLUDEPATH += $$PWD/../myDialog
    DEPENDPATH += $$PWD/../myDialog

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../myDialog/release/ -lmyDialog
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../myDialog/debug/ -lmyDialog

    # releaseにおけるqDebugの出力の抑制
    CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

    !contains(QMAKE_TARGET.arch, x86_64) {
        message("x86 build")

        ## Windows x86 (32bit)固有設定

    } else {
        message("x86_64 build")

        ## Windows x64 (64bit)固有設定

    }
}





# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
