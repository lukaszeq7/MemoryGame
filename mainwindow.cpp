#include <random>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent),
        _mainLayout(new QHBoxLayout(this)),
        _playgroundLayout(new QGridLayout(this)),
        _selectedCard(new Card(-1, this)),
        _card1(new Card(-1, this)),
        _card2(new Card(-1, this)),
        _isSecondCardShowed(false),
        _cardsCounter(0),
        _bothCardsShowed(false)
{
    initCards();
    setupUi();
}

void MainWindow::initCards()
{
    for(int i = 0; i < 8; i++)
    {
        Card* card1 = new Card(i, this);
        Card* card2 = new Card(i, this);

        card1->setIsTurned(false);
        card2->setIsTurned(false);

        connect(card1, &Card::clicked, this, &MainWindow::onCardClicked);
        connect(card2, &Card::clicked, this, &MainWindow::onCardClicked);

        _cards.append(card1);
        _cards.append(card2);
    }
    mixCards();
}

void MainWindow::mixCards()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_cards.begin(), _cards.end(), g);
}

void MainWindow::setupUi()
{
    setFixedSize(800, 600);
    _mainLayout->addLayout(_playgroundLayout);
    setupCards();
}

void MainWindow::setupCards()
{
    for(int c = 0; c < 4; c++)
    {
        for(int r = 0; r < 4;r++)
        {
            _playgroundLayout->setRowStretch(r, 0);
            _playgroundLayout->setColumnStretch(c, 0);
            _playgroundLayout->addWidget(_cards.takeFirst(), r, c);
            _cardsCounter++;
        }
    }

    _selectedCard->hide();
    _card1->hide();
    _card2->hide();
}

void MainWindow::onCardClicked()
{
    _selectedCard = clickedCard();

    if(!_selectedCard->isCollected())
    {
        if(_bothCardsShowed)
        {
            compareCards();
            return;
        }

        if(!_isSecondCardShowed)
        {
            showCards();
            _card1 = _selectedCard;

            _isSecondCardShowed = true;
            return;
        }

        if(_isSecondCardShowed && !_selectedCard->isSame())
        {
            showCards();
            _card2 = _selectedCard;

            _bothCardsShowed = true;
            _isSecondCardShowed = false;
            return;
        }
    }
    else
    {
        compareCards();
    }
}

Card* MainWindow::clickedCard()
{
    return qobject_cast<Card *>(sender());
}

void MainWindow::compareCards()
{
    if (_bothCardsShowed)
    {
        if (sameCards())
        {
            collectCards();
        }
        else
        {
            hideCards();
        }
        _bothCardsShowed = false;
    }
}

bool MainWindow::sameCards()
{
    return _card1->id() == _card2->id();
}

void MainWindow::hideCards()
{
    _card1->setIsTurned(false);
    _card2->setIsTurned(false);
}

void MainWindow::showCards()
{
    _selectedCard->setIsTurned(true);
}

void MainWindow::collectCards()
{
    _card1->collect();
    _card2->collect();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        compareCards();
    }
}