#ifndef CASHIERDIALOG_H
#define CASHIERDIALOG_H

#include <QDialog>
#include "usermodel.h"
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql>
#include <QTableView>

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
    User *currentUser;//当前用户
    void setUser(User *);

    QSqlTableModel *model;
//    QTableView *tableView;

private slots:
    void on_searchGoodPushButton_clicked();

private:



    Ui::CashierDialog *ui;
};

#endif // CASHIERDIALOG_H
