#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    m_pLabel = new QLabel("login window",this);
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
