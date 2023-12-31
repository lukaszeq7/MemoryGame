#ifndef MEMORYGAME_MAINWINDOW_H
#define MEMORYGAME_MAINWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QGridLayout>

#include "card.h"

class MainWindow : public QWidget
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void onCardClicked();

private:
    QHBoxLayout* _mainLayout;
    QGridLayout* _playgroundLayout;
    QList<Card*> _cards;
    int _cardsCounter;
    Card* _selectedCard;
    Card* _card1;
    Card* _card2;
    bool _isSecondCardShowed;
    bool _bothCardsShowed;

    void initCards();
    void mixCards();

    void setupUi();
    void setupCards();

    Card* clickedCard();

    void compareCards();
    bool isSameCards();

    void collectCards();
    void hideCards();
    void showCard();
};

#endif //MEMORYGAME_MAINWINDOW_H
