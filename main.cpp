#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QTimer> // Necesario para gestionar el tiempo de los puntos de poder
#include "Ghost.h" // Incluir el archivo de encabezado de Ghost
#include <QInputDialog>

class PacmanGame : public QWidget {
private:
    QLabel *pacmanLabel;
    int pacmanX, pacmanY; // Posición actual del PacMan
    int lives; // Vidas del jugador
    int currentLevel; // Nivel actual del juego
    QString playerID; // ID del jugador
    Ghost *blinky; // Fantasma Blinky
    Ghost *pinky; // Fantasma Pinky
    Ghost *inky; // Fantasma Inky
    Ghost *clyde; // Fantasma Clyde
    int powerPellets; // Contador de puntos de poder recolectados
    QTimer *powerPelletTimer; // Temporizador para la duración de los puntos de poder

public:
    PacmanGame(QString id, QWidget *parent = nullptr) : QWidget(parent), playerID(id) {
        pacmanLabel = new QLabel(this);
        pacmanLabel->setPixmap(QPixmap(":/images/pacman.png"));
        pacmanLabel->setScaledContents(true);
        pacmanX = 200; // Posición inicial del PacMan en el medio del tablero
        pacmanY = 250; // Suponiendo que el tablero tiene 500x500 y el PacMan es de tamaño 50x50
        pacmanLabel->move(pacmanX, pacmanY);
        lives = 3; // se inicializan vidas del jugador
        currentLevel = 1; // se inicializa nivel del juego
        powerPellets = 0; // se inicializa contador de puntos de poder

        // se crea e inicializa los fantasmas
        blinky = new Ghost(this);
        blinky->setStartPosition(100, 100); // Posición inicial del fantasma Blinky
        blinky->setPersonality("Blinky"); // asigna personalidad a Blinky
        blinky->startMovement(); // Iniciar movimiento del fantasma Blinky

        pinky = new Ghost(this);
        pinky->setStartPosition(400, 100); // Posición inicial del fantasma Pinky
        pinky->setPersonality("Pinky"); // Asigna personalidad a Pinky
        pinky->startMovement(); // Iniciar movimiento del fantasma Pinky

        inky = new Ghost(this);
        inky->setStartPosition(100, 400); // Posición inicial del fantasma Inky
        inky->setPersonality("Inky"); // Asigna personalidad a Inky
        inky->startMovement(); // Iniciar movimiento del fantasma Inky

        clyde = new Ghost(this);
        clyde->setStartPosition(400, 400); // Posición inicial del fantasma Clyde
        clyde->setPersonality("Clyde"); // Asigna personalidad a Clyde
        clyde->startMovement(); // Iniciar movimiento del fantasma Clyde

        // aquí se configura temporizador para la duración de los puntos de poder
        powerPelletTimer = new QTimer(this);
        connect(powerPelletTimer, &QTimer::timeout, this, &PacmanGame::resetGhostColor);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
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

private:
    void movePacman(int dx, int dy) {
        // aquí se verifica si el movimiento es posible (por ejemplo, no chocar con paredes)
        // Aquí se debería tener lógica para verificar colisiones y mover al PacMan

        // Por ahora, simplemente se actualiza la posición del PacMan en la pantalla
        pacmanX += dx;
        pacmanY += dy;
        pacmanLabel->move(pacmanX, pacmanY);

        // Verifica colisión con puntos de poder
        // Supongamos que los puntos de poder están en (100, 100) y (400, 400) para este ejemplo
        if ((pacmanX == 100 && pacmanY == 100) || (pacmanX == 400 && pacmanY == 400)) {
            powerPellets++;
            // Inicia temporizador para la duración de los puntos de poder (15 segundos)
            powerPelletTimer->start(15000);
            // Aquí debería cambiar el tamaño de los fantasmas y actualizar su comportamiento
            // Por ejemplo, hacerlos comestibles por 15 segundos
        }
    }

    void resetGhostColor() {
        // Aquí debería restaurar el color normal de los fantasmas
        // Por ejemplo, después de que los puntos de poder hayan perdido su efecto
        powerPelletTimer->stop();
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // se obtiene el ID del jugador desde la línea de comandos
    QString playerID;
    if (argc > 1) {
        playerID = argv[1];
    } else {
        playerID = "Sin ID";
    }

    PacmanGame game(playerID);
    game.resize(500, 500); // Ajusta el tamaño de la ventana del juego según las necesidades que tengamos
    game.setWindowTitle("PacMan Game");
    game.show();

    return a.exec();
}

