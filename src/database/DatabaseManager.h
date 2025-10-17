#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    bool openSQLite();
    QSqlDatabase database() const;

private:
    DatabaseManager();
    bool initializeSQLiteSchema();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H