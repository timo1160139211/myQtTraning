#include "widget.h"
#include "ui_widget.h"
#include "paintarea.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    //设置主窗口大小
    this->resize(700,400);

    QLabel * SharpLabel = new QLabel("形状:",this);
    shapeComboBox = new QComboBox(this);
    SharpLabel->setGeometry(430,20,60,40);
    shapeComboBox->setGeometry(500,20,150,40);
    shapeComboBox->addItem("Line",PaintArea::Line);
    shapeComboBox->addItem("Rectangle",PaintArea::Rectangle);
    shapeComboBox->addItem("RoundRect",PaintArea::RoundRect);
    shapeComboBox->addItem("Ellipse", PaintArea::Ellipse);
    shapeComboBox->addItem("Path", PaintArea::Path);
    shapeComboBox->addItem("Polyline", PaintArea::Polyline);
    shapeComboBox->addItem("Arc", PaintArea::Arc);
    shapeComboBox->addItem("Points", PaintArea::Points);
    shapeComboBox->addItem("Text", PaintArea::Text);

    QLabel * PenColorLabel = new QLabel("画笔颜色:",this);
    PenColorLabel->setGeometry(430,90,60,40);
    colorFrame = new QFrame(this);
    colorFrame->setGeometry(500,90,150,40);
    colorFrame->setAutoFillBackground(true);
    colorFrame->setPalette(QPalette(Qt::blue));
    QPushButton *colorPushButton = new QPushButton("修改",this);
    colorPushButton->setGeometry(650,90,50,40);

    QLabel * BrushColorLabel = new QLabel("画刷颜色:",this);
    BrushColorLabel->setGeometry(430,160,60,40);
    brushColorFrame = new QFrame(this);
    brushColorFrame->setGeometry(500,160,150,40);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::blue));
    QPushButton *brushcolorPushButton = new QPushButton("修改",this);
    brushcolorPushButton->setGeometry(650,160,50,40);

    QLabel * LineWidthLabel = new QLabel("线宽:",this);
    LineWidthLabel->setGeometry(430,250,60,40);
    widthSpinBox = new QSpinBox(this);
    widthSpinBox->setGeometry(500,250,60,40);
    widthSpinBox->setRange(0,20);


    connect(shapeComboBox,SIGNAL(activated(int)),this,SLOT(slotShape(int)));
    connect(colorPushButton,SIGNAL(clicked()),this,SLOT(slotPenColor()));
    connect(brushcolorPushButton,SIGNAL(clicked()),this,SLOT(slotBrushColor()));
    connect(widthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(slotPenWidth(int)));

    paintArea = new PaintArea(this);
        //设置绘图区域窗口大小及位置
        paintArea->setGeometry(0,0,400,400);

    ui->setupUi(this);
}




Widget::~Widget()
{
    delete ui;
}
