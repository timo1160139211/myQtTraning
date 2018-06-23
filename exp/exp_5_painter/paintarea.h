#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QPainter>
class PaintArea : public QWidget
{
    Q_OBJECT

public:
enum Shape
 {Line,Rectangle,RoundRect,Ellipse,Polygon,Polyline,Points,Arc,Path,Text,Pixmap};

public:
    void setShape(Shape s){
        shape = s;
        update();
    }

    void setPen(QPen p){
        pen = p;
        update();
    }

    void setBrush(QBrush b){
        brush= b;
        update();
    }

    void paintEvent(QPaintEvent *){
        QPainter p(this);
        p.setPen(pen);
        p.setBrush(brush);
        QRect rect(50,100,300,200);
        static const QPoint points[4] = {
            QPoint(150,100),
            QPoint(300,150),
            QPoint(350,250),
            QPoint(100,300)
        };

        int startAngle = 30 * 16;
        int spanAngle = 120 * 16;

        QPainterPath path;
        path.addRect(150,150,100,100);
        path.moveTo(100,100);
        path.cubicTo(300,100,200,200,300,300);
        path.cubicTo(100,300,200,200,100,100);

        switch(shape)
        {
            case Line:
                p.drawLine(rect.topLeft(),rect.bottomRight());
                break;
            case Rectangle:
                p.drawRect(rect);
                break;
            case RoundRect:
                p.drawRoundRect(rect);
                break;
            case Ellipse:
                p.drawEllipse(rect);
                break;
            case Polygon:
                p.drawPolygon(points,4);
                break;
            case Polyline:
                p.drawPolyline(points,4);
                break;
            case Points:
                p.drawPoints(points,4);
                break;
            case Arc:
                p.drawArc(rect,startAngle,spanAngle);
                break;
            case Path:
                p.drawPath(path);
                break;
            case Text:
                p.drawText(rect,Qt::AlignCenter,tr("Hello Qt"));
                break;
            default:
                break;
        }
    }

private:
    Shape shape;
    QBrush brush;
    QPen pen;

public:
    explicit PaintArea(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PAINTAREA_H
