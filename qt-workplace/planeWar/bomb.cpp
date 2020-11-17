#include "bomb.h"

Bomb::Bomb()
{
    //初始化爆炸图片数组
    for(int i=1;i<=BOMB_MAX;++i)
    {
        //字符串拼接，类似：“:/res/bomb-1.png”
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //初始化坐标
    m_X = 0;
    m_Y = 0;

    //初始化空闲状态
    m_Free = true;

    //当前播放图片下标
    m_Index = 0;

    //爆炸间隔记录
    m_Recorder = 0;

}
//更新信息（播放图片下标，播放间隔）
void Bomb::updateInfo()
{
    //空闲状态
    if(m_Free)
    {
        return;
    }

    m_Recorder++;
    if(m_Recorder < BOMB_INTERVAL)
    {
        //记录爆炸间隔未到，直接return 不需要切图
        return;
    }

    //重置记录
    m_Recorder =0;
    //切换爆炸播放图片
    m_Index++;
    //注：数组的下标从0开始，最大为6
    //如果下标大于6，重置为0
    if(m_Index > BOMB_MAX-1)
    {
        m_Index = 0;
        m_Free = true;
    }
}
