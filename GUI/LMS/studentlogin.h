#ifndef STUDENTLOGIN_H
#define STUDENTLOGIN_H

#include <QDialog>

namespace Ui {
class StudentLogin;
}

class StudentLogin : public QDialog
{
    Q_OBJECT

public:
    explicit StudentLogin(QWidget *parent = nullptr);
    ~StudentLogin();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_clicked();

private:
    Ui::StudentLogin *ui;
};

#endif // STUDENTLOGIN_H
