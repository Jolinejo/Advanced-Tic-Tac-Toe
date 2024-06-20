#include "mainwindow.h"
#include "usermanager.h"
#include <QApplication>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>

// Function to load Qt stylesheet
void loadStyleSheet() {
    QFile file(":/users/Wstartpage.qss");
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Failed to open file:" << file.errorString();
    } else {
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }
}

// Main function
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Load Qt stylesheet
    loadStyleSheet();

    // Load users and initialize main window
    UserManager userManager;
    userManager.loadUsers();
    MainWindow w;
    w.resize(500, 500);

    ::testing::InitGoogleTest(&argc, argv);

    RUN_ALL_TESTS();
    return a.exec(); // Run Qt event loop
}
