#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"

AddStudentWidget::AddStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentWidget)
{
    ui->setupUi(this);
}

AddStudentWidget::~AddStudentWidget()
{
    delete ui;
}
