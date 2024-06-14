#ifndef BOMB_H
#define BOMB_H

#include <QVector>
#include <QPixmap>
#include <QSound>

class Bomb
{
public:
    Bomb();
    //加载图片
    void initResource();
    //数据更新
    void updateInfo();

public:
    //爆炸位置
    int m_x;
    int m_y;

    //爆炸图片数组
    QVector<QPixmap> m_arr;
    //爆炸图片序号最大索引
    int m_bombPixMax;

    //爆炸状态
    bool m_free;

    //爆炸数组下标
    int m_index;

    //图片路径
    QString m_bombPath;

    //爆炸图片时间间隔标记
    int m_bombRecorder;
    //爆炸图片时间间隔
    int m_bombInterval;
    //爆炸音效
    QSound* m_bombSound;
    //音效路径
    QString m_soundPath;

};

#endif // BOMB_H
