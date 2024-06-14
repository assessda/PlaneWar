#include "mainscene.h"

#include <QApplication>
#include <QResource>
//#include <windef.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource("./plane.rcc");
    mainscene w;
    w.show();

    RECT mainRect; //windef.h中被定义
    mainRect.left = (LONG)w.geometry().left();
    mainRect.right = (LONG)w.geometry().right();
    mainRect.top = (LONG)w.geometry().top() - 10;
    mainRect.bottom = (LONG)w.geometry().bottom();
    ClipCursor(&mainRect);

    return a.exec();
}
