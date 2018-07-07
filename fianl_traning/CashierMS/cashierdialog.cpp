#include "cashierdialog.h"
#include "ui_cashierdialog.h"

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
}

CashierDialog::~CashierDialog()
{
    delete ui;
}

//为什么不显示
void CashierDialog::show_Goods_infor()
{
    //createConnection();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));//UTF-8 GBK

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("Seals");
    model->setSort(1, Qt::AscendingOrder);

    model->setHeaderData(0,Qt::Horizontal,tr("商品条码"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品名称"));
    model->setHeaderData(2,Qt::Horizontal,tr("规格型号"));
    model->setHeaderData(3,Qt::Horizontal,tr("颜色"));
    model->setHeaderData(4,Qt::Horizontal,tr("销售价"));
    model->setHeaderData(5,Qt::Horizontal,tr("折扣"));
    model->setHeaderData(6,Qt::Horizontal,tr("折后单价"));
    model->setHeaderData(7,Qt::Horizontal,tr("销售数"));
    model->setHeaderData(8,Qt::Horizontal,tr("单位"));
    model->setHeaderData(9,Qt::Horizontal,tr("总金额"));
    model->setHeaderData(10,Qt::Horizontal,tr("备注"));
    model->setHeaderData(11,Qt::Horizontal,tr("系统备注"));

    model->select();

    ui->dataTableView->setModel(model);
    ui->dataTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->dataTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->dataTableView->resizeColumnsToContents();
    ui->dataTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header = ui->dataTableView->horizontalHeader();//->horizontalHeader();
    header->setStretchLastSection(true);

    //closeConnection();
}



/*
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();
*/

