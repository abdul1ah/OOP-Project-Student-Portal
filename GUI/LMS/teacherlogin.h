#ifndef TEACHERLOGIN_H
#define TEACHERLOGIN_H

#include <QDialog>

namespace Ui {
class TeacherLogin;
}

class TeacherLogin : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherLogin(QWidget *parent = nullptr);
    ~TeacherLogin();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_released();

    void on_pushButton_2_clicked();

    void on_pushButton_released();

private:
    Ui::TeacherLogin *ui;
};

#endif // TEACHERLOGIN_H
