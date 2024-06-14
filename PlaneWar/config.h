#ifndef CONFIG_H
#define CONFIG_H
/******************* 游戏配置 *********************/
#define GAME_WIDTH  512   //窗口宽度
#define GAME_HEIGHT  768  //窗口高度
#define GAME_TITLE  "飞机大战" //标题
#define GAME_RCC_PATH  "./plane.rcc" //资源文件的位置
#define GAME_TITILEICO_PATH  ":/Image/Image/app.ico"
#define GAME_TIMER_SPEED 2 //计时器的时间间隔

/******************* 地图配置 *********************/
#define MAP_PATH  ":/Image/Image/img_bg_level_1.jpg"
#define MAP_SCROLL_SPEED  1  //滚动速度 1px

/******************* 英雄飞机配置 *********************/
#define PLANE_PATH ":/Image/Image/hero2.png"
#define PLANE_RECT_WIDTH  50  //飞机识别框的宽
#define PLANE_RECT_HEIGHT  50  //飞机识别框的高

/******************* 子弹配置 *********************/
#define BULLET_PATH ":/Image/Image/bullet_11.png"
#define BULLET_SPEED 4    //子弹移动像素
#define BULLET_NUM 30    //子弹数量
#define BULLET_INTERVAL 30 //子弹发射的时间间隔

/******************* 敌机配置数据 *********************/
#define ENEMY_PATH ":/Image/Image/img-plane_5.png" //敌机资源图片
#define ENEMY_SPEED 2 //敌机移动速度
#define ENEMY_NUM 10 //敌机总数量
#define ENEMY_INTERVAL 500 //敌机出场时间间隔

/******************* 声音配置路径 *********************/
#define BOMB ":/Sound/Sound/bomb.wav"

#endif // CONFIG_H
