#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>

namespace Ui {
class SortWidget;
}

class SortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SortWidget(QWidget *parent = 0);
    ~SortWidget();

private:
    Ui::SortWidget *ui;
private slots:
    void on_btn_returnToMain_clicked();

signals:
    void display(int index);

};

#endif // SORTWIDGET_H
