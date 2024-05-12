#include "studentlogin.h"
#include "studentpannel.h"
#include "ui_studentlogin.h"
#include "user.h"

StudentLogin::StudentLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentLogin)
{
    ui->setupUi(this);

    ui->password->setEchoMode(QLineEdit::Password);
    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton_2->setIcon(ceye);

    QPixmap background(":/new/prefix1/Images/basic/style.png");
    ui->label_2->setPixmap(background);

    QPixmap backgroundlogo(":/new/prefix1/Images/basic/Main Logo.png");
    ui->label_3->setPixmap(backgroundlogo);
}

StudentLogin::~StudentLogin()
{
    delete ui;
}

void StudentLogin::on_pushButton_2_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
    QPixmap oeye(":/new/prefix1/Images/Oeye.png");
    ui->pushButton_2->setIcon(oeye);
}


void StudentLogin::on_pushButton_2_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
    QPixmap ceye(":/new/prefix1/Images/Ceye.png");
    ui->pushButton_2->setIcon(ceye);
}


void StudentLogin::on_pushButton_clicked()
{
    User u1;
    QString email = ui->Email->text();
    QString password = ui->password->text();
    std::string email1 = email.toStdString();
    std::string password1 = password.toStdString();

    std::string file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt";
    std::string r = u1.login(file,email1,password1);
    if(r=="Login Successful!!"){
        StudentPannel *login = new StudentPannel;
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

