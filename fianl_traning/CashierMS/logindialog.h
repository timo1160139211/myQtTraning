#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "usermodel.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    
    User* getCurrentUser(){
        return currentUser;
    }
    User *currentUser;//当前用户

private slots:
    void on_exitPushButton_clicked();

    void on_loginPushButton_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
