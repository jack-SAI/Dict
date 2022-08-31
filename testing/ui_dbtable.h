/********************************************************************************
** Form generated from reading UI file 'dbtable.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBTABLE_H
#define UI_DBTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dbtable
{
public:

    void setupUi(QWidget *dbtable)
    {
        if (dbtable->objectName().isEmpty())
            dbtable->setObjectName(QStringLiteral("dbtable"));
        dbtable->resize(400, 300);

        retranslateUi(dbtable);

        QMetaObject::connectSlotsByName(dbtable);
    } // setupUi

    void retranslateUi(QWidget *dbtable)
    {
        dbtable->setWindowTitle(QApplication::translate("dbtable", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dbtable: public Ui_dbtable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBTABLE_H
