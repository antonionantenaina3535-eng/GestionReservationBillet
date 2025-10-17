/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sideMenu;
    QVBoxLayout *sideLayout;
    QLabel *lblLogo;
    QPushButton *btnDashboard;
    QPushButton *btnClients;
    QPushButton *btnVols;
    QPushButton *btnReservations;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLogout;
    QStackedWidget *stackedWidget;
    QWidget *pageDashboard;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblDashboardTitle;
    QHBoxLayout *statsLayout;
    QLabel *lblTotalVols;
    QLabel *lblTotalClients;
    QLabel *lblTotalReservations;
    QWidget *pageClients;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *clientsActions;
    QLineEdit *lineClientSearch;
    QPushButton *btnClientAdd;
    QPushButton *btnClientEdit;
    QPushButton *btnClientDelete;
    QTableWidget *tableClients;
    QWidget *pageVols;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *volsActions;
    QLineEdit *lineVolSearch;
    QPushButton *btnVolAdd;
    QPushButton *btnVolEdit;
    QPushButton *btnVolDelete;
    QTableWidget *tableVols;
    QWidget *pageReservations;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *reservActions;
    QPushButton *btnResAdd;
    QPushButton *btnResEdit;
    QPushButton *btnResDelete;
    QPushButton *btnPrintTicket;
    QTableWidget *tableReservations;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sideMenu = new QFrame(centralwidget);
        sideMenu->setObjectName("sideMenu");
        sideMenu->setMinimumWidth(180);
        sideLayout = new QVBoxLayout(sideMenu);
        sideLayout->setObjectName("sideLayout");
        lblLogo = new QLabel(sideMenu);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setAlignment(Qt::AlignCenter);

        sideLayout->addWidget(lblLogo);

        btnDashboard = new QPushButton(sideMenu);
        btnDashboard->setObjectName("btnDashboard");

        sideLayout->addWidget(btnDashboard);

        btnClients = new QPushButton(sideMenu);
        btnClients->setObjectName("btnClients");

        sideLayout->addWidget(btnClients);

        btnVols = new QPushButton(sideMenu);
        btnVols->setObjectName("btnVols");

        sideLayout->addWidget(btnVols);

        btnReservations = new QPushButton(sideMenu);
        btnReservations->setObjectName("btnReservations");

        sideLayout->addWidget(btnReservations);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sideLayout->addItem(verticalSpacer);

        btnLogout = new QPushButton(sideMenu);
        btnLogout->setObjectName("btnLogout");

        sideLayout->addWidget(btnLogout);


        horizontalLayout->addWidget(sideMenu);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageDashboard = new QWidget();
        pageDashboard->setObjectName("pageDashboard");
        verticalLayout_2 = new QVBoxLayout(pageDashboard);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblDashboardTitle = new QLabel(pageDashboard);
        lblDashboardTitle->setObjectName("lblDashboardTitle");

        verticalLayout_2->addWidget(lblDashboardTitle);

        statsLayout = new QHBoxLayout();
        statsLayout->setObjectName("statsLayout");
        lblTotalVols = new QLabel(pageDashboard);
        lblTotalVols->setObjectName("lblTotalVols");

        statsLayout->addWidget(lblTotalVols);

        lblTotalClients = new QLabel(pageDashboard);
        lblTotalClients->setObjectName("lblTotalClients");

        statsLayout->addWidget(lblTotalClients);

        lblTotalReservations = new QLabel(pageDashboard);
        lblTotalReservations->setObjectName("lblTotalReservations");

        statsLayout->addWidget(lblTotalReservations);


        verticalLayout_2->addLayout(statsLayout);

        stackedWidget->addWidget(pageDashboard);
        pageClients = new QWidget();
        pageClients->setObjectName("pageClients");
        verticalLayout_3 = new QVBoxLayout(pageClients);
        verticalLayout_3->setObjectName("verticalLayout_3");
        clientsActions = new QHBoxLayout();
        clientsActions->setObjectName("clientsActions");
        lineClientSearch = new QLineEdit(pageClients);
        lineClientSearch->setObjectName("lineClientSearch");

        clientsActions->addWidget(lineClientSearch);

        btnClientAdd = new QPushButton(pageClients);
        btnClientAdd->setObjectName("btnClientAdd");

        clientsActions->addWidget(btnClientAdd);

        btnClientEdit = new QPushButton(pageClients);
        btnClientEdit->setObjectName("btnClientEdit");

        clientsActions->addWidget(btnClientEdit);

        btnClientDelete = new QPushButton(pageClients);
        btnClientDelete->setObjectName("btnClientDelete");

        clientsActions->addWidget(btnClientDelete);


        verticalLayout_3->addLayout(clientsActions);

        tableClients = new QTableWidget(pageClients);
        tableClients->setObjectName("tableClients");

        verticalLayout_3->addWidget(tableClients);

        stackedWidget->addWidget(pageClients);
        pageVols = new QWidget();
        pageVols->setObjectName("pageVols");
        verticalLayout_4 = new QVBoxLayout(pageVols);
        verticalLayout_4->setObjectName("verticalLayout_4");
        volsActions = new QHBoxLayout();
        volsActions->setObjectName("volsActions");
        lineVolSearch = new QLineEdit(pageVols);
        lineVolSearch->setObjectName("lineVolSearch");

        volsActions->addWidget(lineVolSearch);

        btnVolAdd = new QPushButton(pageVols);
        btnVolAdd->setObjectName("btnVolAdd");

        volsActions->addWidget(btnVolAdd);

        btnVolEdit = new QPushButton(pageVols);
        btnVolEdit->setObjectName("btnVolEdit");

        volsActions->addWidget(btnVolEdit);

        btnVolDelete = new QPushButton(pageVols);
        btnVolDelete->setObjectName("btnVolDelete");

        volsActions->addWidget(btnVolDelete);


        verticalLayout_4->addLayout(volsActions);

        tableVols = new QTableWidget(pageVols);
        tableVols->setObjectName("tableVols");

        verticalLayout_4->addWidget(tableVols);

        stackedWidget->addWidget(pageVols);
        pageReservations = new QWidget();
        pageReservations->setObjectName("pageReservations");
        verticalLayout_5 = new QVBoxLayout(pageReservations);
        verticalLayout_5->setObjectName("verticalLayout_5");
        reservActions = new QHBoxLayout();
        reservActions->setObjectName("reservActions");
        btnResAdd = new QPushButton(pageReservations);
        btnResAdd->setObjectName("btnResAdd");

        reservActions->addWidget(btnResAdd);

        btnResEdit = new QPushButton(pageReservations);
        btnResEdit->setObjectName("btnResEdit");

        reservActions->addWidget(btnResEdit);

        btnResDelete = new QPushButton(pageReservations);
        btnResDelete->setObjectName("btnResDelete");

        reservActions->addWidget(btnResDelete);

        btnPrintTicket = new QPushButton(pageReservations);
        btnPrintTicket->setObjectName("btnPrintTicket");

        reservActions->addWidget(btnPrintTicket);


        verticalLayout_5->addLayout(reservActions);

        tableReservations = new QTableWidget(pageReservations);
        tableReservations->setObjectName("tableReservations");

        verticalLayout_5->addWidget(tableReservations);

        stackedWidget->addWidget(pageReservations);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion R\303\251servations - Tableau de bord", nullptr));
        lblLogo->setText(QCoreApplication::translate("MainWindow", "Compagnie A\303\251rienne", nullptr));
        btnDashboard->setText(QCoreApplication::translate("MainWindow", "Tableau de bord", nullptr));
        btnClients->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        btnVols->setText(QCoreApplication::translate("MainWindow", "Vols", nullptr));
        btnReservations->setText(QCoreApplication::translate("MainWindow", "R\303\251servations", nullptr));
        btnLogout->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        lblDashboardTitle->setText(QCoreApplication::translate("MainWindow", "Tableau de bord", nullptr));
        lblTotalVols->setText(QCoreApplication::translate("MainWindow", "Vols: 0", nullptr));
        lblTotalClients->setText(QCoreApplication::translate("MainWindow", "Clients: 0", nullptr));
        lblTotalReservations->setText(QCoreApplication::translate("MainWindow", "R\303\251servations: 0", nullptr));
        lineClientSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un client...", nullptr));
        btnClientAdd->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnClientEdit->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnClientDelete->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lineVolSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un vol...", nullptr));
        btnVolAdd->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnVolEdit->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnVolDelete->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnResAdd->setText(QCoreApplication::translate("MainWindow", "Nouvelle r\303\251servation", nullptr));
        btnResEdit->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnResDelete->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnPrintTicket->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rer ticket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
