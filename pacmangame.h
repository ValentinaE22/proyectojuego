#ifndef PACMANGAME_H
#define PACMANGAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include "Ghost.h"

    class PacmanGame : public QWidget {
    Q_OBJECT
private:
    char board[20][20]; // Tablero del juego
    const int boardWidth = 20; // Ancho del tablero
    const int boardHeight = 20; // Alto del tablero

    QLabel *pacmanLabel;
    int pacmanX, pacmanY; // Posición actual del PacMan
    // Aquí declarar las variables y métodos necesarios para los fantasmas y otros elementos del juego

public:
    PacmanGame(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void initializeBoard(); // Inicializa el diseño del tablero
    void printBoard(); // Imprime el tablero en la consola (solo para depuración)
    void movePacman(int dx, int dy); // Mueve al PacMan
    // Aquí declarar otros métodos necesarios para la lógica del juego
};

#endif // PACMANGAME_H

