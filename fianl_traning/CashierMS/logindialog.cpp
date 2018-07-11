#include "logindialog.h"
#include "usermodel.h"
#include <QMessageBox>
#include "ui_logindialog.h"
#include "connectionpool.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlTableModel>
#include "mainwindow.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setFixedSize(this->width(), this->height());//禁止最大化显示
    //ui->loginPushButton->setFlat(true);         //设置登录按钮状态为透明

    setWindowFlags(windowFlags()&~Qt::WindowCloseButtonHint&~Qt::WindowContextHelpButtonHint);//去掉登录框的问号


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_exitPushButton_clicked()
{
    this->close();
}

void LoginDialog::on_loginPushButton_clicked()
{
    // 从数据库连接池里取得连接
    QSqlDatabase db = ConnectionPool::openConnection();
        qDebug() << "is open:" << db.isOpen();
        qDebug() << "In thread run():" << db.connectionName();

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

        qDebug() << "username:" << username;
        qDebug() << "password:" << password;

    QSqlTableModel * model = new QSqlTableModel(this->parent(),db);
    model->setTable("user");
    model->setFilter(QObject::trUtf8("User_Name = '%1' and User_Pwd = '%2'").arg(username).arg(password));
    model->select();

        qDebug() << "err:" << model->lastError();
        qDebug() << "ddb:" << model->database();
//        qDebug() << "12 :" << model.data();
        qDebug() << "1 :" <<model->record() << model->record(0).value(1).toString() << model->record(1).value(2).toString();

    //将当前用户保存下来
    User *u = new User();
    u->username = model->record(0).value(1).toString();
    u->sex = model->record(0).value(2).toString();
    u->age = model->record(0).value(3).toString();
    u->password = model->record(0).value(4).toString();

    //设置当前登陆用户
    this->currentUser = u;

        qDebug() << u->toString();

    if(model->rowCount() == 1){

        MainWindow *mainWindow = new MainWindow();
        mainWindow->setUser(this->currentUser);
        mainWindow->show();
        this->close();

            qDebug() << "on_loginPushButton_clicked  login";
    }else{
        QMessageBox::information(this,QString("错误！"),QString("账号密码不正确!"),QMessageBox::Ok);
        ui->passwordLineEdit->clear();
            qDebug() << "on_loginPushButton_clicked  login error";
    }

    db.close();
}

