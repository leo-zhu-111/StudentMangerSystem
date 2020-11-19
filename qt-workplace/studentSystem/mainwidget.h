#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "addstudentwidget.h"
#include "menuwidget.h"
#include"modifywidget.h"
#include"selectwidget.h"
#include"sortwidget.h"
#include<QStackedLayout>

//namespace Ui {
//class MainWidget;
//}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    //初始化mainWidget
    void init();

    //设置接收各个子widget的dispaly信号
    void setConnect();

public:
    //成员变量
    MenuWidget *menuWidget;//菜单窗口
    AddStudentWidget* addStudentWidget;//添加学生窗口
    SelectWidget* selectWidget;//查询窗口
    ModifyWidget* modifyWidget;//修改窗口
    SortWidget* sortWidget;//排序窗口
    //栈容器，只有一个目标可以显示
    QStackedLayout* stackLayout;//QStackedLayout布局


private:
//    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
