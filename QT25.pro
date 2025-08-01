QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += model view controller lang

SOURCES += \
    view/admin.cpp \
    model/main.cpp \
    view/login.cpp

HEADERS += \
    view/admin.h \
    view/login.h

FORMS += \
    view/admin.ui \
    view/login.ui

TRANSLATIONS += \
    lang/QT25_ko_KR.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Server 8.0/include"
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/lib" -lmysqlclient
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
