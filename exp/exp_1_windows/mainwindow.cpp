#include "mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    //设置著窗口大小
    this->setGeometry(400,400,600,400);
    //创建按钮
    m_pLoginBt = new QPushButton("Login",this);
    //设置按钮相对于主窗口位置
    m_pLoginBt->setGeometry(300,250,80,60);

    connect(m_pLoginBt,SIGNAL(clicked(bool)),this,SLOT(login()));
}

MainWindow::~MainWindow(){
    
}

void MainWindow::login(){
    Login loginWindow;

    loginWindow.exec();
}
