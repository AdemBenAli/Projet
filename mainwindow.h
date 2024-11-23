#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maintenance.h"
#include "chatdialog.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "mailer.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_supprimer_2_clicked();

    void on_ajouter_clicked();

    void on_annuler_clicked();

    void on_modifier_2_clicked();

    void on_recuperer_clicked();

    void on_trie_clicked();

    void on_recherche_clicked();

    void on_chatButton_clicked();

    void on_pdfButton_clicked();

    void on_btnPiecePhoto_clicked();

    void on_btnSubmit_clicked();

    void handleAiResponse();

    void on_trie1_clicked();

    void on_trie2_clicked();

private:
    Ui::MainWindow *ui;
    Maintenance m;
    ChatDialog *chatDialog;
    mailer mailerInstance;
    QString selectedPhotoPath;
    QNetworkAccessManager *networkManager;

};
#endif // MAINWINDOW_H
