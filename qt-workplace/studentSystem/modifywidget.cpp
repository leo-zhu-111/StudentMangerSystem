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
