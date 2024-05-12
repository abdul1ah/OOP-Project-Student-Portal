#include "teacherlogin.h"
#include "ui_teacherlogin.h"
#include "user.h"

#include <TeacherPannel.h>

TeacherLogin::TeacherLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeacherLogin)
{
    ui->setupUi(this);

    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton->setIcon(ceye);

    QPixmap background(":/new/prefix1/Images/basic/style.png");
    ui->label_2->setPixmap(background);

    QPixmap backgroundlogo(":/new/prefix1/Images/basic/Main Logo.png");
    ui->label_3->setPixmap(backgroundlogo);
}

TeacherLogin::~TeacherLogin()
{
    delete ui;
}

void TeacherLogin::on_pushButton_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
    QPixmap oeye(":/new/prefix1/Images/Oeye.png");
    ui->pushButton->setIcon(oeye);
}

void TeacherLogin::on_pushButton_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton->setIcon(ceye);
}

void TeacherLogin::on_pushButton_2_clicked()
{
    User u1;
    QString email = ui->Email->text();
    QString password = ui->password->text();
    std::string email1 = email.toStdString();
    std::string password1 = password.toStdString();

    std::string file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Teacher Data.txt";
    std::string r = u1.login(file,email1,password1);
    if(r=="Login Successful!!"){
        TeacherPannel *login = new TeacherPannel;
        login->show();
        this->hide();
    }
    else {
        QString a = QString::fromStdString(r);
        ui->invalid->setText(a);
        ui->Email->clear();
        ui->password->clear();
    }
}



