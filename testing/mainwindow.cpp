#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint);
    setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    workingPlane *wk = new workingPlane();

    connect(ui->templogin,&QPushButton::clicked,wk,&QWidget::show);
    connect(this,&MainWindow::acception,wk,&QWidget::show);
    connect(ui->templogin,&QPushButton::clicked,this,&QWidget::hide);
    connect(this,&MainWindow::acception,this,&QWidget::hide);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="1" && ui->lineEdit_2->text()=="1"){
        acception();
    }
    else{

        QMessageBox::warning(this,"错误","账号或密码错误！",QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();

    }
}
