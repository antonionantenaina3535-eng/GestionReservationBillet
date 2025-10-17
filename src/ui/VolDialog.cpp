#include "VolDialog.h"
#include "ui_VolDialog.h"
#include "../dao/VolDAO.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>

VolDialog::VolDialog(QWidget *parent, int volId)
    : QDialog(parent), ui(new Ui::VolDialog), m_volId(volId)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->timeEdit->setTime(QTime::currentTime());
    connect(ui->btnCancel, &QPushButton::clicked, this, &VolDialog::on_btnCancel_clicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &VolDialog::on_btnSave_clicked);
    if (m_volId != -1) loadVol();
}

VolDialog::~VolDialog() { delete ui; }

void VolDialog::loadVol()
{
    auto v = VolDAO::byId(m_volId);
    ui->lineCode->setText(v.code);
    ui->lineDestination->setText(v.destination);
    ui->dateEdit->setDate(v.date);
    ui->timeEdit->setTime(v.heure);
    ui->lineCompagnie->setText(v.compagnie);
    ui->spinPrix->setValue(v.prix);
}

void VolDialog::on_btnSave_clicked()
{
    Vol v;
    v.code = ui->lineCode->text().trimmed();
    v.destination = ui->lineDestination->text().trimmed();
    v.date = ui->dateEdit->date();
    v.heure = ui->timeEdit->time();
    v.compagnie = ui->lineCompagnie->text().trimmed();
    v.prix = ui->spinPrix->value();

    if (v.code.isEmpty() || v.destination.isEmpty()) {
        QMessageBox::warning(this, "Champs requis", "Le code et la destination sont requis.");
        return;
    }

    if (m_volId == -1) {
        if (!VolDAO::add(v)) QMessageBox::critical(this, "Erreur", "Impossible d'ajouter le vol.");
    } else {
        v.id = m_volId;
        if (!VolDAO::update(v)) QMessageBox::critical(this, "Erreur", "Impossible de mettre à jour le vol.");
    }
    accept();
}

void VolDialog::on_btnCancel_clicked()
{
    reject();
}