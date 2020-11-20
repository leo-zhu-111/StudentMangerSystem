#include "modifywidget.h"
#include "ui_modifywidget.h"

ModifyWidget::ModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyWidget)
{
    ui->setupUi(this);
}

ModifyWidget::~ModifyWidget()
{
    delete ui;
}

void ModifyWidget::on_btn_returnToMain_clicked()
{
    display(0);
}

//初始化函数 将文件中的学生信息读出来
void ModifyWidget::init(){

    QFile file("student.txt");
    //以只读方式打开
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        QMessageBox::about(NULL,"警告","文件打开失败");
        return;
    }

    //qt文本流
    QTextStream inp(&file);

    QString tmp;
    StudentInfo tmpStudent;
    while( (tmp=inp.readLine()) != NULL)
    {
        QStringList tmplist = tmp.split(",");

        //添加学生时的顺序
        //out << name << ","<<id<<","<<math<<","<<english<<","<<languageC<<endl;;
        tmpStudent.setName(tmplist[0]);
        tmpStudent.setId(tmplist[1].toInt());
        tmpStudent.setMath(tmplist[2].toInt());
        tmpStudent.setEnglish(tmplist[3].toInt());
        tmpStudent.setLanguageC(tmplist[4].toInt());

        m_allStudentInfo.push_back(tmpStudent);
    }

    //关闭文件
    file.close();

}

//修改按钮按下
void ModifyWidget::on_btn_modify_clicked(){
    //如果学号栏的输入信息为空直接返回
    if(ui->lineEdit_id->text() == ""||ui->lineEdit_name->text()==""
            ||ui->lineEdit_math->text()==""||ui->lineEdit_english->text()==""
            ||ui->lineEdit_c->text()=="")
    {
        QMessageBox::about(NULL,"警告","存在信息栏为空");
        return;
    }

    //获取需要修改的学生id
    int id = ui->lineEdit_id->text().toInt();
    bool flag = false;

    for(QVector<StudentInfo>::iterator it=m_allStudentInfo.begin();it!=m_allStudentInfo.end();++it)
    {
        //找到了需要修改的id号
        if(id == it->getId())
        {
            it->setName(ui->lineEdit_name->text());
            it->setMath(ui->lineEdit_math->text().toInt());
            it->setEnglish(ui->lineEdit_english->text().toInt());
            it->setLanguageC(ui->lineEdit_c->text().toInt());
            flag = true;
            break;
        }
    }

    if(flag)
    {
        //更新文件信息
        this->rewriteFile();
        QMessageBox::about(NULL,"提示","修改信息成功");
        //清空各个信息栏
        ui->lineEdit_id->clear();
        ui->lineEdit_math->clear();
        ui->lineEdit_name->clear();
        ui->lineEdit_english->clear();
        ui->lineEdit_c->clear();
    }
    else
    {
        QMessageBox::about(NULL,"警告","未找到该id学生");
    }


}

//删除按钮按下
void ModifyWidget::on_btn_delete_clicked(){
    //如果学号栏的输入信息为空直接返回
    if(ui->lineEdit_id->text() == "")
    {
        QMessageBox::about(NULL,"警告","学号栏为空");
        return;
    }

    //获取需要修改的学生id
    int id = ui->lineEdit_id->text().toInt();
    //记录是否需要删除
    bool flag = false;

    //查找相应学号的id是否存在
    for(QVector<StudentInfo>::iterator it = m_allStudentInfo.begin();it != m_allStudentInfo.end();++it)
    {
        //找到了对应的id
        if(id == it->getId())
        {
            flag = true;
            m_allStudentInfo.erase(it);
            break;
        }
    }

    //成功进行了删除操作
    if(flag){
        QMessageBox::about(NULL,"提示","删除成功");
        //更新文件信息
        this->rewriteFile();
        //清空显示栏
        ui->lineEdit_id->clear();
        ui->lineEdit_math->clear();
        ui->lineEdit_name->clear();
        ui->lineEdit_english->clear();
        ui->lineEdit_c->clear();
    }
    else{
        //未找到数据
        QMessageBox::about(NULL,"警告","未找到该学号学生");
        return;
    }

}

//查找按钮按下
void ModifyWidget::on_btn_Search_clicked(){
    //判断学号栏是否为空
    if(ui->lineEdit_id->text() == "")
    {
        QMessageBox::about(NULL,"警告","学号栏为空");
        return;
    }

    //获取目标学号
    int id = ui->lineEdit_id->text().toInt();
    bool flag = false;
    StudentInfo tmp;
    for(QVector<StudentInfo>::iterator it = m_allStudentInfo.begin();it != m_allStudentInfo.end();++it)
    {
        if(id == it->getId())
        {
            tmp = *it;
            flag = true;
            break;
        }
    }

    if(flag)
    {
        //qDebug() << tmp.getName() << tmp.getMath();

        //找到了数据
        ui->lineEdit_name->setText(tmp.getName());
        ui->lineEdit_math->setText(QString::number(tmp.getMath()));
        ui->lineEdit_english->setText(QString::number(tmp.getEnglish()));
        ui->lineEdit_c->setText(QString::number(tmp.getLanguageC()));
    }
    else
    {
        //未找到数据
        QMessageBox::about(NULL,"警告","未找到数据");
        ui->lineEdit_id->clear();
    }



}

//根据成员变量容器 重写保存的文件
void ModifyWidget::rewriteFile()
{
    QFile file("student.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(!file.isOpen())
    {
        QMessageBox::about(NULL,"警告","文件打开失败");
        return;
    }

    QTextStream out(&file);
    //重写文件中内容
    for(QVector<StudentInfo>::iterator it = m_allStudentInfo.begin();it != m_allStudentInfo.end();++it)
    {
        out << it->getName() << ","<<it->getId()<<","<<it->getMath()<<","<<it->getEnglish()<<","<<it->getLanguageC()<<endl;
    }
    file.close();

}



