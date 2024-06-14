#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void updateBulletPos();
    //设置子弹坐标
    void setPosition(int x, int y);
    //获取子弹坐标
    int getX();
    int getY();
public:

    //资源图片
    QPixmap m_pix;
    //是否闲置
    bool m_free;
    //子弹碰撞检测矩形框
    QRect m_rect;
protected:
    //坐标
    int m_x;
    int m_y;
};

#endif // BULLET_H
