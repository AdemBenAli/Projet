#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("adem");
    db.setPassword("adem");

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return test;
}

