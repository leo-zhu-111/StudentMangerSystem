#include "mainscene.h"
#include"bullet.h"

#include<ctime>
#include <QSound>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{


    //初始化场景
    this->initScene();

    //开始游戏
    this->playGame();

    //初始化敌机间隔记录
    m_recorder = 0;

}

MainScene::~MainScene()
{

}

void MainScene::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置图标资源
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    //随机数种子
    srand((unsigned int)time(NULL));

}

//启动游戏  用于启动定时器对象
void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){

        //敌机出场
        enemyToScene();

        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
        //碰撞检测
        this->collisionDetection();
    });

    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);
}

//更新坐标
void MainScene::updatePosition()
{
    m_map.mapPosition();

    //测试代码
   // tmp_bullet.m_Free = false;
   // tmp_bullet.updatePosition();

    //发射子弹
    m_hero.shoot();
    //计算子弹坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_Bullets[i].m_Free)
        {
            m_hero.m_Bullets[i].updatePosition();
        }
    }

    //计算敌机坐标
    for(int i=0;i<ENEMY_NUM;++i)
    {
        //非空闲的敌机，更新坐标
        if(!m_enemys[i].m_Free)
        {
            m_enemys[i].updatePosition();
        }
    }

    //计算爆发播放的图片
    for(int i=0;i<BOMB_NUM;++i)
    {
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();
        }
    }
}

//绘图事件
void MainScene::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //测试代码
    //painter.drawPixmap(tmp_bullet.m_X,tmp_bullet.m_Y,tmp_bullet.m_Bullet);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;++i)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_Bullets[i].m_Free)
        {
            painter.drawPixmap(m_hero.m_Bullets[i].m_X,m_hero.m_Bullets[i].m_Y,m_hero.m_Bullets[i].m_Bullet);
        }
    }

    //绘制敌机
    for(int i=0;i<ENEMY_NUM;++i)
    {
        if(!m_enemys[i].m_Free)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //绘制爆炸图片
    for(int i=0;i<BOMB_NUM;++i)
    {
        if(m_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_Index]);
        }
    }
}

//鼠标移动事件
void MainScene::mouseMoveEvent(QMouseEvent *event)
{

    int x = event->x() - m_hero.m_Rect.width() *0.5;
    int y = event->y() - m_hero.m_Rect.height() *0.5;

    //边界检测
    if(x <= 0)
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0 )
    {
        y = 0;
    }
    if( y >= GAME_HIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HIGHT - m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

//敌机出场
void MainScene::enemyToScene()
{
    m_recorder++;
    //如果没到时间间隔，直接退出
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }

    //到了时间间隔，重置
    m_recorder =0;
    for(int i=0;i<ENEMY_NUM;++i)
    {
        //如果数组中敌机为空闲状态可以使用敌机
        if(m_enemys[i].m_Free)
        {
            //敌机状态改为忙碌
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }


}

//碰撞检测
void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i=0;i<ENEMY_NUM;++i)
    {
        if(m_enemys[i].m_Free)
        {
            //如果敌机空闲 直接跳转下一循环
            continue;
        }

        //遍历所有 非空闲子弹
        for(int j=0;j<BULLET_NUM;++j)
        {
            if(m_hero.m_Bullets[i].m_Free)
            {
                //空闲子弹，跳转下一次循环
                continue;
            }

            //如果子弹和敌机的矩形框，发生碰撞，同时变成空闲状态
            if(m_enemys[i].m_Rect.intersects(m_hero.m_Bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_Bullets[j].m_Free = true;

                //播放爆炸效果
                for(int k =0;k<BOMB_NUM;++k)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //爆炸状态设置为非空闲
                        m_bombs[k].m_Free=false;
                        //更新坐标
                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        //播放音效
                        QSound::play(SOUND_BOMB);
                        break;
                    }
                }
            }
        }
    }
}

