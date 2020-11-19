#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>

namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = 0);
    ~ModifyWidget();

private:
    Ui::ModifyWidget *ui;

private slots:
    void on_btn_returnToMain_clicked();

signals:
    void display(int index);

};

#endif // MODIFYWIDGET_H
