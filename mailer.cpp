#include "mailer.h"
#include "maintenance.h"
#include "mainwindow.h"
#include <QtNetwork>
#include <QDebug>
mailer::mailer()
{

}
int mailer::sendEmail(Maintenance* m){

    qDebug()<<"sslLibraryBuildVersionString: "<<QSslSocket::sslLibraryBuildVersionString();
    qDebug()<<"sslLibraryVersionNumber: "<<QSslSocket::sslLibraryVersionNumber();
    qDebug()<<"supportsSsl: "<<QSslSocket::supportsSsl();;
    qDebug()<<QCoreApplication::libraryPaths();


    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // Adjust this based on your SMTP server configuration
    QString username = "adembenali2004@gmail.com";
    QString password = "ooie phvc qant ftfy";



    // Sender and recipient information
    QString from = "adembenali2004@gmail.com";
    QString to = "adembenali2004@gmail.com";
    QString subject = "New Client !";
    QString body = QString("Client Name: %1\n\n"
                           "State: %2\n\n"
                           "Etat: %3\n\n"
                           "Date: %4\n\n"
                           "Departement: %5\n\n"
                           "Nombre De Personnes: %6\n\n"
                           "Nombre De Jour: %7\n\n"
                           "Summary: %8\n\n"
                           "Temp: %9\n\n")
                       .arg(m->getNomClient())      // Assuming getter methods exist in the Maintenance class
                       .arg(m->getState())
                       .arg(m->getEtat())
                       .arg(m->getDateM().toString("dd/MM/yyyy"))  // Format date as needed
                       .arg(m->getDepartement())
                       .arg(m->getNbPersonne())
                       .arg(m->getNbJour())
                       .arg(m->getSummary())
                        .arg(m->getTemp());
                                                                                                                                                                                          "Rayen Bahri\n";

    // Create a TCP socket
    QSslSocket socket;

    // Connect to the SMTP server
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error connecting to the server:" << socket.errorString();
        return -1;
    }

    // Wait for the greeting from the server
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Connected to the server.";

    // Send the HELO command
    socket.write("HELO localhost\r\n");
    socket.waitForBytesWritten();

    // Read the response from the server
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the authentication information
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the username
    socket.write(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the password
    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the MAIL FROM command
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the RCPT TO command
    socket.write("RCPT TO:<" + to.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the DATA command
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the email content
    socket.write("From: " + from.toUtf8() + "\r\n");
    socket.write("To: " + to.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("\r\n");  // Empty line before the body
    socket.write(body.toUtf8() + "\r\n");
    socket.write(".\r\n");  // End of email content
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the QUIT command
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Email sent successfully.";

    // Close the socket
    socket.close();
}
