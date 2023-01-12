#ifndef CUSTOMBUTTON_CARD_H
#define CUSTOMBUTTON_CARD_H

#include <QPushButton>
#include <QString>
#include <QChar>

class CustomButton_Card : public QPushButton
{
    //Q_OBJECT

public:
     explicit CustomButton_Card(QWidget* parent=0);

    // getter i setter
    QChar getLetterValue() const;
    void setLetterValue(const QChar &value);

private:
    QChar letter;      // Slovo sa kartice
};


#endif // CUSTOMBUTTON_CARD_H
