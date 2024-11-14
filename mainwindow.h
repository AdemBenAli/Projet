#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maintenance.h"

#include <QMainWindow>

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
private:
    Ui::MainWindow *ui;
    Maintenance m;
};
#endif // MAINWINDOW_H
