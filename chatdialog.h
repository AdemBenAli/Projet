#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog {
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

private slots:
    void sendMessage();

private:
    Ui::ChatDialog *ui;

    QString getBotResponse(const QString &message);
};

#endif // CHATDIALOG_H
