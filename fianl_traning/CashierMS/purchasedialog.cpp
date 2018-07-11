#include "purchasedialog.h"
#include "ui_purchasedialog.h"
#include <QMessageBox>
PurchaseDialog::PurchaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PurchaseDialog)
{
    ui->setupUi(this);
}

PurchaseDialog::~PurchaseDialog()
{
    delete ui;
}
void PurchaseDialog::setUser(User *user){
    this->currentUser = user;
}

void PurchaseDialog::on_pushButton_clicked()
{

}

void PurchaseDialog::on_exitSystemButton_clicked()
{
    switch( QMessageBox::information(this, tr("退出"),
                                     tr("是否保存?"),
                                     tr("直接退出"), tr("取消退出"),tr("备份后退出"),
                                      0, 1)){
        case 0:
            this->close();
            break;
        case 1:
        default:
            break;
    }

}
