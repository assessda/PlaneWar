#include "map.h"
#include "config.h"


Map::Map()
{
    //加载地图
    this->m_map1.load(MAP_PATH);
    this->m_map2.load(MAP_PATH);

    //设置初始坐标
    this->m_map1_posY = 0;
    this->m_map2_posY = -GAME_HEIGHT;

    //设置滚动速度 1px
    this->m_scroll_speed = MAP_SCROLL_SPEED;

    //地图滚动延时标记
    m_speed_Recorder = 0;
    m_speed_RecorderMax = 5;
}


//地图滚动计算
void Map::mapPosition()
{
    //地图滚动延时标记
    m_speed_Recorder++;
    if(m_speed_Recorder < m_speed_RecorderMax)
    {
        return;
    }
    //重置
    m_speed_Recorder = 0;
    //地图滚动
    this->m_map1_posY += this->m_scroll_speed;
    this->m_map2_posY += this->m_scroll_speed;
    //判断图片超出范围， 两张图片往复切换
    if(this->m_map1_posY >= GAME_HEIGHT)
    {
        this->m_map1_posY = -GAME_HEIGHT;
    }
    if(this->m_map2_posY >= GAME_HEIGHT)
    {
        this->m_map2_posY = -GAME_HEIGHT;
    }


}
