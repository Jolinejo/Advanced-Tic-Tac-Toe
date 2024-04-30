
#include <QtTest>
#include <QCoreApplication>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include "signin.h"

// Mock checkValid function for testing
int mockCheckValid(const std::string& username, const std::string& password) {
    if (username == "validuser" && password == "validpassword") {
        return 1; // Valid user
    } else {
        return 0; // Invalid user
    }
}

// Test signin constructor
void testSigninConstructor() {
    signin signIn(nullptr, "1");
    QVERIFY(signIn.ui->lineEdit_password->echoMode() == QLineEdit::Password);
}

// Test on_pushButton_login_clicked slot with valid credentials
void testPushButtonLoginValid() {
    signin signIn(nullptr, "1");
    signIn.ui->lineEdit_username->setText("validuser");
    signIn.ui->lineEdit_password->setText("validpassword");

    // Mock the checkValid function
    signIn.checkValid = mockCheckValid;

    QSignalSpy spy(&signIn, &signin::accepted);
    QVERIFY(spy.isValid());

    signIn.on_pushButton_login_clicked();
    QVERIFY(spy.wait());

    // Check if the correct message box is displayed
    QVERIFY(QMessageBox::information(nullptr, "login") == "username and password is correct");
}

// Test on_pushButton_login_clicked slot with invalid credentials
void testPushButtonLoginInvalid() {
    signin signIn(nullptr, "1");
    signIn.ui->lineEdit_username->setText("invaliduser");
    signIn.ui->lineEdit_password->setText("invalidpassword");

    // Mock the checkValid function
    signIn.checkValid = mockCheckValid;

    QSignalSpy spy(&signIn, &signin::accepted);
    QVERIFY(spy.isValid());

    signIn.on_pushButton_login_clicked();
    QVERIFY(spy.wait());

    // Check if the correct message box is displayed
    QVERIFY(QMessageBox::warning(nullptr, "login") == "username or password is invalid");
}

// Test on_pushButton_signup1_clicked slot
void testPushButtonSignupClicked() {
    signin signIn(nullptr, "1");

    QSignalSpy spy(&signIn, &signin::accepted);
    QVERIFY(spy.isValid());

    signIn.on_pushButton_signup1_clicked();
    QVERIFY(spy.wait());

    // Check if the signup dialog is opened
    QVERIFY(signIn.signup != nullptr);
}

// Test on_checkBox_showpassword_stateChanged slot
void testCheckBoxShowPasswordStateChanged() {
    signin signIn(nullptr, "1");
    signIn.ui->checkBox_showpassword->setChecked(true);
    QCOMPARE(signIn.ui->lineEdit_password->echoMode(), QLineEdit::Normal); // Password should be visible

    signIn.ui->checkBox_showpassword->setChecked(false);
    QCOMPARE(signIn.ui->lineEdit_password->echoMode(), QLineEdit::Password); // Password should be hidden
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QApplication app(argc, argv);

    // Run the tests
    testSigninConstructor();
    testPushButtonLoginValid();
    testPushButtonLoginInvalid();
    testPushButtonSignupClicked();
    testCheckBoxShowPasswordStateChanged();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
