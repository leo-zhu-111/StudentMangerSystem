#include "heroplane.h"

heroPlane::heroPlane()
{
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化坐标
    m_X = GAME_WIDTH*0.5 - m_Plane.width()*0.5;
    m_Y = GAME_HIGHT - m_Plane.height();

    //初始化矩形框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    //初始化发生间隔记录
    m_recorder = 0;
}

//发射子弹
void heroPlane::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    //达到发生时间处理
    //重置发生时间间隔记录
    m_recorder = 0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果是空闲的子弹进行发射
        if(m_Bullets[i].m_Free)
        {
            //将子弹空闲状态改为假
            m_Bullets[i].m_Free = false;
            //设置发射的子弹坐标
            m_Bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
            m_Bullets[i].m_Y = m_Y - 25;
            break;
        }
    }
}

//设置飞机位置
void heroPlane::setPosition(int x,int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(x,y);
}
