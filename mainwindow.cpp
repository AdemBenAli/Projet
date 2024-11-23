#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maintenance.h"
#include <QPrinter>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QFileDialog>
#include <QPixmap>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

#include "mailer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      networkManager(new QNetworkAccessManager(this)),
      chatDialog(nullptr)
{
    ui->setupUi(this);
    ui->aff->setModel(m.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
    delete chatDialog;
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
        mailerInstance.sendEmail(&m);
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
void MainWindow::on_trie1_clicked()
{
    Maintenance m;
    ui->aff->setModel(nullptr);

    // Retrieve the sorted model from the trie function
    QSqlQueryModel *sortedModel = m.trie1();

    // Set the sorted model to the table view
    ui->aff->setModel(sortedModel);

}
void MainWindow::on_trie2_clicked()
{
    Maintenance m;
    ui->aff->setModel(nullptr);

    // Retrieve the sorted model from the trie function
    QSqlQueryModel *sortedModel = m.trie2();

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
void MainWindow::on_chatButton_clicked() {
    // If chatDialog hasn't been created yet, create it
    if (!chatDialog) {
        chatDialog = new ChatDialog(this);
    }

    // Calculate position just above the chat button
    QPoint buttonPos = ui->chatButton->mapToGlobal(QPoint(-200, -30));
    int dialogHeight = chatDialog->size().height();
    int yPos = buttonPos.y() - dialogHeight;
    chatDialog->move(buttonPos.x(), yPos);

    // Toggle visibility of chatDialog
    if (chatDialog->isVisible()) {
        chatDialog->hide();  // Hide if currently visible
    } else {
        chatDialog->show();  // Show if currently hidden
    }
}
void MainWindow::on_pdfButton_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "", "PDF Files (*.pdf);;All Files (*)");
    if (filePath.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, "Erreur", "Impossible de démarrer l'impression dans le fichier PDF.");
        return;
    }

    // Title
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(100, 100, "Rapport de Maintenance");

    // Table setup
    int margin = 50; // Page margin
    QRect pageRect = printer.pageRect(QPrinter::Millimeter).toRect();
    int pageWidth = pageRect.width() - 2 * margin;
    int pageHeight = pageRect.height() - 2 * margin;

    // Start positions
    int xStart = margin, yStart = 200;
    int x = xStart, y = yStart;
    int colWidth = pageWidth / 2; // Divide width into 3 columns
    int rowHeight = 30;          // Adjust row height
    int maxY = yStart + pageHeight - 100; // Space for title and footer

    Maintenance m;
    QSqlQueryModel* model = m.afficher();
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter.");
        painter.end();
        return;
    }

    // Draw headers
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        painter.drawText(x, y, colWidth, rowHeight, Qt::AlignLeft, header);
        x += colWidth;
    }

    y += rowHeight; // Move to next row

    // Draw rows
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < model->rowCount(); ++row) {
        x = xStart;
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellData = model->data(model->index(row, col)).toString();
            painter.drawText(x, y, colWidth, rowHeight, Qt::AlignLeft, cellData);
            x += colWidth;
        }
        y += rowHeight;

        // Check for page break
        if (y + rowHeight > maxY) {
            printer.newPage();
            y = yStart;

            // Redraw headers on the new page
            painter.setFont(QFont("Arial", 10, QFont::Bold));
            x = xStart;
            for (int col = 0; col < model->columnCount(); ++col) {
                QString header = model->headerData(col, Qt::Horizontal).toString();
                painter.drawText(x, y, colWidth, rowHeight, Qt::AlignLeft, header);
                x += colWidth;
            }
            y += rowHeight; // Move to the next row
            painter.setFont(QFont("Arial", 10));
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Les données ont été exportées avec succès en PDF !");
}

void MainWindow::on_btnPiecePhoto_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Photo", "", "Images (*.png *.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        selectedPhotoPath = filePath; // Store the path of the selected photo
        QPixmap pixmap(filePath);    // Load the photo into a QPixmap
        ui->photoLabel->setPixmap(pixmap.scaled(ui->photoLabel->size(), Qt::KeepAspectRatio)); // Display photo
    } else {
        ui->aiSuggestionsTextBox->setText("No photo selected.");
    }
}

void MainWindow::on_btnSubmit_clicked() {
    if (selectedPhotoPath.isEmpty()) {
        ui->aiSuggestionsTextBox->setText("Please choose a photo first!");
        return;
    }

    QFile file(selectedPhotoPath);
    if (!file.open(QIODevice::ReadOnly)) {
        ui->aiSuggestionsTextBox->setText("Failed to open the selected photo!");
        return;
    }
    ui->aiSuggestionsTextBox->setText("Anyalising...");
    QByteArray photoData = file.readAll();
    file.close();

    // Construct the request with the correct API endpoint
    QUrl url("https://generativelanguage.googleapis.com/v1/models/gemini-1.5-flash:generateContent?key=AIzaSyCAvPtv3qE_tbtuLAeYb_6d2zrOps3nxYg"); // Replace with the correct endpoint
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Create the JSON payload
    QJsonObject inlineData;
    inlineData["mimeType"] = "image/jpeg";
    inlineData["data"] = QString(photoData.toBase64());  // Your Base64-encoded image data (remove the 'data:image/jpeg;base64,' prefix)

    QJsonObject part1;
    part1["text"] = "Give me simple solution to repair this item";

    QJsonObject part2;
    part2["inlineData"] = inlineData;

    QJsonArray parts;
    parts.append(part1);
    parts.append(part2);

    QJsonObject contentObject;
    contentObject["parts"] = parts;

    QJsonArray contents;
    contents.append(contentObject);

    QJsonObject requestBody;
    requestBody["contents"] = contents;

    // Convert JSON object to QByteArray
    QJsonDocument jsonDoc(requestBody);
    QByteArray jsonData = jsonDoc.toJson();

    // Send the request with the correct JSON payload
    QNetworkReply *reply = networkManager->post(request, jsonData); // Send jsonData here
    connect(reply, &QNetworkReply::finished, this, &MainWindow::handleAiResponse);
}

void MainWindow::handleAiResponse()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray response = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();

        if (jsonObject.contains("candidates")) // Check if 'candidates' key exists
        {
            QJsonArray candidates = jsonObject["candidates"].toArray();

            // Ensure there is at least one candidate
            if (!candidates.isEmpty())
            {
                QJsonObject candidate = candidates[0].toObject();

                // Check if 'content' and 'parts' keys exist
                if (candidate.contains("content"))
                {
                    QJsonObject content = candidate["content"].toObject();
                    if (content.contains("parts"))
                    {
                        QJsonArray parts = content["parts"].toArray();

                        // Ensure there is at least one part
                        if (!parts.isEmpty())
                        {
                            // Extract the 'text' field from the first part
                            QJsonObject part = parts[0].toObject();
                            if (part.contains("text"))
                            {
                                QString text = part["text"].toString();
                                ui->aiSuggestionsTextBox->setText(text); // Set the text to the UI
                            }
                        }
                        else
                        {
                            ui->aiSuggestionsTextBox->setText("No parts found in the response.");
                        }
                    }
                }
            }
            else
            {
                ui->aiSuggestionsTextBox->setText("No candidates found in the response.");
            }
        }
        else
        {
            ui->aiSuggestionsTextBox->setText("Unexpected response: " + QString(response));
        }
    }
    else
    {
        ui->aiSuggestionsTextBox->setText("Error: " + reply->errorString());
    }
    reply->deleteLater();

}
