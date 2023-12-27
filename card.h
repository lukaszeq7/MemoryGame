#ifndef MEMORYGAME_CARD_H
#define MEMORYGAME_CARD_H

#include <QWidget>
#include <QToolButton>
#include <QDebug>

class Card : public QToolButton
{
Q_OBJECT

public:
    explicit Card(int id, QWidget *parent = nullptr);

    int id() const;

    void setIsTurned(bool isTurned);

    void collect();
    bool isCollected() const;

    bool isSame() const;

signals:
    void isTurnedChanged();

private:
    int _id;
    bool _isTurned;
    bool _isCollected;
    bool _isSame;

    void setupUiTurned();
    void setupUi();
    void setupUiCollected();

private slots:
    void changeView();
};

#endif //MEMORYGAME_CARD_H
