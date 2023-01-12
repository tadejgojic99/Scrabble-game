#include "headers/mainwindow.h"
#include "headers/playersnumber_dialog.h"
#include "headers/game.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/resources/images/icon2.png"));
    playersNumber_Dialog d;
    MainWindow w;
    Game g;

    QObject::connect(&d, SIGNAL(sendNumberOfPlayers(int)), &g, SLOT(receiveNumberOfPlayers(int)));
    QObject::connect(&g, SIGNAL(createBoard(Board)),
                     &w, SLOT(createBoard(Board)));

    QObject::connect(&g, SIGNAL(sendBoard(Board)),
                     &w, SLOT(receiveBoard(Board)));
    QObject::connect(&g, SIGNAL(sendPlayer(Player)),
                     &w, SLOT(receivePlayer(Player)));

    QObject::connect(&w, SIGNAL(sendRepeatTurn()),
                     &g, SLOT(receiveRepeatTurn()));
    QObject::connect(&w, SIGNAL(sendRepeatFirstTurn()),
                     &g, SLOT(receiveRepeatFirstTurn()));

    QObject::connect(&w, SIGNAL(sendEndTurn(Board)),
                     &g, SLOT(receiveEndTurn(Board)));
    QObject::connect(&g, SIGNAL(sendEnd(Player)),
                     &w, SLOT(receiveEnd(Player)));
    QObject::connect(&w, SIGNAL(sendRequestSuggestion()),
                     &g, SLOT(receiveRequestSuggestion()));
    QObject::connect(&w, SIGNAL(sendUpdate(Board,std::string)),
                     &g, SLOT(receiveUpdate(Board,std::string)));

    d.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);    // skriva nam opciju da menjamo menjamo/iskljucimo prozor(ideja je da se na mainwindow prelazi nakon odabira broja igraca)
    d.exec();

    g.start();
    w.show();

    return a.exec();

}
