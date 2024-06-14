#ifndef HEROPLANE_H
#define HEROPLANE_H

#include <QPixmap>
#include "herobullet.h"
#include "config.h"

class HeroPlane
{
public:
    //构造函数
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition();

public:
    //飞机的坐标
    int m_planeX;
    int m_planeY;
    //飞机图片
    QPixmap m_plane;
    //飞机矩形框
    QRect m_rect;
    //发射子弹的间隔记录标记
    int m_recorder;
    //子弹弹夹
    HeroBullet m_bullets[BULLET_NUM];
    //子弹发射间隔
    int m_bullet_Interval;

};

#endif // HEROPLANE_H
