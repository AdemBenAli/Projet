#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maintenance.h"
#include <QMessageBox>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->aff->setModel(m.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_supprimer_2_clicked()
{
    int id = ui->supp->text().toInt();
    Maintenance m;
    if (m.verifierExistance(id)) {
        if (m.supprimer(id)) {
            QMessageBox::information(this, "Suppression", "Enregistrement supprimé avec succès.");
            ui->aff->setModel(m.afficher());

        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "ID introuvable.");
    }
}


void MainWindow::on_ajouter_clicked()
{
    QString nomClient = ui->nom->text();
    QString etat = ui->etat->currentText();
    QString departement = ui->departement->text();
    QDate dateM = ui->date->date();
    int nbPersonne = ui->nb_p->text().toInt();
    int nbJour = ui->nb_j->text().toInt();
    QString state = ui->state->text();
    QString summary = ui->summary->toPlainText();

    // Contrôles de validation
    if (nomClient.isEmpty() || etat.isEmpty() || departement.isEmpty() || state.isEmpty() || summary.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (nbPersonne <= 0 || nbJour <= 0) {
        QMessageBox::warning(this, "Erreur", "Le nombre de personnes et le nombre de jours doivent être supérieurs à zéro.");
        return;
    }

    Maintenance m(nomClient, etat, departement, dateM, nbPersonne, nbJour, state, summary);

    if (m.ajouter()) {
        QMessageBox::information(this, "Ajout", "Enregistrement ajouté avec succès.");
        ui->aff->setModel(m.afficher());
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout.");
    }
}


void MainWindow::on_annuler_clicked()
{
    ui->nom->clear();
    ui->etat->setCurrentIndex(0);
    ui->departement->clear();
    ui->date->setDate(QDate::currentDate());
    ui->nb_p->clear();
    ui->nb_j->clear();
    ui->state->clear();
    ui->summary->clear();
}


void MainWindow::on_modifier_2_clicked()
{int id = ui->id_m->text().toInt();
    QString nomClient = ui->nom_2->text();
    QString etat = ui->etat_2->currentText();
    QString departement = ui->departement_2->text();
    QDate dateM = ui->date_2->date();
    int nbPersonne = ui->nb_p_2->text().toInt();
    int nbJour = ui->nb_j_2->text().toInt();
    QString state = ui->state_2->text();
    QString summary = ui->summary_2->toPlainText();

    // Contrôles de validation
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être valide et supérieur à zéro.");
        return;
    }

    if (nomClient.isEmpty() || etat.isEmpty() || departement.isEmpty() || state.isEmpty() || summary.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (nbPersonne <= 0 || nbJour <= 0) {
        QMessageBox::warning(this, "Erreur", "Le nombre de personnes et le nombre de jours doivent être supérieurs à zéro.");
        return;
    }

    Maintenance m(nomClient, etat, departement, dateM, nbPersonne, nbJour, state, summary);

    if (m.verifierExistance(id)) {
        if (m.modifier(id)) {
            QMessageBox::information(this, "Modification", "Enregistrement modifié avec succès.");
            ui->aff->setModel(m.afficher());
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "ID introuvable.");
    }
}


void MainWindow::on_recuperer_clicked()
{
    int id = ui->id_m->text().toInt();
    Maintenance m;
    QSqlQuery query;
    query.prepare("SELECT * FROM maintenance WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ui->nom_2->setText(query.value("nom_client").toString());
        ui->etat_2->setCurrentText(query.value("etat").toString());
        ui->departement_2->setText(query.value("departement").toString());
        ui->date_2->setDate(query.value("date_m").toDate());
        ui->nb_p_2->setText(query.value("nb_personne").toString());
        ui->nb_j_2->setText(query.value("nb_jour").toString());
        ui->state_2->setText(query.value("state").toString());
        ui->summary_2->setPlainText(query.value("summary").toString());
    } else {
        QMessageBox::warning(this, "Erreur", "ID introuvable.");
    }
}

void MainWindow::on_trie_clicked()
{
    Maintenance m;
    ui->aff->setModel(nullptr);

    // Retrieve the sorted model from the trie function
    QSqlQueryModel *sortedModel = m.trie();

    // Set the sorted model to the table view
    ui->aff->setModel(sortedModel);

}
void MainWindow::on_recherche_clicked()
{
    QString r = ui->rech->text();
    Maintenance m;
    ui->aff->setModel(nullptr);

    // Retrieve the sorted model from the trie function
    QSqlQueryModel *sortedModel = m.recherche(r);

    // Set the sorted model to the table view
    ui->aff->setModel(sortedModel);

}
