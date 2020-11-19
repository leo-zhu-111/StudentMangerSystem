#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>

namespace Ui {
class SelectWidget;
}

class SelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectWidget(QWidget *parent = 0);
    ~SelectWidget();

    //初始化显示框
    void init();

private:
    Ui::SelectWidget *ui;
private slots:
    void on_btn_returnToMain_clicked();

signals:
    void display(int index);

};

#endif // SELECTWIDGET_H
