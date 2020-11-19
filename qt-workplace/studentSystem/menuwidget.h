#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QApplication>
namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = 0);
    ~MenuWidget();

private:
    Ui::MenuWidget *ui;

private slots:
    void on_btn_add_clicked();
    void on_btn_select_clicked();
    void on_btn_modify_clicked();
    void on_btn_sort_clicked();
    void on_btn_exit_clicked();

signals:
    void display(int index);
};

#endif // MENUWIDGET_H
