#include "../headers/custombutton_card.h"

CustomButton_Card::CustomButton_Card(QWidget *parent) :
    QPushButton(parent)
{ }

char CustomButton_Card::getLetterValue() const
{
    return letter;
}

void CustomButton_Card::setLetterValue(const char &value)
{
    letter = value;
}
