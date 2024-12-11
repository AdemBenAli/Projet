#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Maintenance {
private:
    int id;
    QString nomClient;
    QString etat;
    QString departement;
    QDate dateM;
    int nbPersonne;
    int nbJour;
    QString state;
    QString summary;
    float temp;

public:
    // Constructeurs
    Maintenance();
    Maintenance(QString nomClient, QString etat, QString departement, QDate dateM, int nbPersonne, int nbJour, QString state, QString summary,float temp);

    // Getters
    int getId() const;
    QString getNomClient() const;
    QString getEtat() const;
    QString getDepartement() const;
    QDate getDateM() const;
    int getNbPersonne() const;
    int getNbJour() const;
    QString getState() const;
    QString getSummary() const;
    float getTemp() const;

    // Setters
    void setNomClient(const QString &value);
    void setEtat(const QString &value);
    void setDepartement(const QString &value);
    void setDateM(const QDate &value);
    void setNbPersonne(int value);
    void setNbJour(int value);
    void setState(const QString &value);
    void setSummary(const QString &value);
    void setTemp(float value);

    // Méthodes CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id);

    // Vérification de l'existence de l'ID
    bool verifierExistance(int id);

    QSqlQueryModel* trie();

    QSqlQueryModel* trie1();

    QSqlQueryModel* trie2();

    QSqlQueryModel* recherche(const QString& r);
};

#endif // MAINTENANCE_H
