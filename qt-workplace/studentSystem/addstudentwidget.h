#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>

namespace Ui {
class AddStudentWidget;
}

class AddStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWidget(QWidget *parent = 0);
    ~AddStudentWidget();

private:
    Ui::AddStudentWidget *ui;
};

#endif // ADDSTUDENTWIDGET_H
