#include "VolDAO.h"
#include "../database/DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QList<Vol> VolDAO::all()
{
    QList<Vol> list;
    QSqlQuery q(DatabaseManager::instance().database());
    if (!q.exec("SELECT id, code, destination, date, heure, compagnie, prix FROM vols ORDER BY date, heure")) {
        qWarning() << q.lastError().text();
        return list;
    }
    while (q.next()) {
        Vol v;
        v.id = q.value(0).toInt();
        v.code = q.value(1).toString();
        v.destination = q.value(2).toString();
        v.date = QDate::fromString(q.value(3).toString(), Qt::ISODate);
        v.heure = QTime::fromString(q.value(4).toString(), "HH:mm:ss");
        v.compagnie = q.value(5).toString();
        v.prix = q.value(6).toDouble();
        list.append(v);
    }
    return list;
}

bool VolDAO::add(const Vol &v)
{
    QSqlQuery q(DatabaseManager::instance().database());
    q.prepare("INSERT INTO vols (code, destination, date, heure, compagnie, prix) VALUES (:code,:dest,:date,:heure,:comp,:prix)");
    q.bindValue(":code", v.code);
    q.bindValue(":dest", v.destination);
    q.bindValue(":date", v.date.toString(Qt::ISODate));
    q.bindValue(":heure", v.heure.toString("HH:mm:ss"));
    q.bindValue(":comp", v.compagnie);
    q.bindValue(":prix", v.prix);
    if (!q.exec()) {
        qWarning() << q.lastError().text();
        return false;
    }
    return true;
}

bool VolDAO::update(const Vol &v)
{
    QSqlQuery q(DatabaseManager::instance().database());
    q.prepare("UPDATE vols SET code=:code, destination=:dest, date=:date, heure=:heure, compagnie=:comp, prix=:prix WHERE id=:id");
    q.bindValue(":code", v.code);
    q.bindValue(":dest", v.destination);
    q.bindValue(":date", v.date.toString(Qt::ISODate));
    q.bindValue(":heure", v.heure.toString("HH:mm:ss"));
    q.bindValue(":comp", v.compagnie);
    q.bindValue(":prix", v.prix);
    q.bindValue(":id", v.id);
    if (!q.exec()) {
        qWarning() << q.lastError().text();
        return false;
    }
    return true;
}

bool VolDAO::remove(int id)
{
    QSqlQuery q(DatabaseManager::instance().database());
    q.prepare("DELETE FROM vols WHERE id=:id");
    q.bindValue(":id", id);
    if (!q.exec()) {
        qWarning() << q.lastError().text();
        return false;
    }
    return true;
}

QList<Vol> VolDAO::search(const QString &term)
{
    QList<Vol> list;
    QSqlQuery q(DatabaseManager::instance().database());
    q.prepare("SELECT id, code, destination, date, heure, compagnie, prix FROM vols WHERE code LIKE :t OR destination LIKE :t OR compagnie LIKE :t");
    q.bindValue(":t", "%" + term + "%");
    if (!q.exec()) {
        qWarning() << q.lastError().text();
        return list;
    }
    while (q.next()) {
        Vol v;
        v.id = q.value(0).toInt();
        v.code = q.value(1).toString();
        v.destination = q.value(2).toString();
        v.date = QDate::fromString(q.value(3).toString(), Qt::ISODate);
        v.heure = QTime::fromString(q.value(4).toString(), "HH:mm:ss");
        v.compagnie = q.value(5).toString();
        v.prix = q.value(6).toDouble();
        list.append(v);
    }
    return list;
}

Vol VolDAO::byId(int id)
{
    Vol v;
    QSqlQuery q(DatabaseManager::instance().database());
    q.prepare("SELECT id, code, destination, date, heure, compagnie, prix FROM vols WHERE id=:id");
    q.bindValue(":id", id);
    if (!q.exec()) return v;
    if (q.next()) {
        v.id = q.value(0).toInt();
        v.code = q.value(1).toString();
        v.destination = q.value(2).toString();
        v.date = QDate::fromString(q.value(3).toString(), Qt::ISODate);
        v.heure = QTime::fromString(q.value(4).toString(), "HH:mm:ss");
        v.compagnie = q.value(5).toString();
        v.prix = q.value(6).toDouble();
    }
    return v;
}

int VolDAO::count()
{
    QSqlQuery q(DatabaseManager::instance().database());
    if (!q.exec("SELECT COUNT(*) FROM vols")) return 0;
    if (q.next()) return q.value(0).toInt();
    return 0;
}