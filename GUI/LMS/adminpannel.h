#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QDialog>

namespace Ui {
class AdminPannel;
}

class AdminPannel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPannel(QWidget *parent = nullptr);
    ~AdminPannel();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::AdminPannel *ui;
};

#endif // ADMINPANNEL_H
