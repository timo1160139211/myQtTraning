#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public:
    Ui::MainWindow *ui;

public:
        //显示标签
        QLabel * label1;
        QLabel * label2;
        //文本编辑框
        QTextEdit * showEdit;
        QTextEdit * resultEdit;
        //按钮布局成员变量
        QPushButton * backBt;
        QPushButton * removeBt;
        QPushButton * clearBt;
        QPushButton * sumBt;

        QPushButton * sevenBt;
        QPushButton * eightBt;
        QPushButton * nineBt;
        QPushButton * decBt;

        QPushButton * fourBt;
        QPushButton * fiveBt;
        QPushButton * sixBt;
        QPushButton * starBt;

        QPushButton * oneBt;
        QPushButton * twoBt;
        QPushButton * threeBt;
        QPushButton * divBt;

        QPushButton * _Bt;  //+/-按钮
        QPushButton * zeroBt;
        QPushButton * pointBt;
        QPushButton * equalBt;

        QMenuBar * menuBar;

        QMenu * menu1;
        QMenu * menu2;
        QMenu * menu3;

        QAction *action1;
        QAction *action2;
        QAction *action3;
        QAction *action4;
        QAction *action5;
        QAction *action6;
        QAction *action7;
        QAction *action8;

};

#endif // MAINWINDOW_H
