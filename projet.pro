QT       += core gui sql widgets printsupport network serialport charts
QT       += core network
INCLUDEPATH += C:\Users\ademb\OneDrive\Documents\Arduino\libraries\DHT_sensor_library

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arduino.cpp \
    chatdialog.cpp \
    connection.cpp \
    mailer.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp

HEADERS += \
    Arduino.h \
    chatdialog.h \
    connection.h \
    mailer.h \
    maintenance.h \
    mainwindow.h

FORMS += \
    chatdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    build/Logo.png \
    build/eyeOn.png.png \
    build/mail.png \
    build/userFace.png
