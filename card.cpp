#include "card.h"

Card::Card(int id, QWidget *parent) :
        QToolButton(parent),
        _id(id),
        _isTurned(false),
        _isCollected(false),
        _isSame(false)
{
    setFixedSize(100, 100);
    setAutoExclusive(false);
    setCheckable(false);

    setupUi();

    connect(this, &Card::isTurnedChanged, this, &Card::changeView);
}

void Card::setupUi()
{
    setText("");
    setStyleSheet("background-color: green;");
}

void Card::setupUiTurned()
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

void Card::setIsTurned(bool isTurned)
{
    _isTurned = isTurned;
    emit isTurnedChanged();
}

void Card::changeView()
{
    if(_isTurned)
    {
        setupUiTurned();
        _isSame = true;
    }
    else
    {
        setupUi();
        _isSame = false;
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

bool Card::isSame() const
{
    return _isSame;
}
