#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ClientDialog.h"
#include "VolDialog.h"
#include "ReservationDialog.h"
#include "TicketWidget.h"
#include "../dao/ClientDAO.h"
#include "../dao/VolDAO.h"
#include "../dao/ReservationDAO.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnDashboard, &QPushButton::clicked, this, &MainWindow::showDashboard);
    connect(ui->btnClients, &QPushButton::clicked, this, &MainWindow::showClients);
    connect(ui->btnVols, &QPushButton::clicked, this, &MainWindow::showVols);
    connect(ui->btnReservations, &QPushButton::clicked, this, &MainWindow::showReservations);
    connect(ui->btnLogout, &QPushButton::clicked, this, &MainWindow::logout);

    // Clients actions
    connect(ui->btnClientAdd, &QPushButton::clicked, this, &MainWindow::on_btnClientAdd_clicked);
    connect(ui->btnClientEdit, &QPushButton::clicked, this, &MainWindow::on_btnClientEdit_clicked);
    connect(ui->btnClientDelete, &QPushButton::clicked, this, &MainWindow::on_btnClientDelete_clicked);


    // Vols actions
    connect(ui->btnVolAdd, &QPushButton::clicked, this, &MainWindow::on_btnVolAdd_clicked);
    connect(ui->btnVolEdit, &QPushButton::clicked, this, &MainWindow::on_btnVolEdit_clicked);
    connect(ui->btnVolDelete, &QPushButton::clicked, this, &MainWindow::on_btnVolDelete_clicked);

    // Reservations actions
    connect(ui->btnResAdd, &QPushButton::clicked, this, &MainWindow::on_btnResAdd_clicked);
    connect(ui->btnResEdit, &QPushButton::clicked, this, &MainWindow::on_btnResEdit_clicked);
    connect(ui->btnResDelete, &QPushButton::clicked, this, &MainWindow::on_btnResDelete_clicked);
    connect(ui->btnPrintTicket, &QPushButton::clicked, this, &MainWindow::on_btnPrintTicket_clicked);

    // Configure tables
    ui->tableClients->setColumnCount(5);
    ui->tableClients->setHorizontalHeaderLabels({"ID", "Nom", "Prénom", "Email", "Téléphone"});
    ui->tableClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableVols->setColumnCount(7);
    ui->tableVols->setHorizontalHeaderLabels({"ID", "Code", "Destination", "Date", "Heure", "Compagnie", "Prix"});
    ui->tableVols->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableReservations->setColumnCount(5);
    ui->tableReservations->setHorizontalHeaderLabels({"ID", "Client", "Vol", "Date réservation", "Statut"});
    ui->tableReservations->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Start
    showDashboard();
    loadClientsTable();
    loadVolsTable();
    loadReservationsTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDashboard() { ui->stackedWidget->setCurrentWidget(ui->pageDashboard); updateDashboard(); }
void MainWindow::showClients() { ui->stackedWidget->setCurrentWidget(ui->pageClients); loadClientsTable(); }
void MainWindow::showVols() { ui->stackedWidget->setCurrentWidget(ui->pageVols); loadVolsTable(); }
void MainWindow::showReservations() { ui->stackedWidget->setCurrentWidget(ui->pageReservations); loadReservationsTable(); }

void MainWindow::logout()
{
    close();
}

void MainWindow::updateDashboard()
{
    int totalVols = VolDAO::count();
    int totalClients = ClientDAO::all().size();
    int totalReservations = ReservationDAO::count();

    ui->lblTotalVols->setText(QString("Vols: %1").arg(totalVols));
    ui->lblTotalClients->setText(QString("Clients: %1").arg(totalClients));
    ui->lblTotalReservations->setText(QString("Réservations: %1").arg(totalReservations));
}

void MainWindow::loadClientsTable()
{
    ui->tableClients->setRowCount(0);
    auto clients = ClientDAO::all();
    ui->tableClients->setRowCount(clients.size());
    for (int i=0;i<clients.size();++i) {
        const Client &c = clients.at(i);
        ui->tableClients->setItem(i,0,new QTableWidgetItem(QString::number(c.id)));
        ui->tableClients->setItem(i,1,new QTableWidgetItem(c.nom));
        ui->tableClients->setItem(i,2,new QTableWidgetItem(c.prenom));
        ui->tableClients->setItem(i,3,new QTableWidgetItem(c.email));
        ui->tableClients->setItem(i,4,new QTableWidgetItem(c.telephone));
    }
}

void MainWindow::on_btnClientAdd_clicked()
{
    ClientDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        loadClientsTable();
        updateDashboard();
    }
}

void MainWindow::on_btnClientEdit_clicked()
{
    auto sel = ui->tableClients->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner un client."); return; }
    int row = sel.first()->row();
    int id = ui->tableClients->item(row,0)->text().toInt();
    ClientDialog dlg(this, id);
    if (dlg.exec() == QDialog::Accepted) loadClientsTable();
}

void MainWindow::on_btnClientDelete_clicked()
{
    auto sel = ui->tableClients->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner un client."); return; }
    int row = sel.first()->row();
    int id = ui->tableClients->item(row,0)->text().toInt();
    if (QMessageBox::question(this, "Supprimer", "Confirmer la suppression du client ?") == QMessageBox::Yes) {
        if (ClientDAO::remove(id)) loadClientsTable();
    }
}


void MainWindow::loadVolsTable()
{
    ui->tableVols->setRowCount(0);
    auto vols = VolDAO::all();
    ui->tableVols->setRowCount(vols.size());
    for (int i=0;i<vols.size();++i) {
        const Vol &v = vols.at(i);
        ui->tableVols->setItem(i,0,new QTableWidgetItem(QString::number(v.id)));
        ui->tableVols->setItem(i,1,new QTableWidgetItem(v.code));
        ui->tableVols->setItem(i,2,new QTableWidgetItem(v.destination));
        ui->tableVols->setItem(i,3,new QTableWidgetItem(v.date.toString("yyyy-MM-dd")));
        ui->tableVols->setItem(i,4,new QTableWidgetItem(v.heure.toString("HH:mm")));
        ui->tableVols->setItem(i,5,new QTableWidgetItem(v.compagnie));
        ui->tableVols->setItem(i,6,new QTableWidgetItem(QString::number(v.prix, 'f', 2)));
    }
}

void MainWindow::on_btnVolAdd_clicked()
{
    VolDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        loadVolsTable();
        updateDashboard();
    }
}

void MainWindow::on_btnVolEdit_clicked()
{
    auto sel = ui->tableVols->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner un vol."); return; }
    int row = sel.first()->row();
    int id = ui->tableVols->item(row,0)->text().toInt();
    VolDialog dlg(this, id);
    if (dlg.exec() == QDialog::Accepted) loadVolsTable();
}

void MainWindow::on_btnVolDelete_clicked()
{
    auto sel = ui->tableVols->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner un vol."); return; }
    int row = sel.first()->row();
    int id = ui->tableVols->item(row,0)->text().toInt();
    if (QMessageBox::question(this, "Supprimer", "Confirmer la suppression du vol ?") == QMessageBox::Yes) {
        if (VolDAO::remove(id)) loadVolsTable();
    }
}

void MainWindow::loadReservationsTable()
{
    ui->tableReservations->setRowCount(0);
    auto list = ReservationDAO::all();
    ui->tableReservations->setRowCount(list.size());
    for (int i=0;i<list.size();++i) {
        const Reservation &r = list.at(i);
        auto c = ClientDAO::byId(r.clientId);
        auto v = VolDAO::byId(r.volId);
        ui->tableReservations->setItem(i,0,new QTableWidgetItem(QString::number(r.id)));
        ui->tableReservations->setItem(i,1,new QTableWidgetItem(QString("%1 %2").arg(c.nom).arg(c.prenom)));
        ui->tableReservations->setItem(i,2,new QTableWidgetItem(QString("%1 - %2").arg(v.code).arg(v.destination)));
        ui->tableReservations->setItem(i,3,new QTableWidgetItem(r.dateReservation.toString("yyyy-MM-dd")));
        ui->tableReservations->setItem(i,4,new QTableWidgetItem(r.statut));
    }
}

void MainWindow::on_btnResAdd_clicked()
{
    ReservationDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        loadReservationsTable();
        updateDashboard();
    }
}

void MainWindow::on_btnResEdit_clicked()
{
    auto sel = ui->tableReservations->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner une réservation."); return; }
    int row = sel.first()->row();
    int id = ui->tableReservations->item(row,0)->text().toInt();
    ReservationDialog dlg(this, id);
    if (dlg.exec() == QDialog::Accepted) loadReservationsTable();
}

void MainWindow::on_btnResDelete_clicked()
{
    auto sel = ui->tableReservations->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner une réservation."); return; }
    int row = sel.first()->row();
    int id = ui->tableReservations->item(row,0)->text().toInt();
    if (QMessageBox::question(this, "Supprimer", "Confirmer la suppression de la réservation ?") == QMessageBox::Yes) {
        if (ReservationDAO::remove(id)) loadReservationsTable();
    }
}

void MainWindow::on_btnPrintTicket_clicked()
{
    auto sel = ui->tableReservations->selectedItems();
    if (sel.isEmpty()) { QMessageBox::information(this, "Sélection", "Veuillez sélectionner une réservation."); return; }
    int row = sel.first()->row();
    int id = ui->tableReservations->item(row,0)->text().toInt();

    TicketWidget ticket(this, id);
    ticket.exec();
}

