#include "sortwidget.h"
#include "ui_sortwidget.h"

SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortWidget)
{
    ui->setupUi(this);
}

SortWidget::~SortWidget()
{
    delete ui;
}