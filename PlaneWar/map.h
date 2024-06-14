#ifndef MAP_H
#define MAP_H

#include <QPixmap>


class Map
{
public:
    //构造函数
    Map();
    //地图滚动计算
    void mapPosition();
public:
    //地图
    QPixmap m_map1;
    QPixmap m_map2;

    //地图Y坐标
    int m_map1_posY;
    int m_map2_posY;

    //地图滚动幅度
    int m_scroll_speed;

    //地图滚动延时标记
    int m_speed_Recorder;
    int m_speed_RecorderMax;
};

#endif // MAP_H
