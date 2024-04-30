
#include <QtTest>
#include <QCoreApplication>
#include <QLineEdit>
#include <QMessageBox>
#include "signup.h"

// Mock registerUser function for testing
int mockRegisterUser(const std::string& username, const std::string& password) {
    if (username == "newuser" && password == "newpassword") {
        return 1; // Registration successful
    } else {
        return 0; // User already exists
    }
}

// Test Signup constructor
void testSignupConstructor() {
    Signup signUp(nullptr);
    QVERIFY(signUp.ui->lineEdit_3->echoMode() == QLineEdit::Password);
}

// Test on_pushButton_sign_clicked slot with valid credentials
void testPushButtonSignValid() {
    Signup signUp(nullptr);
    signUp.ui->lineEdit_2->setText("newuser");
    signUp.ui->lineEdit_3->setText("newpassword");

    // Mock the registerUser function
    signUp.registerUser = mockRegisterUser;

    QSignalSpy spy(&signUp, &Signup::accepted);
    QVERIFY(spy.isValid());

    signUp.on_pushButton_sign_clicked();
    QVERIFY(spy.wait());

    // Check if the correct message box is displayed
    QVERIFY(QMessageBox::information(nullptr, "Registration") == "User registered successfully");
}

// Test on_pushButton_sign_clicked slot with invalid credentials
void testPushButtonSignInvalid() {
    Signup signUp(nullptr);
    signUp.ui->lineEdit_2->setText("existinguser");
    signUp.ui->lineEdit_3->setText("existingpassword");

    // Mock the registerUser function
    signUp.registerUser = mockRegisterUser;

    QSignalSpy spy(&signUp, &Signup::accepted);
    QVERIFY(spy.isValid());

    signUp.on_pushButton_sign_clicked();
    QVERIFY(spy.wait());

    // Check if the correct message box is displayed
    QVERIFY(QMessageBox::warning(nullptr, "Registration") == "User already exists");
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QApplication app(argc, argv);

    // Run the tests
    testSignupConstructor();
    testPushButtonSignValid();
    testPushButtonSignInvalid();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
