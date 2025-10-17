QT += widgets sql printsupport
CONFIG += c++17

TEMPLATE = app
TARGET = AirlineBooking

SOURCES += \
    src/main.cpp \
    src/database/DatabaseManager.cpp \
    src/models/Client.cpp \
    src/models/Vol.cpp \
    src/models/Reservation.cpp \
    src/dao/ClientDAO.cpp \
    src/dao/VolDAO.cpp \
    src/dao/ReservationDAO.cpp \
    src/ui/MainWindow.cpp \
    src/ui/LoginDialog.cpp \
    src/ui/ClientDialog.cpp \
    src/ui/VolDialog.cpp \
    src/ui/ReservationDialog.cpp \
    src/ui/TicketWidget.cpp

HEADERS += \
    src/database/DatabaseManager.h \
    src/models/Client.h \
    src/models/Vol.h \
    src/models/Reservation.h \
    src/dao/ClientDAO.h \
    src/dao/VolDAO.h \
    src/dao/ReservationDAO.h \
    src/ui/MainWindow.h \
    src/ui/LoginDialog.h \
    src/ui/ClientDialog.h \
    src/ui/VolDialog.h \
    src/ui/ReservationDialog.h \
    src/ui/TicketWidget.h

FORMS += \
    src/ui/MainWindow.ui \
    src/ui/LoginDialog.ui \
    src/ui/ClientDialog.ui \
    src/ui/VolDialog.ui \
    src/ui/ReservationDialog.ui \
    src/ui/TicketWidget.ui

RESOURCES += resources.qrc

# SQL script will be provided on request
# DISTFILES += sql/init.sql

INCLUDEPATH += src