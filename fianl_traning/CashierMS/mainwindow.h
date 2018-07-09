#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usermodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void closeEvent( QCloseEvent * event );//当用户关闭窗口时提醒用户是否关闭

    User *currentUser;//当前用户
    void setUser(User *);

private slots:
    void on_logoutButton_clicked();

    void on_toCashierButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
