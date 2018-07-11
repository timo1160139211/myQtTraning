#ifndef CASHIERDIALOG_H
#define CASHIERDIALOG_H

#include <QDialog>
#include "usermodel.h"
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql>
#include <QTableView>
#include <QStandardItemModel>
#include "logindialog.h"
namespace Ui {
class CashierDialog;
}

class CashierDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CashierDialog(QWidget *parent = 0);
    CashierDialog(int i, User * u);
    ~CashierDialog();
    

    void show_Goods_infor();
    User *currentUser;//当前用户
    void setUser(User *);

    QStandardItemModel *model;
//    QTableView *tableView;
    QSqlDatabase currentDBConnection;

private slots:
    void on_searchGoodPushButton_clicked();

    void on_moneyInLineEdit_textChanged(const QString &arg1);

    void on_settlementPushButton_clicked();

    void on_pushButton_clicked();

    void on_exitSystemButton_clicked();

    void on_pushButton_2_clicked();

private:



    Ui::CashierDialog *ui;
};

#endif // CASHIERDIALOG_H
