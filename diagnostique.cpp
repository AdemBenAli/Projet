#include "diagnostique.h"
#include <QFileDialog>
#include <QPixmap>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

Diagnostique::Diagnostique() {}
void Diagnostique::choosePhoto()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Photo", "", "Images (*.png *.jpg *.jpeg)");
    if (!filePath.isEmpty())
    {
        selectedPhotoPath = filePath; // Store the path of the selected photo
        QPixmap pixmap(filePath);    // Load the photo into a QPixmap
        ui->photoLabel->setPixmap(pixmap.scaled(ui->photoLabel->size(), Qt::KeepAspectRatio)); // Display photo
    }
    else
    {
        ui->aiSuggestionsTextBox->setText("No photo selected.");
    }
}

void Diagnostique::submitPhoto()
{
    if (selectedPhotoPath.isEmpty())
    {
        ui->aiSuggestionsTextBox->setText("Please choose a photo first!");
        return;
    }

    QFile file(selectedPhotoPath);
    if (!file.open(QIODevice::ReadOnly))
    {
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
       inlineData["data"] =QString(photoData.toBase64());  // Your Base64-encoded image data (remove the 'data:image/jpeg;base64,' prefix)

       QJsonObject part1;
       part1["text"] = "Analyse this image";

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


void Diagnostique::handleAiResponse()
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
