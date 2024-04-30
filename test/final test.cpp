
#include <QtTest>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "mainwindow.h"

// Mock User class for testing
class MockUser : public User {
public:
    MockUser(const std::string& username, const std::string& password)
        : User(username, password) {}
    std::string getUsername() const override { return m_username; }
    std::string getPassword() const override { return m_password; }
};

// Test registerUser function
void testRegisterUser() {
    QFile file("test_register.txt");
    QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Text));
    QTextStream out(&file);
    out << "existinguser*existingpassword\n";
    file.close();

    QVERIFY(registerUser("newuser", "newpassword") == 1); // Registration successful
    QVERIFY(registerUser("existinguser", "existingpassword") == 0); // Username already exists

    QFile::remove("test_register.txt");
}

// Test loadUsers function
void testLoadUsers() {
    QFile file("test_load_users.txt");
    QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Text));
    QTextStream out(&file);
    out << "user1*password1\n";
    out << "user2*password2\n";
    file.close();

    loadUsers();
    QVERIFY(users.size() == 2);
    QVERIFY(users[0].getUsername() == "user1");
    QVERIFY(users[0].getPassword() == "password1");
    QVERIFY(users[1].getUsername() == "user2");
    QVERIFY(users[1].getPassword() == "password2");

    QFile::remove("test_load_users.txt");
}

// Test checkValid function
void testCheckValid() {
    users.clear();
    users.push_back(MockUser("user1", "password1"));
    users.push_back(MockUser("user2", "password2"));

    QVERIFY(checkValid("user1", "password1") == 1); // Valid user
    QVERIFY(checkValid("user2", "password2") == 1); // Valid user
    QVERIFY(checkValid("user1", "wrongpassword") == 0); // Invalid password
    QVERIFY(checkValid("user3", "password3") == 0); // Invalid user
}

// Test main function
void testMain() {
    // Create a test directory
    QDir().mkdir("test_dir");
    QDir::setCurrent("test_dir");

    // Create a test registration file
    QFile file("test_register.txt");
    QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Text));
    QTextStream out(&file);
    out << "user1*password1\n";
    out << "user2*password2\n";
    file.close();

    // Create a test QSS file
    QFile qssFile("test_style.qss");
    QVERIFY(qssFile.open(QIODevice::WriteOnly | QIODevice::Text));
    QTextStream qssOut(&qssFile);
    qssOut << "body { color: red; }";
    qssFile.close();

    // Mock QApplication for testing
    int argc = 1;
    char *argv[1] = { (char*)"test_app" };
    QApplication a(argc, argv);

    // Run the main function
    main(argc, argv);

    // Check if users are loaded
    QVERIFY(users.size() == 2);
    QVERIFY(users[0].getUsername() == "user1");
    QVERIFY(users[0].getPassword() == "password1");
    QVERIFY(users[1].getUsername() == "user2");
    QVERIFY(users[1].getPassword() == "password2");

    // Check if style sheet is applied
    QVERIFY(a.styleSheet() == "body { color: red; }");

    // Clean up
    QDir::setCurrent("..");
    QDir("test_dir").removeRecursively();
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QCoreApplication app(argc, argv);

    // Run the tests
    testRegisterUser();
    testLoadUsers();
    testCheckValid();
    testMain();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
