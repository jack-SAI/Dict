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
#include<QTextBrowser>
#include<QCompleter>
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
    void on_search_clicked();
    void mouseDoubleClickEvent();
    void closeEvent(QCloseEvent *);
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::workingPlane *ui;
    int mMaxnorm=0;
    QSqlQueryModel *models;
    void OperateDB();
    void show_table();
};

#endif // WORKINGPLANE_H
