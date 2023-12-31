#include "card.h"

Card::Card(int id, QWidget *parent) :
        QToolButton(parent),
        _id(id),
        _isShowed(false),
        _isCollected(false)
{
    setFixedSize(100, 100);
    setAutoExclusive(false);
    setCheckable(false);

    setupUi();

    connect(this, &Card::turn, this, &Card::onTurned);
}

void Card::setupUi()
{
    setText("");
    setStyleSheet("background-color: green;");
}

void Card::setupUiShowed()
{
    setText(QString::number(_id));
    setStyleSheet("background-color: red; "
                  "font-size: 80pt; "
                  "font-weight: bold; "
                  "color: white; "
                  "text-align: center;"
    );
}

void Card::setupUiCollected()
{
    setText("");
    setStyleSheet("background-color: black;");
}

int Card::id() const
{
    return _id;
}

void Card::setIsShowed(bool isShowed)
{
    _isShowed = isShowed;
    emit turn();
}

bool Card::isShowed() const
{
    return _isShowed;
}

void Card::onTurned()
{
    if(_isShowed)
    {
        setupUiShowed();
    }
    else
    {
        setupUi();
    }
}

void Card::collect()
{
    setupUiCollected();
    _isCollected = true;
}

bool Card::isCollected() const
{
    return _isCollected;
}