#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog),
    networkManager(new QNetworkAccessManager(this)) // Initialize network manager
{
    ui->setupUi(this);

    // Connect the Enter key in userInput to sendMessage slot
    connect(ui->userInput, &QLineEdit::returnPressed, this, &ChatDialog::sendMessage);

    // Connect Send button to sendMessage slot
    connect(ui->sendButton, &QPushButton::clicked, this, &ChatDialog::sendMessage);
}

ChatDialog::~ChatDialog() {
    delete ui;
}

void ChatDialog::sendMessage() {
    QString userMessage = ui->userInput->text();
    if (!userMessage.isEmpty()) {
        // Display user message in chatDisplay
        ui->chatDisplay->append("You: " + userMessage);

        // Modify the message to be a prompt for Gemini AI
        QString promptMessage = "Respond to: " + userMessage;

        // Send the modified message to Gemini AI
        sendMessageToGemini(promptMessage);

        // Clear the input field
        ui->userInput->clear();
    }
}

void ChatDialog::sendMessageToGemini(const QString &message) {
    // Construct the request
    QUrl url("https://generativelanguage.googleapis.com/v1/models/gemini-1.5-flash:generateContent?key=AIzaSyArxf6hX6trMWEssvbPPBzOne9I3sn__K4"); // Replace with the correct endpoint
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Create the JSON payload with the prompt
    QJsonObject messagePart;
    messagePart["text"] = message;

    QJsonObject contentObject;
    contentObject["parts"] = QJsonArray { messagePart };

    QJsonObject requestBody;
    requestBody["contents"] = QJsonArray { contentObject };

    // Convert JSON object to QByteArray
    QJsonDocument jsonDoc(requestBody);
    QByteArray jsonData = jsonDoc.toJson();

    // Send the request
    QNetworkReply *reply = networkManager->post(request, jsonData);
    connect(reply, &QNetworkReply::finished, this, &ChatDialog::handleGeminiResponse);
}


void ChatDialog::handleGeminiResponse() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();

        if (jsonObject.contains("candidates")) {
            QJsonArray candidates = jsonObject["candidates"].toArray();

            // Check if the candidates array has a response
            if (!candidates.isEmpty()) {
                QJsonObject candidate = candidates[0].toObject();
                QString botResponse = candidate["text"].toString();

                // Ensure the bot response is not empty
                if (!botResponse.isEmpty()) {
                    // Display the bot response
                    ui->chatDisplay->append("Bot: " + botResponse);
                } else {
                    // Display a message if the bot response is empty
                    ui->chatDisplay->append("Bot: Empty response.");
                }
            } else {
                // If there are no candidates in the response
                ui->chatDisplay->append("Bot: No response from AI.");
            }
        } else {
            // If the response format is unexpected
            ui->chatDisplay->append("Bot: Unexpected response format.");
        }
    } else {
        // Handle network error
        ui->chatDisplay->append("Bot: Error - " + reply->errorString());
    }
    reply->deleteLater();
}
