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
