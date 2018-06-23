#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // 以下部分解决中文乱码
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    // 以上部分解决中文乱码

    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
