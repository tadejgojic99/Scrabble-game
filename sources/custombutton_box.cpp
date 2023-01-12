#include "../headers/custombutton_box.h"

CustomButton_Box::CustomButton_Box(QWidget *parent) :
    QPushButton(parent)
{

}

unsigned int CustomButton_Box::getBox() const
{
    return box;
}

void CustomButton_Box::setBox(unsigned int value)
{
    box = value;
}

int CustomButton_Box::getCoordinate_x() const
{
    return coordinate_x;
}

void CustomButton_Box::setCoordinate_x(int value)
{
    coordinate_x = value;
}

int CustomButton_Box::getCoordinate_y() const
{
    return coordinate_y;
}

void CustomButton_Box::setCoordinate_y(int value)
{
    coordinate_y = value;
}

char CustomButton_Box::getLetterValue() const
{
    return letter;
}

void CustomButton_Box::setLetterValue(const char &value)
{
    letter = value;
}

bool CustomButton_Box::getIsNew() const
{
    return isNew;
}

void CustomButton_Box::setIsNew(bool value)
{
    isNew = value;
}

bool CustomButton_Box::getIsWildcard() const
{
    return isWildcard;
}

void CustomButton_Box::setIsWildcard(bool value)
{
    isWildcard = value;
}

void CustomButton_Box::manage_clicked()
{
    send_clicked();
}

