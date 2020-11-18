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
};

#endif // MODIFYWIDGET_H
