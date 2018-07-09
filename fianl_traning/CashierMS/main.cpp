#include "mainwindow.h"
#include "logindialog.h"
#include "cashierdialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include "connectionpool.h"
#include "initdatabase.h"
#include <QTextCodec>
#include "usermodel.h"


int main(int argc, char *argv[])
{

    // 以下部分解决中文乱码
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    // 以上部分解决中文乱码


    QApplication a(argc, argv);
    LoginDialog loginDialog;
//    MainWindow mainWindow;
    //CashierDialog cashierdialogWindow;
    loginDialog.show();


    //初始化数据库
    //qDebug() << initalDatabase();

    //accepted则进入主界面
//    if(loginDialog.exec() == QDialog::Accepted){
//        User *currentUser = loginDialog.getCurrentUser();
//        qDebug()<< "srsr"<<loginDialog.getCurrentUser()->username;
//        qDebug()<< "srsr"<<loginDialog.getCurrentUser();

//        mainWindow.setUser(currentUser);
//        mainWindow.show();
//        //cashierdialogWindow.show();

//    }
//    else{
//        return 0;
//    }


    //释放所有连接
    ConnectionPool::release();
    return a.exec();
}


