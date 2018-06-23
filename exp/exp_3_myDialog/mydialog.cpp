#include "mydialog.h"
#include "ui_mydialog.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QInputDialog>
#include <QErrorMessage>
#include <QFontDialog>
#include <QProgressDialog>
#include <QCoreApplication>




MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_colorBtn_clicked()
{
    QColorDialog *colorDialog = new QColorDialog;
    colorDialog->show();
}

void MyDialog::on_fileBtn_clicked()
{
    QFileDialog *fileDlg = new QFileDialog(this,"filedlg");
    if(fileDlg->exec() == QFileDialog::Accepted){
        QStringList name = fileDlg->selectedFiles();
        QMessageBox::information(this,tr("提示"),name[0]);
    }
}

void MyDialog::on_inputDialog_clicked()
{
    bool isOK;
    QString name = QInputDialog::getText(this,tr("用户名"),
                                         tr("请输入新名字"),
                                         QLineEdit::Normal,
                                         tr("正文"),
                                         &isOK);
    if(isOK && !name.isEmpty()){
        //QString str = "OK";
        QMessageBox::information(this,tr("提示"),name);
    }
}

void MyDialog::on_errorBtn_clicked()
{
    QErrorMessage * errorDlg=new QErrorMessage;
    errorDlg->setWindowTitle(QString("错误提示"));
    errorDlg->showMessage(QString("原油泄漏"));
    errorDlg->show();
}

void MyDialog::on_fontBtn_clicked()
{
    bool isOK;
    QFontDialog::getFont(&isOK, QFont( "Helvetica [Cronyx]", 10 ), this );
}

void MyDialog::on_messageBtn_clicked()
{
    int ret = QMessageBox::information(this,QString("啊！"),QString("弹出一个迷路的消息对话框!"),QMessageBox::Ok);
    if(ret == QMessageBox::Ok){
        QString str = "OK";
        QMessageBox::information(this, tr("提示"), str);
    }
}

void MyDialog::on_progressBtn_clicked()
{
    QProgressDialog proDlg(QString("充电进度"),QString("取消"),0,90000,this);
    proDlg.setWindowTitle(QString("进度对话框"));
    proDlg.setWindowModality(Qt::WindowModal);//将对话框设置为模态
    proDlg.show();
    for(int i=0; i<90000; i++){   //演示复制进度
        proDlg.setValue(i);    //进度条的值
        QCoreApplication::processEvents(); //避免界面冻结
        if (proDlg.wasCanceled()) break; //按下取消按钮就中断
    }
    proDlg.setValue(90000);
}
