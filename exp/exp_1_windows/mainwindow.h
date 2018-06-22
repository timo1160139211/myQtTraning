#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QPushButton *m_pLoginBt;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void login();
};

#endif // MAINWINDOW_H
