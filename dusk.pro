TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    gamebgnd.cpp \
    level.cpp \
    player.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    gamebgnd.h \
    level.h \
    player.h

OTHER_FILES += \
    1.llv
