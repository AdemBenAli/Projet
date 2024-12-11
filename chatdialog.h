#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

private slots:
    void sendMessage();
    void sendMessageToGemini(const QString &message); // Declaration for Gemini interaction
    void handleGeminiResponse(); // Declaration for handling Gemini responses

private:
    Ui::ChatDialog *ui;
    QNetworkAccessManager *networkManager; // Network manager for API calls
};

#endif // CHATDIALOG_H
