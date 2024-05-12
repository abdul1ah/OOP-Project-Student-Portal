#include "teacherpannel.h"
#include "globalvariables.h"
#include "mainwindow.h"
// #include <ui_teacherpannel.h>
#include "ui_teacherpannel.h"
#include "user.h"

TeacherPannel::TeacherPannel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeacherPannel)
{
    ui->setupUi(this);
    qDebug()<<globalname;
    User u1;
    u1.PrintTeacherDetails(globalname);
    ui->stackedWidget->setCurrentIndex(0);
    ui->name16->setText(QString::fromStdString(globalname));
    ui->cnic16->setText(QString::fromStdString(globalcnic));
    ui->department16->setText(QString::fromStdString(globaltdepartment));
    ui->faculty16->setText(QString::fromStdString(globaltfaculty));
    ui->email16->setText(QString::fromStdString(globalemail));

    QPixmap a(":/new/prefix1/Images/basic/lms.png");
    ui->a123->setPixmap(a);

    QPixmap background(":/new/prefix1/Images/basic/Group 28.png");
    ui->label2_9->setPixmap(background);
    QPixmap background_2(":/new/prefix1/Images/basic/Group 29 (1).png");
    ui->label2_10->setPixmap(background_2);
    QPixmap background_3(":/new/prefix1/Images/basic/Group 31.png");
    ui->label2_11->setPixmap(background_3);
    QPixmap background_4(":/new/prefix1/Images/basic/Group 30.png");
    ui->label2_12->setPixmap(background_4);


    ui->label2_14->setPixmap(background);
    ui->label2_13->setPixmap(background_2);
    ui->label2_16->setPixmap(background_3);
    ui->label2_15->setPixmap(background_4);

}

TeacherPannel::~TeacherPannel()
{
    delete ui;
}

void TeacherPannel::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void TeacherPannel::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void TeacherPannel::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


std::string file;
QString selectedItem;
void TeacherPannel::on_student_11_clicked()
{
    //Attendance
   User u1;
   file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Computer.txt";
   ui->stackedWidget->setCurrentIndex(4);
   u1.readAndStoreLines(file);
   for(int i=0;i<arraysize;i++){
       ui->comboBox_2->addItem(QString::fromStdString(lines[i]));
   }
   connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));

}


void TeacherPannel::on_student_9_clicked()
{
     //Attendance
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Maths.txt";
     ui->stackedWidget->setCurrentIndex(4);
    u1.readAndStoreLines(file);
     for(int i=0;i<arraysize;i++){
        ui->comboBox_2->addItem(QString::fromStdString(lines[i]));
    }
     connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));

}


void TeacherPannel::on_student_12_clicked()
{
    //Attendance
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Physics.txt";
    ui->stackedWidget->setCurrentIndex(4);
    u1.readAndStoreLines(file);
    for(int i=0;i<arraysize;i++){
        ui->comboBox_2->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));

}


void TeacherPannel::on_student_10_clicked()
{
    //Attendance
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Stats.txt";
    ui->stackedWidget->setCurrentIndex(4);
    u1.readAndStoreLines(file);
    for(int i=0;i<arraysize;i++){
        ui->comboBox_2->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));

}
void TeacherPannel::onComboBoxIndexChanged(int index) {
    selectedItem = ui->comboBox_2->itemText(index);
}


void TeacherPannel::on_pushButton_5_clicked()
{
    User u1;
    QString a = ui->lineEdit_2->text();
    std::string b = a.toStdString();
    std::string temp = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Temp File.txt";
    std::string v = selectedItem.toStdString();
    qDebug ()<< temp;
    qDebug ()<< b;
    qDebug ()<< v;
    qDebug ()<< file;

    u1.replaceNextLine(file, v, b, temp);
}




void TeacherPannel::on_student_13_clicked()
{
    //Grade
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Computer.txt";
    ui->stackedWidget->setCurrentIndex(3);
    u1.readAndStoreLines(file);
    for(int i=0; i<arraysize; i++){
        ui->comboBox->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndex(int)));
}


void TeacherPannel::on_student_14_clicked()
{
    //Grade
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Maths.txt";
    ui->stackedWidget->setCurrentIndex(3);
    u1.readAndStoreLines(file);
    for(int i=0; i<arraysize; i++){
        ui->comboBox->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndex(int)));
}


void TeacherPannel::on_student_15_clicked()
{
    //Grade
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Physics.txt";
    ui->stackedWidget->setCurrentIndex(3);
    u1.readAndStoreLines(file);
    for(int i=0; i<arraysize; i++){
        ui->comboBox->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndex(int)));
}


void TeacherPannel::on_student_16_clicked()
{
    //Grade
    User u1;
    file = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Stats.txt";
    ui->stackedWidget->setCurrentIndex(3);
    u1.readAndStoreLines(file);
    for(int i=0; i<arraysize; i++){
        ui->comboBox->addItem(QString::fromStdString(lines[i]));
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndex(int)));
}


QString selectedItem2;
void TeacherPannel::onComboBoxIndex(int index) {
    selectedItem2 = ui->comboBox->itemText(index);
}

void TeacherPannel::on_pushButton_4_clicked()
{
    User u1;
    QString a = ui->lineEdit->text();
    std::string b = a.toStdString();
    std::string temp = "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Temp File.txt";
    std::string v = selectedItem2.toStdString();
    qDebug ()<< temp;
    qDebug ()<< b;
    qDebug ()<< v;
    qDebug ()<< file;
    u1.replaceLinesAfter(file, v, b, temp);

}

void TeacherPannel::on_pushButton_6_clicked()
{
    MainWindow *p1 = new MainWindow;
    p1->show();
    this->hide();
}

