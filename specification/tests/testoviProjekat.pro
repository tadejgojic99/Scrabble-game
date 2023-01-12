QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    board.cpp \
    card.cpp \
    constants.cpp \
    custombutton_box.cpp \
    custombutton_card.cpp \
    deck.cpp \
    dictionary.cpp \
    player.cpp \
    prefixtree.cpp \
    test_scrabble.cpp

HEADERS += \
    board.h \
    card.h \
    catch.hpp \
    constants.h \
    custombutton_box.h \
    custombutton_card.h \
    deck.h \
    dictionary.h \
    player.h \
    prefixtree.h

DISTFILES += \
    dictionary.txt
