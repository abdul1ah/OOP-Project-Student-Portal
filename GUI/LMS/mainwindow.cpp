#include "mainwindow.h"
#include "adminlogin.h"
#include "teacherlogin.h"
#include "ui_mainwindow.h"

#include <StudentLogin.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/new/prefix1/Images/basic/style.png");
    ui->label_2->setPixmap(background);

    QPixmap backgroundlogo(":/new/prefix1/Images/basic/Main Logo.png");
    ui->label->setPixmap(backgroundlogo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_admin_clicked()
{
    AdminLogin *ptr = new AdminLogin;
    ptr->show();
    this->hide();
}


void MainWindow::on_teacher_clicked()
{
    TeacherLogin *login = new TeacherLogin;
    login->show();
    this->hide();
}


void MainWindow::on_student_clicked()
{
    StudentLogin *login = new StudentLogin;
    login->show();
    this->hide();
}

