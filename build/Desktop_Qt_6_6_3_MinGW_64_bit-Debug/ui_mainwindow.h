/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QWidget *tab_10;
    QWidget *tab_11;
    QWidget *tab_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_12;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_18;
    QLabel *label_18;
    QPushButton *pushButton;
    QLabel *label_24;
    QWidget *tab_13;
    QTableWidget *tableWidget;
    QWidget *tab_14;
    QWidget *tab_15;
    QWidget *tab_16;
    QWidget *tab_3;
    QTabWidget *tabWidget_4;
    QWidget *tab_17;
    QWidget *tab_18;
    QWidget *tab_19;
    QWidget *tab_20;
    QWidget *tab_21;
    QWidget *tab_4;
    QTabWidget *tabWidget_5;
    QWidget *tab_22;
    QWidget *tab_23;
    QWidget *tab_24;
    QWidget *tab_25;
    QWidget *tab_26;
    QWidget *tab_5;
    QTabWidget *tabWidget_6;
    QWidget *tab_27;
    QWidget *tab_28;
    QWidget *tab_29;
    QWidget *tab_30;
    QWidget *tab_31;
    QWidget *tab_6;
    QTabWidget *tabWidget_7;
    QWidget *tab_32;
    QWidget *tab_33;
    QWidget *tab_34;
    QWidget *tab_35;
    QWidget *tab_36;
    QWidget *widget;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *widget_3;
    QLabel *label_5;
    QWidget *widget_4;
    QLineEdit *lineEdit_24;
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1173, 763);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(140, 70, 1031, 581));
        tabWidget->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white"));
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1021, 531));
        tabWidget_2->setIcon(QIcon("C:/Users/alakh/OneDrive/Bureau/2eme Project/Exemple/build/eyeOff.png"));
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color:red;"));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        tabWidget_2->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        tabWidget_2->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        tabWidget_2->addTab(tab_11, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName("tabWidget_3");
        tabWidget_3->setEnabled(true);
        tabWidget_3->setGeometry(QRect(-10, 0, 691, 471));
        tabWidget_3->setMouseTracking(false);
        tabWidget_3->setTabletTracking(false);
        tabWidget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);"));
        tabWidget_3->setDocumentMode(true);
        tabWidget_3->setTabsClosable(false);
        tabWidget_3->setMovable(false);
        tabWidget_3->setTabBarAutoHide(false);
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        lineEdit = new QLineEdit(tab_12);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 100, 181, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("border:2px solid noir;\n"
"background-color:whitesmoke;\n"
"border-radius:10px"));
        label = new QLabel(tab_12);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 71, 31));
        label->setStyleSheet(QString::fromUtf8("background-color:none;"));
        label_2 = new QLabel(tab_12);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 140, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color:none;\n"
""));
        label_9 = new QLabel(tab_12);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(260, 140, 71, 31));
        label_9->setStyleSheet(QString::fromUtf8("background-color:none;"));
        lineEdit_5 = new QLineEdit(tab_12);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(30, 180, 181, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border:2px solid noir;\n"
"background-color:whitesmoke;\n"
"border-radius:10px"));
        lineEdit_2 = new QLineEdit(tab_12);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(260, 100, 181, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border:2px solid noir;\n"
"background-color:whitesmoke;\n"
"border-radius:10px"));
        lineEdit_9 = new QLineEdit(tab_12);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(260, 180, 181, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8("border:2px solid noir;\n"
"background-color:whitesmoke;\n"
"border-radius:10px"));
        lineEdit_18 = new QLineEdit(tab_12);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(30, 250, 181, 31));
        lineEdit_18->setStyleSheet(QString::fromUtf8("border:2px solid noir;\n"
"background-color:whitesmoke;\n"
"border-radius:10px"));
        label_18 = new QLabel(tab_12);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 210, 71, 31));
        label_18->setStyleSheet(QString::fromUtf8("background-color:none;"));
        pushButton = new QPushButton(tab_12);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 320, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:whitesmoke;\n"
"border:2px solid noir;\n"
"border-radius:10px;\n"
"color:black;"));
        label_24 = new QLabel(tab_12);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(260, 60, 111, 31));
        label_24->setStyleSheet(QString::fromUtf8("background-color:none;\n"
""));
        tabWidget_3->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        tableWidget = new QTableWidget(tab_13);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 20, 621, 341));
        tabWidget_3->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        tabWidget_3->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName("tab_15");
        tabWidget_3->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName("tab_16");
        tabWidget_3->addTab(tab_16, QString());
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget_4 = new QTabWidget(tab_3);
        tabWidget_4->setObjectName("tabWidget_4");
        tabWidget_4->setGeometry(QRect(90, 30, 391, 80));
        tab_17 = new QWidget();
        tab_17->setObjectName("tab_17");
        tabWidget_4->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName("tab_18");
        tabWidget_4->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName("tab_19");
        tabWidget_4->addTab(tab_19, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName("tab_20");
        tabWidget_4->addTab(tab_20, QString());
        tab_21 = new QWidget();
        tab_21->setObjectName("tab_21");
        tabWidget_4->addTab(tab_21, QString());
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget_5 = new QTabWidget(tab_4);
        tabWidget_5->setObjectName("tabWidget_5");
        tabWidget_5->setGeometry(QRect(80, 30, 391, 80));
        tab_22 = new QWidget();
        tab_22->setObjectName("tab_22");
        tabWidget_5->addTab(tab_22, QString());
        tab_23 = new QWidget();
        tab_23->setObjectName("tab_23");
        tabWidget_5->addTab(tab_23, QString());
        tab_24 = new QWidget();
        tab_24->setObjectName("tab_24");
        tabWidget_5->addTab(tab_24, QString());
        tab_25 = new QWidget();
        tab_25->setObjectName("tab_25");
        tabWidget_5->addTab(tab_25, QString());
        tab_26 = new QWidget();
        tab_26->setObjectName("tab_26");
        tabWidget_5->addTab(tab_26, QString());
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget_6 = new QTabWidget(tab_5);
        tabWidget_6->setObjectName("tabWidget_6");
        tabWidget_6->setGeometry(QRect(20, 30, 391, 80));
        tab_27 = new QWidget();
        tab_27->setObjectName("tab_27");
        tabWidget_6->addTab(tab_27, QString());
        tab_28 = new QWidget();
        tab_28->setObjectName("tab_28");
        tabWidget_6->addTab(tab_28, QString());
        tab_29 = new QWidget();
        tab_29->setObjectName("tab_29");
        tabWidget_6->addTab(tab_29, QString());
        tab_30 = new QWidget();
        tab_30->setObjectName("tab_30");
        tabWidget_6->addTab(tab_30, QString());
        tab_31 = new QWidget();
        tab_31->setObjectName("tab_31");
        tabWidget_6->addTab(tab_31, QString());
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget_7 = new QTabWidget(tab_6);
        tabWidget_7->setObjectName("tabWidget_7");
        tabWidget_7->setGeometry(QRect(60, 50, 391, 80));
        tab_32 = new QWidget();
        tab_32->setObjectName("tab_32");
        tabWidget_7->addTab(tab_32, QString());
        tab_33 = new QWidget();
        tab_33->setObjectName("tab_33");
        tabWidget_7->addTab(tab_33, QString());
        tab_34 = new QWidget();
        tab_34->setObjectName("tab_34");
        tabWidget_7->addTab(tab_34, QString());
        tab_35 = new QWidget();
        tab_35->setObjectName("tab_35");
        tabWidget_7->addTab(tab_35, QString());
        tab_36 = new QWidget();
        tab_36->setObjectName("tab_36");
        tabWidget_7->addTab(tab_36, QString());
        tabWidget->addTab(tab_6, QString());
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 120, 120, 521));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(93, 93, 93);"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 30, 91, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"border:2px solid Noir;\n"
"font-size:15px;\n"
"padding:3px;\n"
"color:noir;"));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 100, 91, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"border:2px solid Noir;\n"
"font-size:15px;\n"
"padding:3px;\n"
"color:noir;"));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 180, 91, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"border:2px solid Noir;\n"
"font-size:15px;\n"
"padding:3px;\n"
"color:noir;"));
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 390, 91, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"border:2px solid Noir;\n"
"font-size:15px;\n"
"padding:3px;\n"
"color:noir;"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::FolderNew")));
        pushButton_8->setIcon(icon);
        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(10, 440, 91, 31));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"border:2px solid Noir;\n"
"font-size:15px;\n"
"padding:3px;\n"
"color:noir;"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(140, 0, 1031, 51));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(93, 93, 93);"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(900, 10, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"font-size:20px;\n"
"font-weight:bold;\n"
""));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(850, 10, 31, 31));
        widget_4->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:15px;"));
        lineEdit_24 = new QLineEdit(widget_3);
        lineEdit_24->setObjectName("lineEdit_24");
        lineEdit_24->setGeometry(QRect(60, 10, 113, 28));
        lineEdit_24->setStyleSheet(QString::fromUtf8("background-color:rgb(217, 217, 217);\n"
"color:black;\n"
"border-radius:10px;\n"
"font-size:15px;\n"
"font-weight:bold;"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setEnabled(true);
        widget_2->setGeometry(QRect(0, 0, 120, 101));
        widget_2->setSizeIncrement(QSize(13, 0));
#if QT_CONFIG(statustip)
        widget_2->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        widget_2->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        widget_2->setAutoFillBackground(false);
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(93, 93, 93);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1173, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(4);
        tabWidget_5->setCurrentIndex(4);
        tabWidget_6->setCurrentIndex(0);
        tabWidget_7->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Personnels", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Taille", nullptr));
        lineEdit_5->setText(QString());
        lineEdit_18->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Prix d'achat", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", " id", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_13), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_14), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_15), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_16), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Stock", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_17), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_18), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_19), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_20), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_21), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Equipements", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_22), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_23), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_24), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_25), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_26), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "maintanice", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_27), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_28), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_29), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_30), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_31), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Pannes", nullptr));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_32), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_33), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_34), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_35), QCoreApplication::translate("MainWindow", "m4", nullptr));
        tabWidget_7->setTabText(tabWidget_7->indexOf(tab_36), QCoreApplication::translate("MainWindow", "m5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Factures", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Mailbox", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ala Khelil", nullptr));
        lineEdit_24->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
#if QT_CONFIG(tooltip)
        widget_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        widget_2->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
