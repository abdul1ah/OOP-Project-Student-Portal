#include "studentpannel.h"
#include "globalvariables.h"
#include "mainwindow.h"
#include "ui_studentpannel.h"
#include "user.h"

StudentPannel::StudentPannel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentPannel)
{
    ui->setupUi(this);
    QPixmap background(":/new/prefix1/Images/basic/Group 28.png");
    ui->label2_9->setPixmap(background);
    QPixmap background_2(":/new/prefix1/Images/basic/Group 29 (1).png");
    ui->label2_10->setPixmap(background_2);
    QPixmap background_3(":/new/prefix1/Images/basic/Group 31.png");
    ui->label2_11->setPixmap(background_3);
    QPixmap background_4(":/new/prefix1/Images/basic/Group 30.png");
    ui->label2_12->setPixmap(background_4);

    QPixmap a(":/new/prefix1/Images/basic/lms.png");
    ui->a123->setPixmap(a);

    ui->label2_14->setPixmap(background);
    ui->label2_13->setPixmap(background_2);
    ui->label2_16->setPixmap(background_3);
    ui->label2_15->setPixmap(background_4);

    User u1;
    u1.PrintStudentDetails(globalname);

    ui->name->setText(QString::fromStdString(globalname));
    ui->regno->setText(QString::fromStdString(globalregno));
    ui->email->setText(QString::fromStdString(globalemail));
    ui->faculty->setText(QString::fromStdString(globaltfaculty));
    ui->department->setText(QString::fromStdString(globaltdepartment));

     ui->stackedWidget->setCurrentIndex(0);
}

StudentPannel::~StudentPannel()
{
    delete ui;
}

void StudentPannel::on_pushButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}


void StudentPannel::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void StudentPannel::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void StudentPannel::on_pushButton_4_clicked()
{
    MainWindow *p1 = new MainWindow;
    p1->show();
    this->hide();
}

std::string file1 = "";
void StudentPannel::on_student_11_clicked()
{
    //CS Attendance
    file1 = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Computer.txt";
}


void StudentPannel::on_student_9_clicked()
{
     //Maths Attendance
    file1 = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Maths.txt";
}


void StudentPannel::on_student_12_clicked()
{
     //Physics Attendance
    file1 ="C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Physics.txt";
}


void StudentPannel::on_student_10_clicked()
{
    //Stats Attendance
    file1 = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Stats.txt";
}

