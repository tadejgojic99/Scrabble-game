#ifndef CUSTOMBUTTON_CARD_H
#define CUSTOMBUTTON_CARD_H

#include <QPushButton>
#include <string>

class CustomButton_Card : public QPushButton
{
    //Q_OBJECT

public:
     explicit CustomButton_Card(QWidget* parent=0);

    char getLetterValue() const;
    void setLetterValue(const char &value);

private:
    char letter;
};


#endif // CUSTOMBUTTON_CARD_H
