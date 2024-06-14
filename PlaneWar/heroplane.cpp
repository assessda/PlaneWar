#include "heroplane.h"


HeroPlane::HeroPlane()
{
    //加载飞机图片
    this->m_plane.load(PLANE_PATH);

    //初始化飞机位置
    this->m_planeX = (GAME_WIDTH - m_plane.width()) / 2;
    this->m_planeY = (GAME_HEIGHT - m_plane.height()) - 10;

    //飞机识别框
    this->m_rect.setWidth(PLANE_RECT_WIDTH);
    this->m_rect.setHeight(PLANE_RECT_HEIGHT);

    //初始化时间间隔标记
    this->m_recorder = 0;

    //初始化子弹发射间隔
    this->m_bullet_Interval = 160;

}

//发射子弹
void HeroPlane::shoot()
{
    //更新子弹坐标
    for(int i = 0; i < BULLET_INTERVAL; i++)
    {
        //判断子弹空闲状态
        if(m_bullets[i].m_free == false)
        {
            m_bullets[i].updateBulletPos();
        }
    }
    //时间间隔标记增加
    this->m_recorder++;
    //判断时间是否到达，否则直接退出
    if(this->m_recorder < this->m_bullet_Interval)
    {
        return;
    }
    //重置recorder标记
    this->m_recorder = 0;
    //发射子弹
    for(int i = 0; i < BULLET_NUM; i++)
    {
        //判断子弹空闲状态
        if(m_bullets[i].m_free == true)
        {
            //设置发射坐标
            m_bullets[i].setPosition(this->m_planeX +this->m_plane.width() / 2 - m_bullets[i].m_pix.width() / 2,\
                                     this->m_planeY - m_bullets[i].m_pix.height());
            m_bullets[i].m_free = false;
            break;
        }
    }
}
//设置飞机识别框的位置
void HeroPlane::setPosition()
{
    //让识别框跟着飞机变化
    this->m_rect.moveTo(m_planeX + m_plane.width() / 2 - m_rect.width() / 2, m_planeY + m_plane.height() / 2 - m_rect.height() / 2);
}
