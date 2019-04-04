TEMPLATE = app
#CONFIG += console c++11
CONFIG += c++11
CONFIG -= console
CONFIG -= app_bundle
CONFIG += qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

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
    model.cpp \
    MyLinearAlgebra.cpp \
    sundial.cpp \
    spaceformule.cpp \
    gnomon.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    earthrotation.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    model.h \
    MyLinearAlgebra.h \
    sundial.h \
    spaceformule.h \
    gnomon.h \
    mainwindow.h \
    qcustomplot.h \
    earthrotation.h

FORMS += \
    mainwindow.ui
