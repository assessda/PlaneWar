#include "bomb.h"

Bomb::Bomb()
{
    //初始化坐标
    this->m_x = 0;
    this->m_y = 0;
    //初始化空闲状态
    this->m_free = true;
    //初始化图片下标
    this->m_index = 0;
    //初始化爆炸图片间隔时间
    this->m_bombInterval = 50;
    //初始化图片最大索引
    this->m_bombPixMax = 7;
    //加入声音路径
    this->m_soundPath = ":/Sound/Sound/bomb.wav";

    //初始化资源
    this->initResource();
}


//资源的添加
void Bomb::initResource()
{
    //添加资源图片
    this->m_bombPath = ":/Image/Image/bomb-%1.png";
    for(int i = 0; i < this->m_bombPixMax; i++)
    {
        QString str = QString(m_bombPath).arg(i);
        this->m_arr.push_back(QPixmap(str));
    }
    //添加声音
    this->m_bombSound = new QSound(m_soundPath);
}

//数据更新
void Bomb::updateInfo()
{
    //如果空闲return
    if(m_free == true)
    {
        return;
    }

    m_bombRecorder++;
    if(m_bombRecorder < m_bombInterval)
    {
        return;
    }
    m_bombRecorder = 0;

    //切换播放动画
    m_index++;
    //如果大于最大值 重置
    if(m_index >= m_bombPixMax)
    {
        m_index = 0;
        //播放完毕
        m_free = true;
    }
}
