#include "enemyplane.h"
#include"config.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源挂载
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    this->m_X = 0;
    this->m_Y =0;

    //敌机速度
    this->m_Speed = ENEMY_SPEED;

    //敌机状态
    this->m_Free = true;

    //敌机矩阵
    this->m_Rect.setWidth(this->m_enemy.width());
    this->m_Rect.setHeight(this->m_enemy.height());
    this->m_Rect.moveTo(this->m_X,this->m_Y);


}


//更新坐标
void EnemyPlane::updatePosition()
{
    //空闲状态不计算坐标
    if(this->m_Free)
    {
        return;
    }

    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y >= GAME_HIGHT)
    {
        m_Free = true;
    }
}
