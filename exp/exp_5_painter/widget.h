#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "paintarea.h"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QColorDialog>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    PaintArea *paintArea;
    QComboBox *shapeComboBox;
    QFrame *colorFrame;
    QFrame *brushColorFrame;
    QSpinBox *widthSpinBox;

public slots:
    //修改形状槽函数
    void slotShape(int value)
    {
        PaintArea::Shape shape
            = PaintArea::Shape(shapeComboBox->itemData(value,Qt::UserRole).toInt());
        paintArea->setShape(shape);
    }
    //修改画笔槽函数
    void slotPenColor(){
        QColor color = QColorDialog::getColor(Qt::blue);
        colorFrame->setPalette(QPalette(color));
        int width = widthSpinBox->value();
        Qt::PenStyle style = Qt::SolidLine;
        Qt::PenCapStyle cap = Qt::RoundCap;
        Qt::PenJoinStyle join = Qt::RoundJoin;
        paintArea->setPen(QPen(color, width, style, cap, join));
    }
    //修改笔宽槽函数
    void slotPenWidth(int value){
        QColor color = colorFrame->palette().color(QPalette::Window);
        Qt::PenStyle style = Qt::SolidLine;
        Qt::PenCapStyle cap = Qt::RoundCap;
        Qt::PenJoinStyle join = Qt::RoundJoin;
        paintArea->setPen(QPen(color, value, style, cap, join));
    }
    //修改画刷槽函数
    void slotBrushColor(){
        QColor color = QColorDialog::getColor(Qt::blue);
        brushColorFrame->setPalette(QPalette(color));
        paintArea->setBrush(QBrush(color));
    }

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
