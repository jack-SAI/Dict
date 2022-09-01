#ifndef WORKINGPLANE_H
#define WORKINGPLANE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include<QCloseEvent>
namespace Ui {
class workingPlane;
}

class workingPlane : public QWidget
{
    Q_OBJECT

public:
    explicit workingPlane(QWidget *parent = nullptr);
    ~workingPlane();

private slots:
   // void on_pushButton_clicked();
    void on_search_clicked();
    void mouseDoubleClickEvent();
    void closeEvent(QCloseEvent *);

   // void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::workingPlane *ui;
    void Connection();
    void show_table();
    int mMaxnorm=0;
    QSqlQueryModel *models;
    QSqlQueryModel *modelss;
    QStringList midData;
    QStringList mnameData;
    QStringList mpriceData;

};

#endif // WORKINGPLANE_H
