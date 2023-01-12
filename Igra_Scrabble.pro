QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/board.cpp \
    sources/playersnumber_dialog.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/card.cpp \
    sources/deck.cpp \
    sources/player.cpp \
    sources/wildcard_dialog.cpp \
    sources/constants.cpp \
    sources/game.cpp \
    sources/dictionary.cpp \
    sources/prefixtree.cpp \
    sources/custombutton_card.cpp \
    sources/custombutton_box.cpp

HEADERS += \
    headers/board.h \
    headers/mainwindow.h \
    headers/playersnumber_dialog.h \
    headers/card.h \
    headers/deck.h \
    headers/player.h \
    headers/wildcard_dialog.h \
    headers/constants.h \
    headers/game.h \
    headers/dictionary.h \
    headers/prefixtree.h \
    headers/custombutton_card.h \
    headers/custombutton_box.h

FORMS += \
    forms/mainwindow.ui \
    forms/playersnumber_dialog.ui \
    forms/wildcard_dialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/images/icon.png \
    resources/images/icon2.png \
    resources/images/F4F1DE.png \
    resources/images/2B3953.png \
    resources/images/6880AF.png \
    resources/images/doubleLetterScore.jpg \
    resources/images/doubleWordScore.jpg \
    resources/images/joker.jpg \
    resources/images/slova/A.jpg \
    resources/images/slova/B.jpg \
    resources/images/slova/C.jpg \
    resources/images/slova/D.jpg \
    resources/images/slova/E.jpg \
    resources/images/slova/F.jpg \
    resources/images/slova/G.jpg \
    resources/images/slova/H.jpg \
    resources/images/slova/I.jpg \
    resources/images/slova/J.jpg \
    resources/images/slova/K.jpg \
    resources/images/slova/L.jpg \
    resources/images/slova/M.jpg \
    resources/images/slova/N.jpg \
    resources/images/slova/O.jpg \
    resources/images/slova/P.jpg \
    resources/images/slova/Q.jpg \
    resources/images/slova/R.jpg \
    resources/images/slova/S.jpg \
    resources/images/slova/T.jpg \
    resources/images/slova/U.jpg \
    resources/images/slova/V.jpg \
    resources/images/slova/W.jpg \
    resources/images/slova/X.jpg \
    resources/images/slova/Y.jpg \
    resources/images/slova/Z.jpg \
    resources/images/tripleLetterScore.jpg \
    resources/images/tripleWordScore.jpg \
    resources/images/white.jpeg \
    resources/images/yellow.jpeg \
    resources/images/center.jpg \
#    resources/dictionary/dictionary/txt

DISTFILES += \
    resources/dictionary/dictionary.txt
