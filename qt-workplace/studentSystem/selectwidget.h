#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include "studentinfo.h"
#include <QFile>
namespace Ui {
class SelectWidget;
}

class SelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectWidget(QWidget *parent = 0);
    ~SelectWidget();

    //初始化显示框
    void init();

    //读取文件信息
    void readFromFile(QString path,QVector<StudentInfo>& m_StudentInfo);


private:
    Ui::SelectWidget *ui;
private slots:
    //按下了返回主菜单按钮
    void on_btn_returnToMain_clicked();
    //按下搜索按钮
    void on_btn_Search_clicked();

signals:
    void display(int index);

};

#endif // SELECTWIDGET_H
