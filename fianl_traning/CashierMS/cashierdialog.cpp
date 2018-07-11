#include "cashierdialog.h"
#include "ui_cashierdialog.h"
#include "ConnectionPool.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QStandardItemModel>
#include <QDebug>
#include "mainwindow.h"

CashierDialog::CashierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashierDialog)
{
    ui->setupUi(this);

    this->currentDBConnection = ConnectionPool::openConnection();

    setFixedSize(this->width(), this->height());//禁止最大化显示

    //设置销售日期 为今天
    ui->sellDate->setCalendarPopup(true);
    QDate today = QDate::currentDate();
    //设置时间范围为前后一个月
    ui->sellDate->setDateRange(today.addDays(-30),today.addDays(30));

    ui->barcodeLineEdit->setFocus();

    //显示表头
    show_Goods_infor();

}

CashierDialog::CashierDialog(int i, User * u):
    QDialog(),
    ui(new Ui::CashierDialog)
{
    ui->setupUi(this);
    this->currentUser = u;
    this->currentDBConnection = ConnectionPool::openConnection();

    setFixedSize(this->width(), this->height());//禁止最大化显示

    //设置销售日期 为今天
    ui->sellDate->setCalendarPopup(true);
    QDate today = QDate::currentDate();
    //设置时间范围为前后一个月
    ui->sellDate->setDateRange(today.addDays(-30),today.addDays(30));

    //当前用户
    ui->cashierNameLineEdit->setText(this->currentUser->username);

    ui->barcodeLineEdit->setFocus();

    //显示表头
    show_Goods_infor();

}


CashierDialog::~CashierDialog()
{
    delete ui;
}

void CashierDialog::show_Goods_infor()
{
    // 从数据库连接池里取得连接
    qDebug() << "is open:" << this->currentDBConnection.isOpen();
    qDebug() << "In thread run():" << this->currentDBConnection.connectionName();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));//UTF-8 GBK


    this->model = new QStandardItemModel(ui->dataTableView);

    this->model->setHorizontalHeaderItem(0,new QStandardItem(trUtf8("商品条码")));
    this->model->setHorizontalHeaderItem(1,new QStandardItem(trUtf8("商品类型")));
    this->model->setHorizontalHeaderItem(2,new QStandardItem(trUtf8("品牌")));
    this->model->setHorizontalHeaderItem(3,new QStandardItem(trUtf8("名称")));
    this->model->setHorizontalHeaderItem(4,new QStandardItem(trUtf8("规格")));
    this->model->setHorizontalHeaderItem(5,new QStandardItem(trUtf8("颜色")));

    this->model->setHorizontalHeaderItem(6,new QStandardItem(trUtf8("单位")));
    this->model->setHorizontalHeaderItem(7,new QStandardItem(trUtf8("单价")));
    //this->model->setHorizontalHeaderItem(8,new QStandardItem(trUtf8("总金额")));
    this->model->setHorizontalHeaderItem(8,new QStandardItem(trUtf8("备注")));

    ui->dataTableView->setModel(model);
    ui->dataTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->dataTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->dataTableView->resizeColumnsToContents();
    ui->dataTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //释放连接，使其回归连接池
    this->currentDBConnection.close();
}

void CashierDialog::setUser(User *user){
    this->currentUser = user;
}

void CashierDialog::on_searchGoodPushButton_clicked()
{
    // 从数据库连接池里取得连接
    this->currentDBConnection = ConnectionPool::openConnection();

    int i = ui->barcodeLineEdit->text().toInt();

    QSqlQuery *query = new QSqlQuery(this->currentDBConnection);

    query->exec(QObject::trUtf8("select * from Goods where Goods_Id = '%1'").arg(i));

    //    ui->dataTableView;
    if(query->next()){

        int rowNum = model->rowCount();
        model->setItem(rowNum,0,new QStandardItem(query->value(0).toString()));
        model->setItem(rowNum,1,new QStandardItem(query->value(1).toString()));
        model->setItem(rowNum,2,new QStandardItem(query->value(2).toString()));
        model->setItem(rowNum,3,new QStandardItem(query->value(3).toString()));
        model->setItem(rowNum,4,new QStandardItem(query->value(4).toString()));
        model->setItem(rowNum,5,new QStandardItem(query->value(5).toString()));
        model->setItem(rowNum,6,new QStandardItem(query->value(7).toString()));//第六列 不要。故value往后选1
        model->setItem(rowNum,7,new QStandardItem(query->value(8).toString()));
        //model->setItem(rowNum,8,new QStandardItem(query->value(9).toString()));
        //model->setItem(rowNum,9,new QStandardItem(query->value(11).toString()));

        qDebug() << " model->columnCount()=" << model->columnCount();
        qDebug() << " model->rowCount()" << model->rowCount();
    }

    //计算 (总和=原来的+当前值)
    int totalPrice = ui->totalPriceEditLine->text().toInt() + query->value(8).toInt();
    //显示总和
    ui->totalPriceEditLine->setText(QString::number(totalPrice));

    this->currentDBConnection.close();
}

void CashierDialog::on_moneyInLineEdit_textChanged(const QString &arg1)
{
    //总价
    int total = ui->totalPriceEditLine->text().toInt();
    //实收
    int in = ui->moneyInLineEdit->text().toInt();
    //找零   实收-总价
    ui->moneyOutLineEdit->setText(QString::number(in - total));
}

void CashierDialog::on_settlementPushButton_clicked()
{
    this->model->clear();
    ui->barcodeLineEdit->clear();
    ui->totalPriceEditLine->clear();
    ui->moneyInLineEdit->clear();
    ui->moneyOutLineEdit->clear();
}

void CashierDialog::on_pushButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUser(this->currentUser);
    mainWindow->show();
    this->close();

}

void CashierDialog::on_exitSystemButton_clicked()
{
    switch( QMessageBox::information(this, tr("退出"),
                                     tr("是否保存?"),
                                     tr("直接退出"), tr("取消退出"),tr("备份后退出"),
                                      0, 1)){
        case 0:
            this->close();
            break;
        case 1:
        default:
            break;
    }

}

void CashierDialog::on_pushButton_2_clicked()
{   LoginDialog* l = new LoginDialog;
    l->show();
    this->close();

}
