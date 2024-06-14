#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>
#include "bomb.h"

class EnemyPlane
{
public:
    EnemyPlane();

    //更新敌机坐标
    void updateBulletPos();
    //设置敌机坐标
    void setPosition(int x, int y);
    //爆炸函数
    void isBomb();
public:

    //敌机坐标
    int m_x;
    int m_y;

    //血量
    int m_hp;

    //资源图片
    QPixmap m_pix;

    //敌机碰撞检测矩形框
    QRect m_rect;

    //是否闲置
    bool m_free;

    //敌机移动像素
    int m_pxSpeed;

    //敌机出现速度
    int m_enemyRecorder;
    int m_enemyRecorderMax;

    //死亡标记
    bool m_isDied;

    //爆炸动画
    Bomb m_bomb;
};

#endif // ENEMYPLANE_H
