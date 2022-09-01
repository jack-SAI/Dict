#include "workingplane.h"
#include "ui_workingplane.h"
#include<QTextBrowser>
#include<QCompleter>

workingPlane::workingPlane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workingPlane)
{
    ui->setupUi(this);
    this->setWindowTitle("简易英汉词典");
    models = new QSqlQueryModel(ui->tableView);//QSqlTableModel为读写模型,QSqlQueryModel为用来查询的只读模型
     modelss = new QSqlQueryModel(ui->tableView);//QSqlTableModel为读写模型,QSqlQueryModel为用来查询的只读模型
    Connection();



}

workingPlane::~workingPlane()
{
    delete ui;
}


void workingPlane::Connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库的连接，连接名默认
    db.setDatabaseName("testing.db");
    if(!db.open()){
        QMessageBox::warning(this,"错误","不能连接到数据库！",QMessageBox::Yes);
    }
    else{
        qDebug("open is OK");
    }

    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);


               model->setQuery(QString("select * from stardict limit 10"));
               //列名

               model->setHeaderData(0, Qt::Horizontal, tr("ID"));
               model->setHeaderData(1, Qt::Horizontal, tr("状态"));


               ui->tableView->setModel(model);//数据放置进去
               ui->tableView->setColumnWidth(2,100);                             //设置第一列的宽度
               ui->tableView->setColumnWidth(5,500);                            //设置第二列的宽度
               ui->tableView->hideColumn(0);                                     //隐藏不必要的列
               ui->tableView->hideColumn(1);
               ui->tableView->hideColumn(3);
               ui->tableView->hideColumn(4);
               ui->tableView->hideColumn(6);
               ui->tableView->hideColumn(7);
               ui->tableView->hideColumn(8);
               ui->tableView->hideColumn(9);
               ui->tableView->hideColumn(10);
               ui->tableView->hideColumn(11);
               ui->tableView->hideColumn(12);
               ui->tableView->hideColumn(13);
               ui->tableView->hideColumn(14);

}


void workingPlane::show_table()
{
    qDebug("show is OK");

    models->setHeaderData(2,Qt::Horizontal,tr("英文"));
    models->setHeaderData(5,Qt::Horizontal,tr("中文"));


    ui->tableView->setModel(models);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中时为整行选中
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(5,500);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->hideColumn(11);
    ui->tableView->hideColumn(12);
    ui->tableView->hideColumn(13);
    ui->tableView->hideColumn(14);

}


void workingPlane::on_search_clicked()
{
    QString input = ui->lineEdit->text();
    if(input.isEmpty())      //判断是否有输入查询内容
    {
        QMessageBox::warning(this,"查询失败","请输入要查询的单词！",QMessageBox::Yes);
        return;
    }
    QSqlQuery query;
    query.prepare("select * from stardict where sw LIKE :sw order by sw asc");//搜索以:word开头的所有单词，全字匹配是where word = :word
    query.bindValue(":sw",ui->lineEdit->text()+"%");//参考http://www.qtdebug.com/qtbook-db-common/
    query.exec();
    if(!query.next())
    {
        QMessageBox::warning(this,"查询失败","没有查找到该单词！",QMessageBox::Yes);
        return;
    }
    models->setQuery(query);   //重新设置model的内容
    show_table();

}

void workingPlane::mouseDoubleClickEvent(){
    qDebug()<<"D C";
    if(mMaxnorm){
        this->showMaximized();
        mMaxnorm=1;
    }else{
        this->showMinimized();
        mMaxnorm=0;
    }
}

void workingPlane::closeEvent(QCloseEvent *event){

    QMessageBox msgBox;
    msgBox.setText("提示");
    msgBox.setInformativeText("确认退出?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok){
        //若用户点击确认，则接收这个事件,当前窗口会关闭
        exit(0);
    }else{
       //若用户点击取消，则忽略这个事件，当前窗口不会关闭
    event->ignore();
}
}





void workingPlane::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty() || arg1.length()<=2){

        return;

    }
    //qDebug()<<"!! ##";
    QStringList prelist;
    QSqlQuery qsq;

    qsq.prepare("select word from stardict where sw LIKE :sw order by sw asc");//搜索以:word开头的所有单词，全字匹配是where word = :word
    qsq.bindValue(":sw",arg1+"%");//参考http://www.qtdebug.com/qtbook-db-common/
    qsq.exec();

    while(qsq.next()){
        prelist.append(qsq.value(0).toString());
    }



    QCompleter *pCompleter=new QCompleter(prelist,this);

    //pCompleter->setFilterMode(Qt::MatchContains);    //部分内容匹配
   pCompleter->setCaseSensitivity(Qt::CaseInsensitive);    //设置为大小写不敏感
    ui->lineEdit->setCompleter(pCompleter);

}
