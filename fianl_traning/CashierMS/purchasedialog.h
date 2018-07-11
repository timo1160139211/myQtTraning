#ifndef PURCHASEDIALOG_H
#define PURCHASEDIALOG_H

#include <QDialog>
#include "usermodel.h"

namespace Ui {
class PurchaseDialog;
}

class PurchaseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PurchaseDialog(QWidget *parent = 0);
    ~PurchaseDialog();

    User *currentUser;//当前用户

    void setUser(User *);

private slots:
    void on_pushButton_clicked();

    void on_exitSystemButton_clicked();

private:
    Ui::PurchaseDialog *ui;
};

#endif // PURCHASEDIALOG_H
