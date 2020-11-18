#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //初始化mainwidget
    this->init();

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init()
{
    //初始化成员变量
    menuWidget = new MenuWidget;
    addStudentWidget = new AddStudentWidget;//添加学生窗口
    selectWidget = new SelectWidget;//查询窗口
    modifyWidget = new ModifyWidget;//修改窗口
    sortWidget = new SortWidget;//排序窗口
    stackLayout = new QStackedLayout;//QStackedLayout布局

    stackLayout->addWidget(menuWidget);
    stackLayout->addWidget(addStudentWidget);
    stackLayout->addWidget(selectWidget);
    stackLayout->addWidget(modifyWidget);
    stackLayout->addWidget(sortWidget);

    setLayout(stackLayout);
}

