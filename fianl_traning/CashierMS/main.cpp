#include "mainwindow.h"
#include "logindialog.h"
#include "cashierdialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

void createDB()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("music.db");     //创建数据库
    if(!db.open())
    {
        qDebug()<< "database is error";
        //return;
    }
    else
    {
        qDebug()<<"database is ok";
        //return;
    }
    QSqlQuery query(db);
         bool bsuccess =
                 query.exec("create table person (id int primary key, "
                    "firstname varchar(20), lastname varchar(20))");   //创建一个表
         query.exec("insert into person values(101, 'Danny', 'Young')");
         query.exec("insert into person values(102, 'Christine', 'Holand')");
         query.exec("insert into person values(103, 'Lars', 'Gordon')");
         query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
         query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");
    if(!bsuccess)
    {
        qDebug()<< "table is error";
    }
    else
    {
        qDebug()<<"table is ok";

    }
    //query.exec("INSERT INTO persons VALUES ('xue','chao','langfang')");
    //db.close();

}

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


    createDB();

    return a.exec();
}


