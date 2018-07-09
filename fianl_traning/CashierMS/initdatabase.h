#ifndef ESTABLISHDATABASE_H
#define ESTABLISHDATABASE_H
#include <QSqlDatabase>
#include <QtSql>
#include <QObject>
#include "connectionpool.h"

/*初始化数据库*/
static bool initalDatabase()
{


    QSqlDatabase db = ConnectionPool::openConnection();


    QSqlQuery* query = new QSqlQuery("init_sql",db);
    /***************************员  工  表 *****************************/
    query->exec(QObject::trUtf8("create table user(User_Id integer primary key AUTOINCREMENT,"
                           "User_Name vchar(100) ,User_Sex vchar(10),"
                           "User_Age vchar(100),User_Pwd vchar(20))"));
    query->exec(QObject::trUtf8("insert into user values (999,'admin 超级管理员','男','20','admin')"));
    query->exec(QObject::trUtf8("insert into user values (1001,'小张 管理员','女','22','1001')"));

    /**********************会 员 卡 信 息 表********************/
    query->exec(QObject::trUtf8("create table member(Member_Id integer primary key AUTOINCREMENT,"
                           "Member_Name vchar(10),Member_Phone vchar(20),"
                           "Member_Address vchar(100),Member_Class vchar(10),"
                           "Member_Grade vchar(20) ,Member_Cost vchar(20),"
                           "Member_Register vchar(20),Member_Birthday vchar(20),"
                           "Member_Email vchar(20),Member_Remark vchar(500))"));
    query->exec(QObject::trUtf8("insert into member values (100001,'张楠','15383463513',"
                           "'山西省太原市尖草坪区太原工业学院','普通级','300','350',"
                           "'2014-08-20','1992-01-01','Zhang@163.com','null')"));
    query->exec(QObject::trUtf8("insert into member values (100002,'李棋','15383465641',"
                           "'山西省太原市尖草坪区太原工业学院','尊贵级','3000','10000',"
                           "'2014-06-20','1992-11-24','creazylq@163.com','null')"));
    query->exec(QObject::trUtf8("insert into member values (100004,'张泽军','15388511234',"
                           "'山西省太原市尖草坪区太原工业学院','普通级','440','500',"
                           "'2013-06-20','1991-1-4','zhangzj@163.com','null')"));
    query->exec(QObject::trUtf8("insert into member values (100006,'梅翔','15388513945',"
                           "'山西省太原市尖草坪区太原工业学院','尊贵级','1000','1200',"
                           "'2011-04-12','1992-4-12','meixiang@163.com','null')"));
    query->exec(QObject::trUtf8("insert into member values (100008,'马恩东','15388513920',"
                           "'山西省太原市尖草坪区太原工业学院','普通级','500','700',"
                           "'2001-06-20','1991-3-2','maendong@163.com','null')"));
    query->exec(QObject::trUtf8("insert into member values (100005,'谷忠新','15388510110',"
                           "'山西省太原市尖草坪区太原工业学院','普通级','500','700',"
                           "'2014-09-10','1991-8-2','guzhongxin@163.com','null')"));

    /**********************商 品 信 息 表*********************************/
    query->exec(QObject::trUtf8("create table Goods(Goods_Id int(10) primary key,Goods_Categories vchar(10),"
                           "Goods_Brand vchar(10),Goods_Name vchar(10),"
                           "Goods_Type vchar(10),Goods_Color vchar(10),"
                           "Goods_Num int(20),Goods_Units vchar(10),"
                           "Goods_Seal_Price int(10),Goods_Sum int(20),"
                           "Goods_Bid_Price int(20),Goods_Total int(20))"));
    query->exec(QObject::trUtf8("insert into Goods values (8000001,'烟','香烟','中华','1x1','红色',100,'包',20,2000,5,500)"));
    query->exec(QObject::trUtf8("insert into Goods values (8000002,'酒','汾酒','1x1','无色',10,'瓶',100,1000,50,500)"));

    /*******************************商品销售表**********************************/
    query->exec(QObject::trUtf8("create table Seals(Seal_Id int primary key,Seal_Name vchar(10),"
                           "Seal_Type vchar(10),Seal_Color vchar(10),"
                           "Seal_Price int,Seal_Discount int,"
                           "Seal_Discount_price int,Seal_num int,"
                           "Seal_Unit vchar(10),Seal_Total_price int,"
                           "Seal_Remark vchar(100),Seal_System_Remark vchar(200))"));

    /**********************供 货 商 表************************************/
    query->exec(QObject::trUtf8("create table Supplier(Supplier_Name vchar(50) primary key,"
                           "Supplier_Person_Name vchar(10),Supplier_Address vchar(10),"
                           "Supplier_Phone int,Supplier_Email vchar(20))"));
    query->exec(QObject::trUtf8("insert into Supplier values(12000001,'太原佳乐食品有限责任公司','山西省太原市五一路',15299483232,'Jl@gress.com')"));
    query->exec(QObject::trUtf8("insert into Supplier values(12000002,'北京爱美制造厂','北京市海淀区',13233243456,'bjam@163.com')"));

    /***********************生产厂商表*******************************/
    query->exec(QObject::trUtf8("create table producter(Producter_Name vchar(40) primary key,"
                           "Producter_Address vchar(40),Producter_Phone vchar(20))"));


    /**************************商品颜色表********************************/
    query->exec(QObject::trUtf8("create table color(Color_Kind vchar(10) primary key)"));
    query->exec(QObject::trUtf8("insert into color values ('透明')"));
    query->exec(QObject::trUtf8("insert into color values ('红色')"));
    query->exec(QObject::trUtf8("insert into color values ('橙色')"));
    query->exec(QObject::trUtf8("insert into color values ('黄色')"));
    query->exec(QObject::trUtf8("insert into color values ('绿色')"));
    query->exec(QObject::trUtf8("insert into color values ('蓝色')"));
    query->exec(QObject::trUtf8("insert into color values ('靛色')"));
    query->exec(QObject::trUtf8("insert into color values ('紫色')"));

    /**********************商品类别表**********************/
    query->exec(QObject::trUtf8("create table G_Type(Type_d int primary key,Type_Name vchar(4))"));
    query->exec(QObject::trUtf8("insert into G_Type values (1,'日化类')"));

    /******************************VIP折扣表***********************************/
    query->exec(QObject::trUtf8("create table Vip(Vip_Id int PRIMARY KEY,Vip_Name vchar(4)),"
                           "Vip_Discount vchar(10)"));
    return true;
}
#endif // ESTABLISHDATABASE_H
