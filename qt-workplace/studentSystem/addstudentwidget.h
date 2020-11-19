#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QMessageBox>
#include<QDebug>
#include<QString>
namespace Ui {
class AddStudentWidget;
}

class AddStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWidget(QWidget *parent = 0);
    ~AddStudentWidget();

private:
    Ui::AddStudentWidget *ui;

private slots:
    //设置按下主菜单的槽函数
    void on_btn_returnToMain_clicked();
    //设置按下添加按钮的槽函数
    void on_btn_add_clicked();
signals:
    //设置切换窗口的信号
    void display(int index);
};

#endif // ADDSTUDENTWIDGET_H
