#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/constants.h"
#include "headers/board.h"
#include "headers/custombutton_box.h"
#include "headers/custombutton_card.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       this->setGeometry(50,50,1100,750);

       QPixmap bkgnd(":/resources/images/2B3953.png");   // : referise na trenutni folder projekta
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);

       isFirstLetter = true;
       isFirstTurn = true;
       isHorizontal = true;
       previous_x = -1;
       previous_y = -1;

       ui->gridLayoutWidget->setGeometry(10,10,700,700);
       ui->verticalLayoutWidget->setGeometry(750,10,300,450);
       ui->board_gridLayout->setGeometry(QRect(750,10,300,450));

       w.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint); //sakrivamo traku

       // Povezuje SIGNAL i SLOT za dobijanje kartica iz Wildcard_Dialog
       QObject::connect(&w, SIGNAL(sendLetter(char)),
                        this, SLOT(receiveLetter(char)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveEnd(Player winningPlayer)
{
    QMessageBox msgBox;
    std::string msg = "";
    msg.append("The winner is ");
    msg.append(winningPlayer.getName());
    msg.append(" with a score of " );
    msg.push_back(winningPlayer.getScore());
    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();
    this->close();
}


void MainWindow::receiveLetter(char letter)
{
    wildcardLetter = letter;
}

void MainWindow::on_repeatTurn_pushButton_clicked()
{
    if (isFirstTurn) // ako je u pitanju prvi potez, pravi se nova tabla
    {
        QLayoutItem* item;
        while ((item = ui->board_gridLayout->takeAt(0)) != NULL )
        {
            delete item->widget();
            delete item;
        }

        sendRepeatFirstTurn();
    }
    else
    {
        sendRepeatTurn();
    }
}



void MainWindow::on_endTurn_pushButton_clicked()
{

    Constants *c = new Constants();
    Board tempBoard = Board();
    QVector<QVector<char>> letters_temp;
    for (int y = 0; y < c->LEN_Y; y++)
    {
        QVector<char> temp;
        for (int x = 0; x < c->LEN_X; x++)
        {
            CustomButton_Box *button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y,x)->widget());
            temp.push_back(button_box->getLetterValue());
            if (button_box->getIsNew())
                tempBoard.setNewLetterValue(true,x,y);

            if (button_box->getIsWildcard())
                tempBoard.setWildcard(true,x,y);

        }
        letters_temp.push_back(temp);
    }
    tempBoard.setLetters(letters_temp);
    isFirstTurn = false;

    if(tempBoard.isEmpty()){
        isFirstTurn=true;
        CustomButton_Box *btn_center = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(7,7)->widget());

        btn_center->setEnabled(true);

        QMessageBox msgBox;
        msgBox.setText("You are required to set atleast one card on the board; first card must be placed in the board center");
        msgBox.exec();

    }
    else
        sendEndTurn(tempBoard);
}



void MainWindow::on_suggestion_pushButton_clicked()

{
    sendRequestSuggestion();
}

bool MainWindow::getIsFirstLetter() const
{
    return isFirstLetter;
}

void MainWindow::setIsFirstLetter(bool value)
{
    isFirstLetter = value;
}

int MainWindow::getPrevious_x() const
{
    return previous_x;
}

void MainWindow::setPrevious_x(int value)
{
    previous_x = value;
}

int MainWindow::getPrevious_y() const
{
    return previous_y;
}

void MainWindow::setPrevious_y(int value)
{
    previous_y = value;
}



void MainWindow::receivePlayer(Player myPlayer)
{
    ui->nameLabel->setText(QString::fromStdString(myPlayer.getName()));
    std::string toSet = "Score: " + to_string(myPlayer.getScore());
    ui->scoreLabel->setText(QString::fromStdString(toSet));

    std::string cards = myPlayer.getHand();
    // resetujemo mrezu
    QLayoutItem* item;
    ui->hand_gridLayout->setSpacing(3);

    while ((item = ui->hand_gridLayout->takeAt(0)) != NULL)
    {
        // da ne bi doslo do curenja memorije
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < static_cast<int>(cards.length()); i++)
    {
        CustomButton_Card *button = new CustomButton_Card();
        button->setFixedSize(QSize(70, 80));
        button->setLetterValue(cards[i]);

        std::string image_path = "";
        // ako je dzoker
        if (cards[i] == '*')
            image_path = ":/resources/images/joker.jpg";
        else   // ako je slovo
        {
            if(cards[i] != '#')  {
                image_path = ":/resources/images/slova/";
                image_path.push_back(cards[i]);
                image_path.append(".jpg");
            }
            else {
                image_path = ":/resources/images/2B3953.png";
            }
        }
        setCardImage(button,image_path);       // postavljamo sliku

        // postavljam karte u dva reda sa po cetiri kolone
        if (i < 4)
            ui->hand_gridLayout->addWidget(button, 0, i);
        else
            ui->hand_gridLayout->addWidget(button, 1, i-4);
        button->setCheckable(true);         // postavljamo svojstvo checkable
        button->setAutoExclusive(true);
        button->show();         // i zaista prikazujem dugme
    }
    // Skriveno dugme koje ce sluziti da se onemoguci izbor vec odigranih karata
    CustomButton_Card *tmp = new CustomButton_Card();
    tmp->setObjectName("hidden");
    tmp->setCheckable(true);
    tmp->setVisible(false);
    tmp->setAutoExclusive(true);

    ui->hand_gridLayout->addWidget(tmp);
}

void MainWindow::setCardImage(CustomButton_Card *button, std::string imagePath)  {
    QPixmap backgroundButton(QString::fromStdString(imagePath));
    backgroundButton = backgroundButton.scaled(button->size(), Qt::IgnoreAspectRatio);
    QPalette paletteButton;
    paletteButton.setBrush(QPalette::Button, backgroundButton);
    button->setFlat(true);
    button->setAutoFillBackground(true);
    button->setPalette(paletteButton);
}


void MainWindow::createBoard(Board myBoard)
{
    isFirstLetter = true;
    isFirstTurn = true;
    previous_x = -1;
    previous_y = -1;
    int x = 0;
    int y = 0;

    // prolazimo kroz polja
    for (auto element : myBoard.getField())
    {
        for (auto e : element)
        {
            CustomButton_Box *button = new CustomButton_Box();

            // postavljene informacije u svoj objekat
            button->setCoordinate_x(x);      // koordinate
            button->setCoordinate_y(y);
            button->setBox(e);      // tip kutije
            button->setLetterValue('#');    // slovo (u pocetku prazno)
            button->setIsWildcard(false);  // ne sadrzi WildCard
            button->setIsNew(false);    // postavljamo na false, jer nema novog slova

            button->setFixedSize(QSize(40,40));         // postavljamo dimenzije


            ui->board_gridLayout->addWidget(button,button->getCoordinate_y(),button->getCoordinate_x());

            std::string image_path = "";        // u zavisnosti od vrste polja dodajemo odgovarajucu sliku
            switch(button->getBox())
            {
            case (Constants::EMPTY):
                {
                    image_path = ":/resources/images/white.jpeg";
                    break;
                }
            case (Constants::CENTER):
                {
                    image_path = ":/resources/images/center.jpg";
                    break;
                }
            case (Constants::WORDx2):
                {
                    image_path = ":/resources/images/doubleWordScore.jpg";
                    break;
                }
            case (Constants::WORDx3):
                {
                    image_path = ":/resources/images/tripleWordScore.jpg";
                    break;
                }
            case (Constants::LETTERx2):
                {
                    image_path = ":/resources/images/doubleLetterScore.jpg";
                    break;
                }
            case (Constants::LETTERx3):
                {
                    image_path = ":/resources/images/tripleLetterScore.jpg";
                    break;
                }
            }
            setBoxImage(button,image_path);        //dodajemo sliku

            // povezivanje signala i slotova
            QObject::connect(button, SIGNAL(clicked()),
                             button, SLOT(manage_clicked()));
            QObject::connect(button, SIGNAL(send_clicked()),
                             this, SLOT(receiveClickedButton()));

            // u pocetku samo sredisnje dugme moze da se pritisne
            if ((x == y) && (x == Constants::LEN_X/2))
                button->setEnabled(true);
            else
                button->setEnabled(false);

            button->show();         // prikazujemo dugme
            x++;                    //uvecavamo brojac x
        }
        y++;                        // uvecavamo brojac y
        x = 0;                      // resetujemo x
    }
}

void MainWindow::receiveBoard(Board board)
{
    isFirstLetter = true;
    previous_x = -1;
    previous_y = -1;
    int x = 0;
    int y = 0;
    for (auto element : board.getField())
    {
        for (auto e : element)
        {
            CustomButton_Box *button = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y,x)->widget());
            if ((board.getLetters()[y][x] != button->getLetterValue()) || (board.getWildcard()[y][x] != button->getIsWildcard()))
            {
                button->setLetterValue(board.getLetters()[y][x]);

                if (board.getLetters()[y][x] == '#')
                {
                    std::string imagePath = "";
                    switch(e)
                    {
                        case (Constants::EMPTY):
                        {
                            imagePath = ":/resources/images/white.jpeg";
                            break;
                        }
                        case (Constants::CENTER):
                        {
                            imagePath = ":/resources/images/center.jpg";
                            break;
                        }
                        case (Constants::WORDx2):
                        {
                            imagePath = ":/resources/images/doubleWordScore.jpg";
                            break;
                        }
                        case (Constants::WORDx3):
                        {
                            imagePath = ":/resources/images/tripleWordScore.jpg";
                            break;
                        }
                        case (Constants::LETTERx2):
                        {
                            imagePath = ":/resources/images/doubleLetterScore.jpg";
                            break;
                        }
                        case (Constants::LETTERx3):
                        {
                            imagePath = ":/resources/images/tripleLetterScore.jpg";
                            break;
                        }
                    }
                    setBoxImage(button, imagePath);
                }
                else
                {
                    std::string imagePath = "";
                    if (board.getWildcard()[y][x])
                        imagePath = ":/resources/images/joker.jpg";
                    else
                    {
                        imagePath = ":/resources/images/";
                        imagePath.append("slova/");
                        imagePath.push_back(board.getLetters()[y][x]);
                        imagePath.append(".jpg");
                    }
                    setBoxImage(button, imagePath);
                }
            }

            if ((board.isNear(y,x)) && (button->getLetterValue() == '#'))
                button->setEnabled(true);
            else
                button->setEnabled(false);
            if (board.getWildcard()[y][x]) {
                button->setEnabled(true);
            }
            else
                button->setIsWildcard(false);
            button->setIsNew(false);
            x++;
        }
        y++;
        x = 0;
    }

    if(board.isEmpty()){

        CustomButton_Box *button = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(7,7)->widget());
        button->setEnabled(true);

    }
}

void MainWindow::setBoxImage(CustomButton_Box *button, std::string imagePath)
{
    QPixmap backgroundButton(QString::fromStdString(imagePath));
    backgroundButton = backgroundButton.scaled(button->size(), Qt::IgnoreAspectRatio);
    QPalette paletteButton;
    paletteButton.setBrush(QPalette::Button, backgroundButton);
    button->setFlat(true);
    button->setAutoFillBackground(true);
    button->setPalette(paletteButton);
}





int MainWindow::firstUp(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = y - 1;
    while (!end)
    {
        // proveravamo da li nije van granica
        if (tmp != -1)
        {
            CustomButton_Box *buttonBox = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(tmp, x)->widget());
            // proveravamo da li je susedna kutijica slobodna
            if (buttonBox->getLetterValue() == '#')
            {
                end = true;
            }
            else    // ako ne, onda drugu proveravamo
                tmp--;
        }
        else    // ako sam na kraju
            end = true;
    }

    if (tmp != -1)
        dist = y - tmp;    // racunam udaljenost kao razliku pocetne koordinate i koordinate pronadjene kutijice
    else
        dist = 0;   // nema prazne kutijice

    return dist;
}

int MainWindow::firstRight(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = x + 1;
    while (!end)
    {
        // isti princip, proveravamo da li je van granica itd..
        if (tmp != Constants::LEN_X)
        {
            CustomButton_Box *buttonBox = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y, tmp)->widget());
            if (buttonBox->getLetterValue() == '#')
            {
                end = true;
            }
            else
                tmp++;
        }
        else
            end = true;
    }

    if (tmp != Constants::LEN_X)
        dist = tmp - x;
    else
        dist = 0;

    return dist;
}

int MainWindow::firstDown(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = y + 1;
    while (!end)
    {
        if (tmp != Constants::LEN_Y)
        {
            CustomButton_Box *buttonBox = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(tmp, x)->widget());
            if (buttonBox->getLetterValue() == '#')
            {
                end = true;
            }
            else
                tmp++;
        }
        else
            end = true;
    }

    if (tmp != Constants::LEN_Y)
        dist = tmp - y;
    else
        dist = 0;

    return dist;
}

int MainWindow::firstLeft(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = x - 1;
    while (!end)
    {
        if (tmp != -1)
        {
            CustomButton_Box *buttonBox = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y, tmp)->widget());
            if (buttonBox->getLetterValue() == '#')
            {
                end = true;
            }
            else
                tmp--;
        }
        else
            end = true;
    }

    if (tmp != -1)
        dist = x - tmp;
    else
        dist = 0;

    return dist;
}

void MainWindow::receiveClickedButton()
{
    CustomButton_Box* button_box = static_cast<CustomButton_Box*>(sender());       // kastujemo u custombutton_box
    Board  tmpBoard = Board();
    std::string cards = "";

    if (button_box->getIsWildcard())   // ako je karta dzoker tj wildcard, menja se zaa neko sllovo
    {
        // proveravamo koja karta je izabrana
        for (int i = 0; i < ui->hand_gridLayout->count(); i++)
        {
            // proveravamo da li je tekuca sakrivena karta
            CustomButton_Card *button_card = static_cast<CustomButton_Card*>(ui->hand_gridLayout->itemAt(i)->widget());
            if (button_card->objectName() != "hidden")
            {
                // kada nadjemo izabranu kartu
                if (button_card->isChecked())
                {
                    if (button_card->getLetterValue() == button_box->getLetterValue()) // ako se slova poklapaju mozemo izvrsiti zamenu
                    {
                        button_box->setIsWildcard(false);
                        button_card->setLetterValue('*');

                        Constants *l = new Constants();
                        //polje za igru konvertujemo u privremeni board objekat
                       // Board tmpBoard = Board();
                        QVector<QVector<char>> letters_tmp;
                        for (int y = 0; y < l->LEN_Y; y++)
                        {
                            QVector<char> tmp;
                            for (int x = 0; x < l->LEN_X; x++)
                            {

                                CustomButton_Box *button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y,x)->widget());
                                tmp.push_back(button_box->getLetterValue());
                                if (button_box->getIsNew())     // ukoliko je slovo dodato u ovom krugu
                                {
                                    tmpBoard.setNewLetterValue(true,x,y);       //cuvamo informaciju u novoj privremenoj tabli
                                }
                                if (button_box->getIsWildcard())  {   // ukoliko je dzoker karta
                                    tmpBoard.setWildcard(true,x,y);              // cuvamo informaciju u novoj privremenoj tabli
                                }
                            }
                            letters_tmp.push_back(tmp);
                        }
                        tmpBoard.setLetters(letters_tmp);        // dodajemo slova u novu tablu

                        // racunamo igracev novi rezultat
                       // std::string cards = "";
                        for (int i = 0; i < ui->hand_gridLayout->count(); i++)
                        {
                            CustomButton_Card *button_card = static_cast<CustomButton_Card*>(ui->hand_gridLayout->itemAt(i)->widget());
                            if (button_card->objectName() != "hidden")
                                cards.push_back(button_card->getLetterValue());
                        }

                        button_box->setIsWildcard(true);  // vracamo se na originalnu poziciju

                        sendUpdate(tmpBoard,cards);
                    }
                    else        // u suptotnom obavestavamp
                    {
                        QMessageBox msgBox;
                        std::string text = "The WILDCARD can't be taken. Its letter is:";
                        text.push_back(button_box->getLetterValue());
                        msgBox.setText(QString::fromStdString(text));
                        msgBox.exec();
                    }
                }
            }
        }
    }
    else    // u suprotnom normalno smestamo slovo na polje

    {

        for (int x = 0; x < ui->hand_gridLayout->count(); x++)
        {
            // proveravamo da li je tekuci element skrivena karta
            CustomButton_Card *button_card = static_cast<CustomButton_Card*>(ui->hand_gridLayout->itemAt(x)->widget());

            if (button_card->objectName() != "hidden")
            {
                if (button_card->isChecked())
                {
                    cards.append("#");
                    std::string image_path = "";
                    if(button_card->getLetterValue() != '#') {
                        image_path = ":/resources/images/";
                        if (button_card->getLetterValue() == '*')
                            image_path.append("joker");
                        else{
                            image_path.append("slova/");
                            image_path.push_back( button_card->getLetterValue());
                        }
                        image_path.append(".jpg");
                        setBoxImage(button_box, image_path);

                        image_path = ":/resources/images/2B3953.png";
                        setCardImage(button_card, image_path);
                    }

                    if (button_card->getLetterValue() == '*')
                    {
                        w.exec();
                        button_box->setLetterValue(wildcardLetter);
                        std::string imagePath = ":/resources/images/slova/";
                        imagePath.push_back(button_box->getLetterValue());
                        imagePath.append(".jpg");
                         setBoxImage(button_box, imagePath);
                        button_box->setIsWildcard(true);
                    }
                    else
                    {
                        button_box->setLetterValue(button_card->getLetterValue());     // postavljamo slovo
                        button_box->setIsWildcard(false);
                    }
                    button_box->setEnabled(false);      // onemogucujemo polje
                    button_box->setIsNew(true);         // postavljeno je u ovom koraku

                    button_card->setLetterValue('#');              // resetujemo slovo
                    button_card->setEnabled(false);            // onemogucimo kartu


                    QVector<QVector<char>> letters_tmp;
                    for (int y = 0; y < Constants::LEN_Y; y++)
                    {
                        QVector<char> tmp;
                        for (int x = 0; x < Constants::LEN_X; x++)
                        {

                            CustomButton_Box *button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(y,x)->widget());
                            tmp.push_back(button_box->getLetterValue());
                            if (button_box->getIsNew())     // ukoliko je slovo dodato u ovom krugu
                            {
                                tmpBoard.setNewLetterValue(true,x,y);       //cuvamo informaciju u novoj privremenoj tabli
                            }
                            if (button_box->getIsWildcard())  {   // ukoliko je dzoker karta
                                tmpBoard.setWildcard(true,x,y);              // cuvamo informaciju u novoj privremenoj tabli
                            }
                        }
                        letters_tmp.push_back(tmp);
                    }
                    tmpBoard.setLetters(letters_tmp);        // dodajemo slova u novu tablu

                    // namestamo da sloca mogu da se dodaju samo u odredjena polja gde je to omoguceno
                    for (int i = 0; i < ui->board_gridLayout->count(); ++i)
                    {
                        CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAt(i)->widget());
                        my_button_box->setEnabled(false);       // prvo onemogucimo sve dugmice
                    }

                    if (isFirstLetter)     // ukoliko je prvo slovo u potezu igrac mmoze da odluci da li da fa postavi horizontalno ili vertikalno
                    {
                        int my_x = button_box->getCoordinate_x();
                        int my_y = button_box->getCoordinate_y();
                        isFirstLetter = false;
                        previous_x = my_x;
                        previous_y = my_y;
                        if ((firstUp(my_x,my_y) != 0))
                        {
                            CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y - firstUp(my_x,my_y),my_x)->widget());
                            my_button_box->setEnabled(true);
                        }
                        if ((firstRight(my_x,my_y) != 0))
                        {
                            CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y,my_x + firstRight(my_x,my_y))->widget());
                            my_button_box->setEnabled(true);
                        }
                        if ((firstDown(my_x,my_y) != 0))
                        {
                            CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y + firstDown(my_x,my_y),my_x)->widget());
                            my_button_box->setEnabled(true);
                        }
                        if ((firstLeft(my_x,my_y) != 0))
                        {
                            CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y,my_x - firstLeft(my_x,my_y))->widget());
                            my_button_box->setEnabled(true);
                        }
                    }
                    else    // u suprotnom igrac moze samo da nastavi da postavlja slova horizontalno ili vertikalno
                    {
                        int my_x = button_box->getCoordinate_x();
                        int my_y = button_box->getCoordinate_y();

                        // proveravamo da li postavlja horizontlano ili vertikalno
                        if (my_y == previous_y)
                            isHorizontal = true;
                        else
                            isHorizontal = false;

                        if (isHorizontal)  // ukoliko je horizontalno sme da postavlja samo levo ili desno
                        {
                            if (firstRight(my_x,my_y) != 0)
                            {
                                CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y,my_x + firstRight(my_x,my_y))->widget());
                                my_button_box->setEnabled(true);
                            }
                            if (firstLeft(my_x,my_y) != 0)
                            {
                                CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y,my_x - firstLeft(my_x,my_y))->widget());
                                my_button_box->setEnabled(true);
                            }
                        }
                        else                // u suprotnom samo gore ili dole
                        {
                            if (firstUp(my_x,my_y) != 0)
                            {
                                CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y - firstUp(my_x,my_y),my_x)->widget());
                                my_button_box->setEnabled(true);
                            }
                            if (firstDown(my_x,my_y) != 0)
                            {
                                CustomButton_Box *my_button_box = static_cast<CustomButton_Box*>(ui->board_gridLayout->itemAtPosition(my_y + firstDown(my_x,my_y),my_x)->widget());
                                my_button_box->setEnabled(true);
                            }
                        }
                    }
                }
                else {
                    cards.push_back(button_card->getLetterValue());
                }

            }
            else
                button_card->setChecked(true);     // postavljamo na sakriveno dugme i tako teramo igraca da bira dalje
        }

    }
}

bool MainWindow::getIsHorizontal() const{
    return isHorizontal;
}
void MainWindow::setIsHorizontal(bool value){
    isHorizontal = value;
}

char MainWindow::getWildCardLetter() const{
    return wildcardLetter;
}
void MainWindow::setWildCardLetter(const char &value){
    wildcardLetter = value;
}
