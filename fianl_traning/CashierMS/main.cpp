#include "mainwindow.h"
#include "logindialog.h"
#include "cashierdialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDialog;
    MainWindow mainWindow;
    //CashierDialog cashierdialogWindow;
    loginDialog.show();

    //accepted则进入主界面
    if(loginDialog.exec() == QDialog::Accepted){
        mainWindow.show();
        //cashierdialogWindow.show();

    }
    else{
        return 0;
    }


    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("ms18753185820");
    if(!db.open()){
        qDebug()<<"Unable to open database";
    }else{
        qDebug()<<"Database connection established";
    }
    //db.exec("SET NAMES GBK");


    return a.exec();
}


