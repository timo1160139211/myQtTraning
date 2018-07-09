#include "cashierdialog.h"
#include "ui_cashierdialog.h"
#include "ConnectionPool.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>

CashierDialog::CashierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashierDialog)
{
    ui->setupUi(this);
    show_Goods_infor();

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

CashierDialog::~CashierDialog()
{
    delete ui;
}

//为什么不显示    必须在model的构造函数里 加上db
void CashierDialog::show_Goods_infor()
{

    // 从数据库连接池里取得连接
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "is open:" << db.isOpen();
    qDebug() << "In thread run():" << db.connectionName();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));//UTF-8 GBK

    this->model = new QSqlTableModel(this->parent(),db);
//    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("Goods");
    model->setSort(1, Qt::AscendingOrder);

    model->setHeaderData(0,Qt::Horizontal,trUtf8("商品条码"));
    model->setHeaderData(1,Qt::Horizontal,trUtf8("商品名称"));
    model->setHeaderData(2,Qt::Horizontal,trUtf8("规格型号"));
    model->setHeaderData(3,Qt::Horizontal,trUtf8("颜色"));
    model->setHeaderData(4,Qt::Horizontal,trUtf8("销售价"));
    model->setHeaderData(5,Qt::Horizontal,trUtf8("折扣"));
    model->setHeaderData(6,Qt::Horizontal,trUtf8("折后单价"));
    model->setHeaderData(7,Qt::Horizontal,trUtf8("销售数"));
    model->setHeaderData(8,Qt::Horizontal,trUtf8("单位"));
    model->setHeaderData(9,Qt::Horizontal,trUtf8("总金额"));
    model->setHeaderData(10,Qt::Horizontal,trUtf8("备注"));
    model->setHeaderData(11,Qt::Horizontal,trUtf8("系统备注"));

//    model->select();

    ui->dataTableView->setModel(model);
    ui->dataTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->dataTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->dataTableView->resizeColumnsToContents();
    ui->dataTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header = ui->dataTableView->horizontalHeader();//->horizontalHeader();
    header->setStretchLastSection(true);

    //释放连接，使其回归连接池
    db.close();
}

void CashierDialog::setUser(User *user){
    this->currentUser = user;
}

void CashierDialog::on_searchGoodPushButton_clicked()
{
    // 从数据库连接池里取得连接
    QSqlDatabase db = ConnectionPool::openConnection();

    int i = ui->barcodeLineEdit->text().toInt();

    this->model = new QSqlTableModel(this->parent(),db);
    model->setTable("Goods");

    /*在用户数据表里进行检索查询，匹配用户名和密码是否相同*/
    model->setFilter(QObject::tr("Goods_Id = '%1'").arg(i));

    model->select();
//    model->insertRow((model->rowCount()+1);

//emit(ui->dataTableView->dataChanged(1, 1));

    ui->totalPriceEditLine->setText("12");

    ui->dataTableView->setModel(model);

    db.close();
}
