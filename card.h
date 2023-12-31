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

    void setIsShowed(bool isShowed);
    bool isShowed() const;

    void collect();
    bool isCollected() const;

signals:
    void turn();

private:
    int _id;
    bool _isShowed;
    bool _isCollected;

    void setupUiShowed();
    void setupUi();
    void setupUiCollected();

private slots:
    void onTurned();
};

#endif //MEMORYGAME_CARD_H
