#include "paintarea.h"
#include <QPalette>

PaintArea::PaintArea(QWidget *parent) :
    QWidget(parent)
{

    //设置背景白色
        QPalette pal = palette();
        pal.setColor(QPalette::Background, Qt::white);
        setAutoFillBackground(true);
        setPalette(pal);
        shape = Line;
}



