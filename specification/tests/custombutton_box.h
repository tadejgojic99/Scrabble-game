#ifndef CUSTOMBUTTON_BOX_H
#define CUSTOMBUTTON_BOX_H

#include <QPushButton>
#include <QString>
#include <QChar>
#include <QObject>

class CustomButton_Box : public QPushButton
{
    Q_OBJECT

public:
//    CustomButton_Box();
    CustomButton_Box(QWidget *parent=0);

    unsigned int getBox() const;
    void setBox(unsigned int value);

    int getCoordinate_x() const;
    void setCoordinate_x(int value);

    int getCoordinate_y() const;
    void setCoordinate_y(int value);

    QChar getLetterValue() const;
    void setLetterValue(const QChar &value);

    bool getIsNew() const;
    void setIsNew(bool value);

    bool getIsWildcard() const;
    void setIsWildcard(bool value);

private:
    int coordinate_x;            // x koordinata celije u kojoj je kutijica
    int coordinate_y;            // y koordinata celije u kojoj je kutijica
    unsigned int box;            // vrsta polja
    bool isNew;                  // govori nam da li je slovo vezano za tu kutijicu odigrano u ovom potezu
    bool isWildcard;             // indikator  dzoker-a
    QChar letter;                // slovo vezano za tu kutijicu

signals:
    void send_clicked();        // salje signal da je kliknuto na kutijicu

private slots:
    void manage_clicked();      // obrada, tj. preko ovog slota cemo slati signal da je kliknuto
};

#endif // CUSTOMBUTTON_BOX_H
