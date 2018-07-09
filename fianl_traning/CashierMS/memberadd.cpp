#include "memberadd.h"
#include "ui_memberadd.h"

MemberAdd::MemberAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberAdd)
{
    ui->setupUi(this);
}

MemberAdd::~MemberAdd()
{
    delete ui;
}
