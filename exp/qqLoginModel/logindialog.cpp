#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QString>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    QString USERNAME = tr("gaoyisheng");
    QString PWD = tr("123456");

    QString input_username = ui->userNameLineEdit->text().trimmed();
    QString input_pwd = ui->pwdLineEdit->text().trimmed();

    if(USERNAME == input_username && PWD == input_pwd){
        accept();
    }else{
        //如果不对，显示警告信息
        QMessageBox::warning(this,tr("坏了！"),
                             tr("账号密码不对！-> gys 16"),
                             QMessageBox::Yes);

        //清空内容，定位光标。
        ui->userNameLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->userNameLineEdit->setFocus();
    }

}
