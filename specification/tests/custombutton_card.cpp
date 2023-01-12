#include "custombutton_card.h"

//CustomButton_Card::CustomButton_Card() {};

CustomButton_Card::CustomButton_Card(QWidget *parent) :
    QPushButton(parent)
{ }

QChar CustomButton_Card::getLetterValue() const
{
    return letter;
}

void CustomButton_Card::setLetterValue(const QChar &value)
{
    letter = value;
}
