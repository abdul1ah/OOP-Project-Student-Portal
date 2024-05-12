#include "adminpannel.h"
#include "mainwindow.h"
#include "ui_adminpannel.h"
#include "user.h"
#include <QMessageBox>

AdminPannel::AdminPannel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPannel)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QPixmap a(":/new/prefix1/Images/basic/lms.png");
    ui->a123->setPixmap(a);

    // ui->pushButton_7->setIconSize(32,32);
    // ui->pushButton_7->setIcon();

}

AdminPannel::~AdminPannel()
{
    delete ui;
}

QString name;
QString regno;
QString email;
QString password;
QString age;

void AdminPannel::on_pushButton_5_clicked()
{
    name = ui->name->text();
    regno = ui->regno->text();
    email = ui->email->text();
    password = ui->password->text();
    age = ui->age->text();

    if (!name.isEmpty() && !regno.isEmpty() && !email.isEmpty() && !password.isEmpty() && !age.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void AdminPannel::on_pushButton_6_clicked()
{
    QString batch;
    QString faculty;
    QString department;
    User u1;
    batch = ui->batch->text();
    faculty = ui->faculty->text();
    department = ui->department->text();
    std::string file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt";
    if (!batch.isEmpty() && !faculty.isEmpty() && !department.isEmpty()) {
        std::string nameStd = name.toStdString();
        std::string emailStd = email.toStdString();
        std::string passwordStd = password.toStdString();
        std::string batchStd = batch.toStdString();
        std::string facultyStd = faculty.toStdString();
        std::string departmentStd = department.toStdString();

        int ageInt = age.toInt();
        int regnoInt = regno.toInt();
        u1.registration(nameStd,ageInt,emailStd,passwordStd,regnoInt,file,batchStd,facultyStd,departmentStd);
        QMessageBox *msg = new QMessageBox;
        msg->setWindowTitle("Note");
        msg->setText("Successful Registration");
        msg->show();
        ui->name->clear();
        ui->regno->clear();
        ui->email->clear();
        ui->password->clear();
        ui->age->clear();
        ui->batch->clear();
        ui->faculty->clear();
        ui->department->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }

};


void AdminPannel::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void AdminPannel::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void AdminPannel::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void AdminPannel::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
QString tname;
int tage;
int tcnic;
QString temail;
QString tpassword;


void AdminPannel::on_pushButton_9_clicked()
{
    tname = ui->tname->text();
    tage = ui->tage->text().toInt();
    tcnic = ui->tcnic->text().toInt();
    temail = ui->temail->text();
    tpassword = ui->tpassword->text();
    if (!tname.isEmpty() && tage != 0 && tcnic!= 0  && !temail.isEmpty() && !tpassword.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(3);
    }
}


void AdminPannel::on_pushButton_10_clicked()
{
    User u1;
    QString tdepartment;
    QString Faculty;

    tdepartment = ui->tdepartment->text();
    Faculty = ui->tfaculty->text();

    std::string tname1 = tname.toStdString();
    std::string temail1 = temail.toStdString();
    std::string tpassword1 = tpassword.toStdString();
    std::string tfaculty1 = Faculty.toStdString();
    std::string tdepartment1 = tdepartment.toStdString();

    QMessageBox::information(nullptr, "Note", "Successful Registration");
    ui->tname->clear();
    ui->tage->clear();
    ui->tcnic->clear();
    ui->temail->clear();
    ui->tpassword->clear();
    ui->tdepartment->clear();
    ui->tfaculty->clear();
    ui->stackedWidget->setCurrentIndex(2);
    std::string FILE = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Teacher Data.txt";

    u1.registration(tname1,tage,temail1,tpassword1,tcnic,FILE,"",tfaculty1,tdepartment1);


}


void AdminPannel::on_pushButton_11_clicked()
{
    User u1;
    QString dname = ui->rname->text();
    std::string deletename = dname.toStdString();
    if(!deletename.empty()){
        std::string temp = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\temp.txt";
        std::string file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt";
        std::string returnvalue = u1.deleteaccount(deletename,file,temp);
        QString r1 = QString::fromStdString(returnvalue);
        QMessageBox msg;
        msg.setWindowTitle("Note");
        msg.setText(r1);
        msg.exec();
        ui->rname->clear();
        ui->rregno->clear();

    }
}


void AdminPannel::on_pushButton_12_clicked()
{
   User u1;
   QString cnic = ui->tdcnic->text();
   QString name12 = ui->tdname->text();
   std::string name = name12.toStdString();
   if(!name.empty()){
       std::string temp = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\temp.txt";
       std::string file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Teacher Data.txt";
       std::string returnvalue = u1.deleteaccount(name,file,temp);
       QString r1 = QString::fromStdString(returnvalue);
       QMessageBox msg;
       msg.setWindowTitle("Note");
       msg.setText(r1);
       msg.exec();
       ui->tdcnic->clear();
       ui->tdname->clear();
   }

}


void AdminPannel::on_pushButton_7_clicked()
{
    MainWindow *p1 = new MainWindow;
    p1->show();
    this->hide();
}

