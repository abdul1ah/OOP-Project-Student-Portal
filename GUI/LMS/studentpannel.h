#ifndef STUDENTPANNEL_H
#define STUDENTPANNEL_H

#include <QDialog>

namespace Ui {
class StudentPannel;
}

class StudentPannel : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPannel(QWidget *parent = nullptr);
    ~StudentPannel();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_student_11_clicked();

    void on_student_9_clicked();

    void on_student_12_clicked();

    void on_student_10_clicked();

private:
    Ui::StudentPannel *ui;
};

#endif // STUDENTPANNEL_H
