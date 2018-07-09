#ifndef MEMBERADD_H
#define MEMBERADD_H

#include <QWidget>

namespace Ui {
class MemberAdd;
}

class MemberAdd : public QWidget
{
    Q_OBJECT
    
public:
    explicit MemberAdd(QWidget *parent = 0);
    ~MemberAdd();
    
private:
    Ui::MemberAdd *ui;
};

#endif // MEMBERADD_H
