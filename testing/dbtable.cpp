#include "dbtable.h"
#include "ui_dbtable.h"

dbtable::dbtable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbtable)
{

    qDebug()<<"@@@@@@@";

    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("testing.db");
    if(!db1.open()){
        qDebug()<<"open db error";
    }



}

dbtable::~dbtable()
{
    delete ui;
}
