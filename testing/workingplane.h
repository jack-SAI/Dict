#ifndef WORKINGPLANE_H
#define WORKINGPLANE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
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

private:
    Ui::workingPlane *ui;
    void Connection();
    void show_table();
    QSqlQueryModel *models;
    QSqlQueryModel *modelss;
    QStringList midData;
    QStringList mnameData;
    QStringList mpriceData;
};

#endif // WORKINGPLANE_H
