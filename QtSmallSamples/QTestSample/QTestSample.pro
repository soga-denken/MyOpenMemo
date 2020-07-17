QT += testlib

# guiは利用しない場合
QT -= gui

# depend_includepath: Appending the value of INCLUDEPATH to DEPENDPATH is enabled. Set by default.
# warn_on: The compiler should output as many warnings as possible. If warn_off is also specified, the last one takes effect.
# testcase: The target is an automated test. A check target will be added to the generated Makefile to run the test. Only relevant when generating Makefiles.
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_firsttest.cpp
