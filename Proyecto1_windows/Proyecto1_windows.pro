TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        garbagecollector.cpp \
        main.cpp \
        singleton.cpp

HEADERS += \
    Lista.hpp \
    Nodo.hpp \
    VSPtr.hpp \
    garbagecollector.hpp \
    singleton.hpp
