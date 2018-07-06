#ifndef CASHIERDIALOG_H
#define CASHIERDIALOG_H

#include <QDialog>

#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
namespace Ui {
class CashierDialog;
}

class CashierDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CashierDialog(QWidget *parent = 0);
    ~CashierDialog();
    

    void show_Goods_infor();

    QSqlTableModel *model;

private:



    Ui::CashierDialog *ui;
};

#endif // CASHIERDIALOG_H
