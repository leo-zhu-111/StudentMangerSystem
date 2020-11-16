#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "config.h"
#include<QIcon>
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();

    void initScene();
};

#endif // MAINSCENE_H
