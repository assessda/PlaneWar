#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    //加载图片
    this->m_pix.load(ENEMY_PATH);

    //初始化坐标
    this->m_x = 0;
    this->m_y = -m_pix.height();

    //初始化状态
    this->m_free = true;
    //初始化血量
    this->m_hp = 1;
    //死亡标记
    this->m_isDied = false;

    //初始化速度
    this->m_pxSpeed = ENEMY_SPEED;

    //初始化碰撞检测矩形框
    this->m_rect.setWidth(m_pix.width());
    this->m_rect.setHeight(m_pix.height());


    //初始化
    //敌机出现速度
    this->m_enemyRecorder = 0;
    this->m_enemyRecorderMax = 5;
}

//更新敌机坐标
void EnemyPlane::updateBulletPos()
{
    this->m_enemyRecorder++;
    if(this->m_enemyRecorder < this->m_enemyRecorderMax)
    {
        return;
    }
    this->m_enemyRecorder = 0;
    //空闲状态不计算坐标
    if(this->m_free == true)
    {
        return;
    }
    //向下移动
    this->m_y += this->m_pxSpeed;
    this->m_rect.moveTo(this->m_x, this->m_y);
    //重置越界敌机
    if(this->m_y > GAME_HEIGHT)
    {
        this->m_free = true;
    }
}

//设置敌机坐标
void EnemyPlane::setPosition(int x, int y)
{
    //设置敌机坐标
    this->m_x = x;
    this->m_y = y;
    //矩形框跟着坐标移动
    this->m_rect.moveTo(x, y);

}

//爆炸函数
void EnemyPlane::isBomb()
{
    //如果敌机死亡. 刷新数据
    if(this->m_isDied == true)
    {
        this->m_bomb.m_free = false;
        this->m_bomb.updateInfo();
        //爆炸动画播放完毕
        if(this->m_bomb.m_free == true)
        {
            //重置死亡状态
            this->m_free = true;
            this->m_isDied = false;

        }
    }

}
