#include "Ghost.h"
#include <QRandomGenerator>


Ghost::Ghost(QObject *parent) : QObject(parent) {
    ghostLabel = new QLabel();
    ghostLabel->setFixedSize(50, 50); // Tamaño del fantasma
    ghostLabel->setPixmap(QPixmap(":/images/ghost.png")); // la ruta de la imagen del fantasma
    ghostLabel->setScaledContents(true);
}



void Ghost::setStartPosition(int x, int y) {
    currentX = x;
    currentY = y;
    ghostLabel->move(currentX, currentY);
}

void Ghost::startMovement() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ghost::moveGhost);
    timer->start(200); // Velocidad de movimiento del fantasma (en milisegundos)
}

void Ghost::moveGhost() {
    // Lógica de movimiento del fantasma
    // Por ahora, solo movemos el fantasma aleatoriamente
    int direction = QRandomGenerator::global()->bounded(4); // 0: arriba, 1: abajo, 2: izquierda, 3: derecha
    switch (direction) {
    case 0:
        currentY -= 50;
        break;
    case 1:
        currentY += 50;
        break;
    case 2:
        currentX -= 50;
        break;
    case 3:
        currentX += 50;
        break;
    }
    ghostLabel->move(currentX, currentY);
}

void Ghost::setPersonality(const QString &p){
    personality = p;
}
