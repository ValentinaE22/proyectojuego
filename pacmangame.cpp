#include "pacmangame.h"
#include <iostream>

PacmanGame::PacmanGame(QWidget *parent) : QWidget(parent) {
    pacmanLabel = new QLabel(this);
    pacmanLabel->setPixmap(QPixmap(":/images/pacman.png")); // Asigna la imagen del PacMan
    pacmanLabel->setScaledContents(true);
    pacmanX = 10; // Posición inicial del PacMan
    pacmanY = 10;
    pacmanLabel->move(pacmanX * 25, pacmanY * 25); // Suponiendo que cada celda del tablero es de 25x25 pixels

    initializeBoard(); // Inicializa el diseño del tablero
    printBoard(); // Imprime el tablero en la consola (solo para depuración)
}

void PacmanGame::initializeBoard() {
    // Inicializa el diseño del tablero
    // Por ejemplo, 'W' para paredes, '.' para puntos, ' ' para espacios vacíos
    // Aquí debería definir el diseño del tablero según necesidades
    // Por ahora, este es como un ejemplo
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (i == 0 || i == boardHeight - 1 || j == 0 || j == boardWidth - 1) {
                board[i][j] = 'W'; // Paredes
            } else {
                board[i][j] = '.'; // Puntos
            }
        }
    }
}

void PacmanGame::printBoard() {
    // Imprime el tablero en la consola (solo para depuración)
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PacmanGame::keyPressEvent(QKeyEvent *event) {
    // Maneja los eventos de teclado para mover al PacMan
    switch (event->key()) {
    case Qt::Key_Left:
        movePacman(-1, 0);
        break;
    case Qt::Key_Right:
        movePacman(1, 0);
        break;
    case Qt::Key_Up:
        movePacman(0, -1);
        break;
    case Qt::Key_Down:
        movePacman(0, 1);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void PacmanGame::movePacman(int dx, int dy) {
    // aquí se mueve al PacMan y verifica las colisiones con las paredes
    int newPacmanX = pacmanX + dx;
    int newPacmanY = pacmanY + dy;
    if (board[newPacmanY][newPacmanX] != 'W') {
        pacmanX = newPacmanX;
        pacmanY = newPacmanY;
        pacmanLabel->move(pacmanX * 25, pacmanY * 25); // Mueve el PacMan visualmente
    }
}
