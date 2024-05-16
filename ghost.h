#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <QTimer>
#include <QLabel>

class Ghost : public QObject {
    Q_OBJECT
public:
    explicit Ghost(QObject *parent = nullptr);

    void setStartPosition(int x, int y);
    void startMovement();
    void setPersonality(const QString &p);


private:
    QString personality;
    QLabel *ghostLabel;
    int currentX, currentY;

    void moveGhost();

signals:

};

#endif // GHOST_H
