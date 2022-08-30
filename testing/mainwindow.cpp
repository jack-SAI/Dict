#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <workingplane.h>
#include <qdebug.h>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint);
    setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    workingPlane *wk = new workingPlane();
    //db=new dbtable();
    //wk->setParent(this);
    //wk->show();
    connect(ui->templogin,&QPushButton::clicked,wk,&QWidget::show);
    connect(this,&MainWindow::acception,wk,&QWidget::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"click templogin";
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="1" && ui->lineEdit_2->text()=="1"){
        acception();
    }
    else{

        QMessageBox::warning(this,"Attention","account or password error!",QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();

    }
}
