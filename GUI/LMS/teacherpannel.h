#ifndef TEACHERPANNEL_H
#define TEACHERPANNEL_H

#include <QDialog>

namespace Ui {
class TeacherPannel;
}

class TeacherPannel : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherPannel(QWidget *parent = nullptr);
    ~TeacherPannel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_student_11_clicked();

    void on_student_9_clicked();

    void on_student_12_clicked();

    void on_student_10_clicked();

    void on_student_13_clicked();

    void on_student_14_clicked();

    void on_student_15_clicked();

    void on_student_16_clicked();

    void on_pushButton_5_clicked();

    void onComboBoxIndexChanged(int index);

    void onComboBoxIndex(int index);
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::TeacherPannel *ui;
};

#endif // TEACHERPANNEL_H
