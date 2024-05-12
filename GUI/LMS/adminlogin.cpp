#include "adminlogin.h"
#include "ui_adminlogin.h"

#include <AdminPannel.h>

AdminLogin::AdminLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton->setIcon(ceye);

    QPixmap background(":/new/prefix1/Images/basic/style.png");
    ui->label_2->setPixmap(background);

    QPixmap backgroundlogo(":/new/prefix1/Images/basic/Main Logo.png");
    ui->label_3->setPixmap(backgroundlogo);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_login_clicked()
{
    QString email = ui->email->text();
    QString password = ui->password->text();
    if (email == "GIKILMS" && password =="123"){
        AdminPannel *login = new AdminPannel;
        this->close();
        login->show();
    }
    else{
        ui->invalid->setText("Invalid Password");
    }

}

void AdminLogin::on_pushButton_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
    QPixmap oeye(":/new/prefix1/Images/Oeye.png");
    ui->pushButton->setIcon(oeye);
}


void AdminLogin::on_pushButton_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton->setIcon(ceye);
}

