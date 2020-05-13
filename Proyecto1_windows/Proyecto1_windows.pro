TEMPLATE = app
QT -= gui
CONFIG += console c++11
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        singleton.cpp\
        garbagecollector.cpp \
        main.cpp \
        puntero.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    singleton.hpp\
    Lista.hpp \
    Nodo.hpp \
    VSPtr.hpp \
    garbagecollector.hpp \
    puntero.hpp

