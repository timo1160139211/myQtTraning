#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cashierdialog.h"
#include "logindialog.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowCloseButtonHint&~Qt::WindowContextHelpButtonHint);//去掉登录框的问号

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logoutButton_clicked()
{
    this->close();
    LoginDialog* l = new LoginDialog;
    l->show();
}

void MainWindow::setUser(User *user){
    this->currentUser = user;

    //qDebug()<< user->toString();
    qDebug()<< "asdasda";
    ui->usernameLabel->setText(user->username);
}

/*********当用户点击右上角的X关闭程序时提醒用户是否保存数据后再关闭****************/
//void MainWindow::closeEvent(QCloseEvent *event)
//{
//    switch( QMessageBox::information(this, tr("退出"),
//                                     tr("是否保存?"),
//                                     tr("直接退出"), tr("取消退出"),tr("备份后退出"),
//                                     0, 1)){
//        case 0:
//           event->accept();
//            break;
//        case 1:
//        default:
//            event->ignore();
//            break;
//    }
//}

/*******************将系统时间显示在状态栏上*******************/
//void MainWindow::showtime_slot()
//{
//    QDateTime time = QDateTime::currentDateTime();
//    QString str= time.toString("yyyy-MM-dd hh:mm:ss dddd");
//    ui datatimelabel->setText(str);
//}

void MainWindow::on_toCashierButton_clicked()
{

    CashierDialog *cashierdialog = new CashierDialog();
    cashierdialog->show();
    this->close();
}
