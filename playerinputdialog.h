#ifndef PLAYERINPUTDIALOG_H
#define PLAYERINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class PlayerInputDialog;
}

class PlayerInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInputDialog(QWidget *parent = nullptr);
    ~PlayerInputDialog();

    QString getPlayerID() const;

private:
    Ui::PlayerInputDialog *ui;
};

#endif // PLAYERINPUTDIALOG_H

