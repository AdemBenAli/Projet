#include "maintenance.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>

Maintenance::Maintenance() {}

Maintenance::Maintenance(QString nomClient, QString etat, QString departement, QDate dateM, int nbPersonne, int nbJour, QString state, QString summary)
    : nomClient(nomClient), etat(etat), departement(departement), dateM(dateM), nbPersonne(nbPersonne), nbJour(nbJour), state(state), summary(summary) {}

// Getters
int Maintenance::getId() const { return id; }
QString Maintenance::getNomClient() const { return nomClient; }
QString Maintenance::getEtat() const { return etat; }
QString Maintenance::getDepartement() const { return departement; }
QDate Maintenance::getDateM() const { return dateM; }
int Maintenance::getNbPersonne() const { return nbPersonne; }
int Maintenance::getNbJour() const { return nbJour; }
QString Maintenance::getState() const { return state; }
QString Maintenance::getSummary() const { return summary; }

// Setters
void Maintenance::setNomClient(const QString &value) { nomClient = value; }
void Maintenance::setEtat(const QString &value) { etat = value; }
void Maintenance::setDepartement(const QString &value) { departement = value; }
void Maintenance::setDateM(const QDate &value) { dateM = value; }
void Maintenance::setNbPersonne(int value) { nbPersonne = value; }
void Maintenance::setNbJour(int value) { nbJour = value; }
void Maintenance::setState(const QString &value) { state = value; }
void Maintenance::setSummary(const QString &value) { summary = value; }

// Méthode ajouter
bool Maintenance::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO maintenance (id, nom_client, etat, departement, date_m, nb_personne, nb_jour, state, summary) "
                  "VALUES (maintenance_seq.NEXTVAL, :nom_client, :etat, :departement, :date_m, :nb_personne, :nb_jour, :state, :summary)");
    query.bindValue(":nom_client", nomClient);
    query.bindValue(":etat", etat);
    query.bindValue(":departement", departement);
    query.bindValue(":date_m", dateM);
    query.bindValue(":nb_personne", nbPersonne);
    query.bindValue(":nb_jour", nbJour);
    query.bindValue(":state", state);
    query.bindValue(":summary", summary);
    return query.exec();
}

// Méthode afficher
QSqlQueryModel* Maintenance::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom_client, etat, departement, date_m, nb_personne, nb_jour, state, summary FROM maintenance");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nb Personne"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nb Jour"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Summary"));
    return model;
}

// Méthode supprimer
bool Maintenance::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM maintenance WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Méthode modifier
bool Maintenance::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE maintenance SET nom_client = :nom_client, etat = :etat, departement = :departement, "
                  "date_m = :date_m, nb_personne = :nb_personne, nb_jour = :nb_jour, state = :state, summary = :summary "
                  "WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom_client", nomClient);
    query.bindValue(":etat", etat);
    query.bindValue(":departement", departement);
    query.bindValue(":date_m", dateM);
    query.bindValue(":nb_personne", nbPersonne);
    query.bindValue(":nb_jour", nbJour);
    query.bindValue(":state", state);
    query.bindValue(":summary", summary);
    return query.exec();
}

// Vérification de l'existence de l'ID
bool Maintenance::verifierExistance(int id) {
    QSqlQuery query;
    query.prepare("SELECT id FROM maintenance WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    return query.next();  // Renvoie true si l'ID existe
}
QSqlQueryModel* Maintenance::trie() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM maintenance ORDER BY nom_client ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nb Personne"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nb Jour"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Summary"));
    return model;
}

QSqlQueryModel* Maintenance::trie1() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM maintenance ORDER BY nb_personne ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nb Personne"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nb Jour"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Summary"));
    return model;
}
QSqlQueryModel* Maintenance::trie2() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM maintenance ORDER BY nb_jour ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nb Personne"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nb Jour"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Summary"));
    return model;
}

QSqlQueryModel* Maintenance::recherche(const QString& r) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id, nom_client, etat, departement, date_m, nb_personne, nb_jour, state, summary FROM maintenance WHERE nom_client LIKE :nom_client");
    query.bindValue(":nom_client", "%" + r + "%");  // Bind the search term with wildcard characters
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nb Personne"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nb Jour"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Summary"));
    return model;
}
