#ifndef WIDGETENDGAME_H
#define WIDGETENDGAME_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class WidgetEndGame : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * vLayout = new QVBoxLayout();

    QLabel * textGameHasEnded = new QLabel("Game has ended!");
    QLabel * textWhoHasWon = new QLabel();

    QPushButton * buttonRestartGame = new QPushButton("Restart game");

private slots:
    void restartGame();

public:
    WidgetEndGame();

    void setIfPlayerWon(bool playerWon);
};

#endif // WIDGETENDGAME_H
