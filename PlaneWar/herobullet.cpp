#include "herobullet.h"
#include "config.h"

HeroBullet::HeroBullet()
{
    //设置子弹飞行速度
    this->m_pxSpeed = BULLET_SPEED;

    this->m_x = GAME_WIDTH / 2;
    this->m_y = GAME_HEIGHT / 2;

    //初始化子弹速度标记
    m_speedRecorder = 0;
    m_speddRecoederMax = 4;
}

//子弹移动轨迹
void HeroBullet::bulletMoveTrack()
{
    //子弹移动
    this->m_y -= m_pxSpeed;
    this->m_rect.moveTo(m_x,m_y);
}

//重写父类子弹更新
void HeroBullet::updateBulletPos()
{
    //子弹速度
    m_speedRecorder++;
    if(m_speedRecorder < m_speddRecoederMax)
    {
        return;
    }
    //重置
    m_speedRecorder = 0;
    //子弹移动
    this->bulletMoveTrack();
    //其他交给父类处理
    return Bullet::updateBulletPos();
}
