#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    
private slots:
    void on_colorBtn_clicked();
    void on_fileBtn_clicked();

    void on_inputDialog_clicked();

    void on_errorBtn_clicked();

    void on_fontBtn_clicked();

    void on_messageBtn_clicked();

    void on_progressBtn_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
