QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canpa.cpp \
    cfabricante.cpp \
    chospital.cpp \
    cmedico.cpp \
    cnoquirurgicas.cpp \
    cortopedia.cpp \
    cpaciente.cpp \
    cpersona.cpp \
    cprotesis.cpp \
    cquirurgicas.cpp \
    cregistrosanpa.cpp \
    main.cpp

HEADERS += \
    canpa.h \
    cfabricante.h \
    chospital.h \
    cmedico.h \
    cnoquirurgicas.h \
    cortopedia.h \
    cpaciente.h \
    cpersona.h \
    cprotesis.h \
    cquirurgicas.h \
    cregistrosanpa.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
