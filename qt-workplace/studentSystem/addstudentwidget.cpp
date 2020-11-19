#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"

//构造函数
AddStudentWidget::AddStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentWidget)
{
    ui->setupUi(this);


}

//析构函数
AddStudentWidget::~AddStudentWidget()
{
    delete ui;
}

//设置按下主菜单的槽函数
void AddStudentWidget::on_btn_returnToMain_clicked()
{
    display(0);
}

//设置按下添加按钮的槽函数
void AddStudentWidget::on_btn_add_clicked()
{
    //如果输入框为空则 出错
    if(ui->lineEdit_c->text() == ""||ui->lineEdit_english->text() ==""||
            ui->lineEdit_math->text() == ""||ui->lineEdit_number->text() == ""||
            ui->lineEdit_name->text() == "")
    {
        QMessageBox::about(NULL,"出错","输入有误,存在空项");
        return;
    }
    //取出姓名 id 英语 数学 c语言成绩
    QString name = ui->lineEdit_name->text();
    int id = ui->lineEdit_number->text().toInt();
    int math = ui->lineEdit_math->text().toInt();
    int english = ui->lineEdit_english->text().toInt();
    int languageC = ui->lineEdit_c->text().toInt();

    QFile file("./student.txt");
    //以只读 文本文件  追加方式 打开
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(!file.isOpen())
    {
        QMessageBox::about(NULL,"出错","数据文件打开失败");
        return;
    }
    //通过QTextStream进行基本的文件读写
    QTextStream out(&file);
    out << name << ","<<id<<","<<math<<","<<english<<","<<languageC<<endl;;
    //关闭文件
    file.close();
    QMessageBox::about(NULL,"提示","写入成功");
    //写入成功后将数据清除
    ui->lineEdit_c->clear();
    ui->lineEdit_english->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_math->clear();
    ui->lineEdit_number->clear();

}




