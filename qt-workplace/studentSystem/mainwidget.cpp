#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
//    ui(new Ui::MainWidget)
{
    //ui->setupUi(this);

    //初始化mainwidget
    this->init();

    //设置连接信号
    this->setConnect();



}

MainWidget::~MainWidget()
{
    //delete ui;
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

    stackLayout->addWidget(menuWidget);//index 0
    stackLayout->addWidget(addStudentWidget);//index 1
    stackLayout->addWidget(selectWidget);//index 2
    stackLayout->addWidget(modifyWidget);//index 3
    stackLayout->addWidget(sortWidget);//index 4

    setLayout(stackLayout);
    stackLayout->setCurrentIndex(0);

    //设置标题
    this->setWindowTitle("学生管理系统");

    //设置窗口宽高
    this->setFixedSize(400,600);
}

//设置接收各个子widget的dispaly信号
void MainWidget::setConnect()
{
    connect(this->menuWidget,&MenuWidget::display,[=](int index){
        stackLayout->setCurrentIndex(index);
    });
    connect(this->addStudentWidget,&AddStudentWidget::display,[=](int index){
        stackLayout->setCurrentIndex(index);
    });
    connect(this->modifyWidget,&ModifyWidget::display,[=](int index){
        stackLayout->setCurrentIndex(index);
    });
    connect(this->selectWidget,&SelectWidget::display,[=](int index){
        stackLayout->setCurrentIndex(index);
    });
    connect(this->sortWidget,&SortWidget::display,[=](int index){
        stackLayout->setCurrentIndex(index);
    });

    //一旦进入学生修改界面，首先自动从文件中读取信息
    connect(this->stackLayout,&QStackedLayout::currentChanged,[=](int index){
        switch(index)
        {
        case 3:
            this->modifyWidget->init();
            break;
        default:
            break;
        }
    });

}


