#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
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

        // Get bot response
        QString botResponse = getBotResponse(userMessage);
        ui->chatDisplay->append("Bot: " + botResponse);

        // Clear input field
        ui->userInput->clear();
    }
}

QString ChatDialog::getBotResponse(const QString &message) {
    // Simple chatbot logic
    if (message.toLower().contains("hello")) {
        return "Hello! How can I assist you?";
    } else if (message.toLower().contains("help")) {
        return "I'm here to help! What do you need assistance with?";
    } else {
        return "I'm sorry, I didn't understand that.";
    }
}
