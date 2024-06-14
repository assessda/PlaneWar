#include "bullet.h"
#include "config.h"

Bullet::Bullet()
{
    //加载资源
    this->m_pix.load(BULLET_PATH);
    //碰撞检测矩形框的设置
    this->m_rect.setSize(QSize(this->m_pix.width(),this->m_pix.height()));
    //子弹闲置标志 默认true
    this->m_free = true;
}

//更新子弹坐标
void Bullet::updateBulletPos()
{
    if(this->m_free == true)
    {
        return;
    }
    //子弹越界
    if(this->m_x < -this->m_pix.width() || this->m_x > GAME_WIDTH + this->m_pix.width() || \
       this->m_y < 0 || this->m_y > GAME_HEIGHT +this->m_pix.height())
    {
        this->m_free = true;
    }
}

//设置子弹坐标
void Bullet::setPosition(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
    //碰撞检测矩形框位置移动
    this->m_rect.moveTo(this->m_x, this->m_y);
}
//获取子弹坐标
int Bullet::getX()
{
    return this->m_x;
}
int Bullet::getY()
{
    return this->m_y;
}
