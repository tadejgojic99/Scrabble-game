#ifndef CUSTOMBUTTON_BOX_H
#define CUSTOMBUTTON_BOX_H

#include <QPushButton>
#include <string>
#include <QObject>

class CustomButton_Box : public QPushButton
{
    Q_OBJECT

public:
    CustomButton_Box(QWidget *parent=0);

    unsigned int getBox() const;
    void setBox(unsigned int value);

    int getCoordinate_x() const;
    void setCoordinate_x(int value);

    int getCoordinate_y() const;
    void setCoordinate_y(int value);

    char getLetterValue() const;
    void setLetterValue(const char &value);

    bool getIsNew() const;
    void setIsNew(bool value);

    bool getIsWildcard() const;
    void setIsWildcard(bool value);

private:
    int coordinate_x;
    int coordinate_y;
    unsigned int box;
    bool isNew;
    bool isWildcard;
    char letter;

signals:
    void send_clicked();

private slots:
    void manage_clicked();
};

#endif // CUSTOMBUTTON_BOX_H
