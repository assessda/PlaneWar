#ifndef HEROBULLET_H
#define HEROBULLET_H
#include "bullet.h"

class HeroBullet : public Bullet
{
public:
    HeroBullet();
    //重写父类子弹更新
    void updateBulletPos();
    //子弹移动轨迹
    void bulletMoveTrack();
public:
    //子弹像素移动速度
    int m_pxSpeed;

    //子弹速度标记
    int m_speedRecorder;
    int m_speddRecoederMax;

};

#endif // HEROBULLET_H
