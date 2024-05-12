#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_login_clicked();

    void on_pushButton_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
