#include "mainwindow.h"
#include "logindialog.h"
#include "cashierdialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDialog;
    MainWindow mainWindow;
    CashierDialog cashierdialogWindow;
    loginDialog.show();

    //accepted则进入主界面
    if(loginDialog.exec() == QDialog::Accepted){
        mainWindow.show();
        cashierdialogWindow.show();

    }
    else{
        return 0;
    }



    return a.exec();
}


