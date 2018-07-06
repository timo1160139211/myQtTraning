#include "logindialog.h"
#include "ui_logindialog.h"

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
    accept();
}
