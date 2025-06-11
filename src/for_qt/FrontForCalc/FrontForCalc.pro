QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../core/s21_calculator.c \
    ../../core/s21_cred_calc.c \
    ../../core/s21_instruments.c \
    ../../core/s21_stack.c \
    ../../s21_main.c \
    creditcalc.cpp \
    depositcalc.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    settingsgraph.cpp

HEADERS += \
    ../../core/s21_backend.h \
    ../../core/s21_cred_calc.h \
    ../../core/s21_stack.h \
    ../../s21_main.h \
    creditcalc.h \
    depositcalc.h \
    graph.h \
    mainwindow.h \
    qcustomplot.h \
    settingsgraph.h

FORMS += \
    creditcalc.ui \
    depositcalc.ui \
    graph.ui \
    mainwindow.ui \
    settingsgraph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
