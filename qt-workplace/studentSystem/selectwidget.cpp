#include "selectwidget.h"
#include "ui_selectwidget.h"

SelectWidget::SelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWidget)
{
    ui->setupUi(this);

    //初始化显示框
    this->init();
}

SelectWidget::~SelectWidget()
{
    delete ui;
}

void SelectWidget::on_btn_returnToMain_clicked()
{
    //清空各个显示，搜索栏
    ui->lineEdit->clear();
    ui->label_name->clear();
    ui->label_math->clear();
    ui->label_english->clear();
    ui->label_c->clear();

    display(0);
}

//初始化显示框
void SelectWidget::init()
{
    ui->label_average->setText("NULL");
    ui->label_math->setText("NULL");
    ui->label_english->setText("NULL");
    ui->label_c->setText("NULL");
    ui->label_name->setText("NULL");
}

//按下搜索按钮
void SelectWidget::on_btn_Search_clicked()
{
    //学号输入栏为空 直接返回
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::about(NULL,"警告","学号输入栏为空");
        return;
    }

    //读取student文件的信息
    QVector<StudentInfo> m_StudentInfo;
    readFromFile("student.txt",m_StudentInfo);

    int id = ui->lineEdit->text().toInt();
    bool flag = false;

    StudentInfo tmp;
    for(QVector<StudentInfo>::iterator it = m_StudentInfo.begin();it != m_StudentInfo.end();++it)
    {
        //找到了学生信息
        if(id == it->getId())
        {
            tmp = *it;
            flag = true;
            break;
        }
    }

    //计算平均成绩
    tmp.calculateAverage();

    //找到信息，显示信息
    if(flag)
    {
        ui->label_name->setText(tmp.getName());
        ui->label_math->setText(QString::number(tmp.getMath()));
        ui->label_english->setText(QString::number(tmp.getEnglish()));
        ui->label_c->setText(QString::number(tmp.getLanguageC()));
        ui->label_average->setText(QString::number(tmp.getAverage()));

    }
    else
    {
        //未找到 弹窗提示
        QMessageBox::about(NULL,"警告","未找到该学号学生");
        ui->lineEdit->clear();
        return;
    }
}

//读取文件信息
void SelectWidget::readFromFile(QString path,QVector<StudentInfo>& m_StudentInfo)
{
    QFile file(path);
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

        m_StudentInfo.push_back(tmpStudent);
    }

    //关闭文件
    file.close();

}

