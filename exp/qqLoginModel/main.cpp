#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
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
    MainWindow w;
    LoginDialog loginDialog;

    if(loginDialog.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }

}
