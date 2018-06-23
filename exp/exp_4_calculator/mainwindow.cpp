#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);


        //设置中心窗口
        QWidget *centerWindow = new QWidget;
        this->setCentralWidget(centerWindow);

        label1 = new QLabel("显示");
        label2 = new QLabel("结果");
        QHBoxLayout * h1 = new QHBoxLayout;
        h1->addWidget(label1);
        h1->addWidget(label2);
        label1->setMaximumHeight(15);
        label2->setMaximumHeight(15);
        h1->setStretch(0,2);
        h1->setStretch(1,1);

        showEdit = new QTextEdit;
        resultEdit = new QTextEdit;
        QHBoxLayout * h2 = new QHBoxLayout;
        h2->addWidget(showEdit);
        h2->addWidget(resultEdit);
        showEdit->setMaximumHeight(30);
        resultEdit->setMaximumHeight(30);
        showEdit->setReadOnly(true);
        resultEdit->setReadOnly(true);
        h2->setStretch(0,2);
        h2->setStretch(1,1);

        //第三行按钮
        backBt   = new QPushButton("Back");
        removeBt = new QPushButton("CE");
        clearBt  = new QPushButton("CLS");
        sumBt    = new QPushButton("+");
        backBt->setMinimumHeight(50);
        removeBt->setMinimumHeight(50);
        clearBt->setMinimumHeight(50);
        sumBt->setMinimumHeight(50);
        QHBoxLayout * h3 = new QHBoxLayout;
        h3->addWidget(backBt);
        h3->addWidget(removeBt);
        h3->addWidget(clearBt);
        h3->addWidget(sumBt);
        sevenBt = new QPushButton("7");
        eightBt = new QPushButton("8");
        nineBt  = new QPushButton("9");
        decBt   = new QPushButton("-");
        sevenBt->setMinimumHeight(50);
        eightBt->setMinimumHeight(50);
        nineBt->setMinimumHeight(50);
        decBt->setMinimumHeight(50);
        QHBoxLayout * h4 = new QHBoxLayout;
        h4->addWidget(sevenBt);
        h4->addWidget(eightBt);
        h4->addWidget(nineBt);
        h4->addWidget(decBt);

        fourBt = new QPushButton("4");
        fiveBt = new QPushButton("5");
        sixBt  = new QPushButton("6");
        starBt = new QPushButton("*");
        fourBt->setMinimumHeight(50);
        fiveBt->setMinimumHeight(50);
        sixBt->setMinimumHeight(50);
        starBt->setMinimumHeight(50);
        QHBoxLayout * h5 = new QHBoxLayout;
        h5->addWidget(fourBt);
        h5->addWidget(fiveBt);
        h5->addWidget(sixBt);
        h5->addWidget(starBt);

        oneBt    = new QPushButton("1");
        twoBt    = new QPushButton("2");
        threeBt  = new QPushButton("3");
        divBt    = new QPushButton("/");
        oneBt->setMinimumHeight(50);
        twoBt->setMinimumHeight(50);
        threeBt->setMinimumHeight(50);
        divBt->setMinimumHeight(50);
        QHBoxLayout * h6 = new QHBoxLayout;
        h6->addWidget(oneBt);
        h6->addWidget(twoBt);
        h6->addWidget(threeBt);
        h6->addWidget(divBt);

        _Bt      =  new QPushButton("+/-");
        zeroBt   =  new QPushButton("0");
        pointBt  =  new QPushButton(".");
        equalBt  =  new QPushButton("=");
        _Bt->setMinimumHeight(50);
        zeroBt->setMinimumHeight(50);
        pointBt->setMinimumHeight(50);
        equalBt->setMinimumHeight(50);
        QHBoxLayout * h7 = new QHBoxLayout;
        h7->addWidget(_Bt);
        h7->addWidget(zeroBt);
        h7->addWidget(pointBt);
        h7->addWidget(equalBt);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(h1);
        mainLayout->addLayout(h2);
        mainLayout->addLayout(h3);
        mainLayout->addLayout(h4);
        mainLayout->addLayout(h5);
        mainLayout->addLayout(h6);
        mainLayout->addLayout(h7);

        centerWindow->setLayout(mainLayout);




        //增加菜单栏选项
        action1 = new QAction("标准",this);
        action1->setShortcut(tr("alt+l"));
        action2 = new QAction("科学",this);
        action2->setShortcut(tr("alt+2"));
        action3 = new QAction("历史记录",this);
        action3->setShortcut(tr("alt+3"));
        action4 = new QAction("时间设置",this);
        action4->setShortcut(tr("alt+4"));
        action5 = new QAction("复制",this);
        action5->setShortcut(tr("ctrl+1"));
        action6 = new QAction("粘贴",this);
        action6->setShortcut(tr("ctrl+2"));
        action7 = new QAction("帮助",this);
        action7->setShortcut(tr("ctrl+3"));

        action8 = new QAction("关于",this);
        action8->setShortcut(tr("ctrl+4"));

        //增加菜单栏
        //menuBar = new QMenuBar();
        menu1 = new QMenu();
        menu1= ui->menuBar->addMenu(tr("选择"));
        menu1->addAction(action1);
        menu1->addAction(action2);
        //增加横线
        menu1->addSeparator();
        menu1->addAction(action3);
        menu1->addAction(action4);

        menu2 = new QMenu();
        menu2= ui->menuBar->addMenu("编辑");
        menu2->addAction(action5);
        menu2->addSeparator();
        menu2->addAction(action6);

        menu3 = new QMenu();
        menu3= ui->menuBar->addMenu("帮助");
        menu3->addAction(action7);
        menu3->addSeparator();
        menu3->addAction(action8);



}

MainWindow::~MainWindow()
{
    delete ui;
}


