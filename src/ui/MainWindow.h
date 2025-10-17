
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void showDashboard();
    void showClients();
    void showVols();
    void showReservations();
    void logout();

    // Clients
    void loadClientsTable();
    void on_btnClientAdd_clicked();
    void on_btnClientEdit_clicked();
    void on_btnClientDelete_clicked();


    // Vols
    void loadVolsTable();
    void on_btnVolAdd_clicked();
    void on_btnVolEdit_clicked();
    void on_btnVolDelete_clicked();

    // Reservations
    void loadReservationsTable();
    void on_btnResAdd_clicked();
    void on_btnResEdit_clicked();
    void on_btnResDelete_clicked();
    void on_btnPrintTicket_clicked();

private:
    Ui::MainWindow *ui;
    void updateDashboard();
};

#endif // MAINWINDOW_H
