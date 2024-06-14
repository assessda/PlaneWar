#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "herobullet.h"
#include "enemyplane.h"
#include "config.h"
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class mainscene; }
QT_END_NAMESPACE

class mainscene : public QWidget
{
    Q_OBJECT

public:
    mainscene(QWidget *parent = nullptr);
    ~mainscene();
    //初始化场景
    void initScene();
    //开始游戏
    void playGame();
    //刷新坐标
    void updatePosition();
    //绘制图像
    void paintEvent(QPaintEvent*);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent* ev);
    //敌机出场
    void enemyToScene();
    //碰撞检测
    void cillisionDetection();
    //键盘事件
    void keyPressEvent(QKeyEvent*);

public:
    //定时器
    QTimer m_Timer;
    //地图对象
    Map m_map;
    //飞机对象
    HeroPlane m_plane;
    //敌机数组
    EnemyPlane m_enemyPlane[ENEMY_NUM];

    //场景标记
    int m_sceneFlag;

    //敌机出场时间间隔记录标记
    int m_enemyRecorder;
    //除了刷新图像，其他延时标记
    int m_otherRecorder;
    //声音
    QSound* m_sound;
    //声音路径
    QString m_soundPath;
    //游戏暂停标记
    bool m_pause;
private:
    Ui::mainscene *ui;
};
#endif // MAINSCENE_H
