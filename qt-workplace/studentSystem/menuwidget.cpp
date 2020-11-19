#include "menuwidget.h"
#include "ui_menuwidget.h"
#include <QDebug>
MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::on_btn_add_clicked()
{
    //qDebug() << "按下了添加按钮";
    emit display(1);
}

void MenuWidget::on_btn_select_clicked()
{
    //qDebug() << "按下了选择按钮";
    emit display(2);

}

void MenuWidget::on_btn_modify_clicked()
{
    //qDebug()<<"按下了修改按钮";
    emit display(3);
}

void MenuWidget::on_btn_sort_clicked()
{
    emit display(4);
}

void MenuWidget::on_btn_exit_clicked()
{
    QApplication::exit();
}



