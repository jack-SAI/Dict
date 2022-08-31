/********************************************************************************
** Form generated from reading UI file 'workingplane.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKINGPLANE_H
#define UI_WORKINGPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workingPlane
{
public:
    QFrame *frame;
    QLineEdit *lineEdit;
    QPushButton *search;
    QTableView *tableView;

    void setupUi(QWidget *workingPlane)
    {
        if (workingPlane->objectName().isEmpty())
            workingPlane->setObjectName(QStringLiteral("workingPlane"));
        workingPlane->resize(853, 531);
        workingPlane->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(workingPlane);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-10, 0, 861, 531));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-image: url(:/image/122.webp);}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 80, 591, 41));
        search = new QPushButton(frame);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(680, 80, 51, 41));
        search->setCursor(QCursor(Qt::PointingHandCursor));
        search->setStyleSheet(QLatin1String("\n"
"QPushButton:pressed\n"
"{\n"
"    \n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"    QPushButton:hover{\n"
"                     background-color : rgb(31, 164, 255);\n"
"\n"
"border-radius:15px;\n"
"                     color:white;\n"
"                     }\n"
""));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(80, 130, 591, 371));

        retranslateUi(workingPlane);

        QMetaObject::connectSlotsByName(workingPlane);
    } // setupUi

    void retranslateUi(QWidget *workingPlane)
    {
        workingPlane->setWindowTitle(QApplication::translate("workingPlane", "Form", Q_NULLPTR));
        search->setText(QApplication::translate("workingPlane", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class workingPlane: public Ui_workingPlane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKINGPLANE_H
