#ifndef DIAGNOSTIQUE_H
#define DIAGNOSTIQUE_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>



class Diagnostique {
public:
    Diagnostique();

private slots:
    void choosePhoto();       // Slot to handle photo selection
    void submitPhoto();       // Slot to handle photo submission
    void handleAiResponse();  // Slot to process the API response

private:
    QString selectedPhotoPath;              // Holds the path to the selected photo
    QNetworkAccessManager *networkManager;  // Handles network requests

};


#endif // DIAGNOSTIQUE_H
