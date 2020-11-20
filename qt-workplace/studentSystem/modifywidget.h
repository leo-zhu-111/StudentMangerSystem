#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>
#include <QVector>
#include "studentinfo.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = 0);
    ~ModifyWidget();

private:
    Ui::ModifyWidget *ui;

public:
    //创建存放全部学生信息的成员变量容器
    QVector<StudentInfo> m_allStudentInfo;
    //初始化函数 将文件中的学生信息读出来
    void init();
    //根据成员变量容器 重写保存的文件
    void rewriteFile();

private slots:
    //返回主菜单槽函数
    void on_btn_returnToMain_clicked();
    void on_btn_modify_clicked();//修改按钮按下
    void on_btn_delete_clicked();//删除按钮按下
    //查找按钮按下
    void on_btn_Search_clicked();
signals:
    //切换界面信号
    void display(int index);

};

#endif // MODIFYWIDGET_H
