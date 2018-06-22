#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT
    
public:
    QLabel *m_pLabel;
public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
