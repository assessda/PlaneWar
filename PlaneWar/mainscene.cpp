#include "mainscene.h"
#include "ui_mainscene.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <ctime>
#include <QSound>

mainscene::mainscene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainscene)
{
    ui->setupUi(this);
    //初始化场景  加载数据
    initScene();
    //开始游戏
    //playGame();
}

mainscene::~mainscene()
{
    delete ui;
}
//初始化
void mainscene::initScene()
{
    //设置窗口大小
    this->setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    //设置标题
    this->setWindowTitle(GAME_TITLE);
    //设置图标
    this->setWindowIcon(QIcon(GAME_TITILEICO_PATH));
    //设置定时器
    m_Timer.setInterval(2);

    //加载声音路径
    m_soundPath = ":/Sound/Sound/bg2.wav";
    //初始化背景音乐
    m_sound = new QSound(m_soundPath);

    //触发鼠标移动事件（不需要点击） 默认 false
    setMouseTracking(true);

    //敌机出场时间间隔记录标记初始化
    m_enemyRecorder = 0;

    //除了刷新图像，其他延时  标记
    m_otherRecorder = 0;

    //初始化暂停标记
    m_pause = 0;

    //生成随机数种子
    srand((unsigned int)time(NULL));

    //场景标记
    m_sceneFlag = 0;
}
//开始游戏
void mainscene::playGame()
{
    //隐藏鼠标指针
    QWidget::setCursor(QCursor(Qt::BlankCursor));
    //启动定时器并监听
    m_Timer.start();
    //播放音乐
    m_sound->setLoops(-1);
    m_sound->play();
    connect(&m_Timer, &QTimer::timeout, [=](){
        //刷新图像
        update();
        //更新飞机
        m_plane.setPosition();
        //每隔一段时间刷新游戏数据
        updatePosition();

        if(m_pause == 1)
        {
            //如果暂停
            m_Timer.stop();
        }

        });
}
//刷新游戏数据
void mainscene::updatePosition()
{
    //地图更新
    m_map.mapPosition();
    //子弹更新
    m_plane.shoot();
    //敌机出现
    this->enemyToScene();
    //碰撞检测
    this->cillisionDetection();
}

//敌机出场
void mainscene::enemyToScene()
{
    //出现的敌机继续移动
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(m_enemyPlane[i].m_free == false)
        {
            if(m_enemyPlane[i].m_isDied == false)
            {
                m_enemyPlane[i].updateBulletPos();
            }
            //检测是否死亡
            m_enemyPlane[i].isBomb();
        }
    }


    //每隔一段时间，新敌机出场
    m_enemyRecorder++;
    if(m_enemyRecorder < ENEMY_INTERVAL)
    {
        return;
    }

    //敌机出现 一次只出一辆
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(m_enemyPlane[i].m_free == true)
        {
            m_enemyPlane[i].m_free = false;
            m_enemyPlane[i].setPosition(rand() % (GAME_WIDTH - m_enemyPlane[i].m_pix.width()), \
                                        -m_enemyPlane[i].m_pix.height());
            break;
        }
    }

    //重置recorder
    m_enemyRecorder = 0;
}

//碰撞检测
void mainscene::cillisionDetection()
{
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        //敌机不空闲并且没有死亡
        if(m_enemyPlane[i].m_free == false && m_enemyPlane[i].m_isDied == false)
        {
            for(int j = 0; j < BULLET_NUM; j++)
            {
                if(m_plane.m_bullets[j].m_free == false)
                {
                    if(m_enemyPlane[i].m_rect.intersects(m_plane.m_bullets[j].m_rect) == true)
                    {
                        //敌机死亡
                        //m_enemyPlane[i].m_free = true;
                        m_enemyPlane[i].m_isDied = true;
                        m_plane.m_bullets[j].m_free =true;

                        m_enemyPlane[i].m_bomb.m_bombSound->play();
                    }
                }
            }
        }
    }
}



//绘制图像
void mainscene::paintEvent(QPaintEvent*)
{


    //绘制游戏场景
    if(m_sceneFlag == 1)
    {
        QPainter painter(this);
        //绘制地图的两张图片
        painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
        painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);
        //绘制飞机
        painter.drawPixmap(m_plane.m_planeX, m_plane.m_planeY, m_plane.m_plane);
        /*****测试********/
        painter.setPen(QPen(QColor(255, 0, 0)));
        painter.drawRect(m_plane.m_rect);
        //绘制hero子弹
        for(int i = 0; i < BULLET_NUM; i++)
        {
            if(m_plane.m_bullets[i].m_free == false)
            {
                painter.drawPixmap(m_plane.m_bullets[i].getX(), m_plane.m_bullets[i].getY(), m_plane.m_bullets[i].m_pix);
                /*****测试********/
                painter.setPen(QPen(QColor(255, 0, 0)));
                painter.drawRect(m_plane.m_bullets[i].m_rect);
            }
        }

        //绘制敌机
        for(int i = 0; i < ENEMY_NUM; i++)
        {
            if(m_enemyPlane[i].m_free == false)
            {

                if(m_enemyPlane[i].m_isDied == false)
                {
                    painter.drawPixmap(m_enemyPlane[i].m_x, m_enemyPlane[i].m_y, m_enemyPlane[i].m_pix);
                }
                else
                {
                    //绘制爆炸动画
                    painter.drawPixmap(m_enemyPlane[i].m_x, m_enemyPlane[i].m_y, m_enemyPlane[i].m_bomb.m_arr[m_enemyPlane[i].m_bomb.m_index]);
                }

                /*****测试********/
                painter.setPen(QPen(QColor(255, 0, 0)));
                painter.drawRect(m_enemyPlane[i].m_rect);
            }
        }
    }


}

//鼠标移动事件
void mainscene::mouseMoveEvent(QMouseEvent* ev)
{
    //让飞机跟着鼠标移动
    m_plane.m_planeX = ev->x() - m_plane.m_plane.width() / 2;
    m_plane.m_planeY = ev->y() - m_plane.m_plane.height() / 2;
}

//键盘事件
void mainscene::keyPressEvent(QKeyEvent* ev)
{
    //按下空格键
    if(ev->key() == Qt::Key_Space)
    {
        //按空格开始游戏
        if(m_sceneFlag == 0)
        {
            m_sceneFlag = 1;
            playGame();
        }

        //游戏中暂停
        else if(m_sceneFlag == 1)
        {
            //空格暂停
            if(m_pause == 0)
            {
                m_pause = 1;
            }
            else
            {
                m_pause = 0;
                //重启定时器
                m_Timer.start();
            }
        }
    }







}
