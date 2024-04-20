#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;
public:
    User(const string& name, const string& pass) : username(name), password(pass) {}
    string getUsername() const {
        return username;
    }
    string getPassword() const {
        return password;
    }
};

vector<User> users; // Vector to store registered users

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;

    // Check if the username is already taken
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            cout << "Username already exists. Please choose a different one." << endl;
            return;
        }
    }

    cout << "Enter your password: ";
    cin >> password;

    // Create a new user with the entered username and password
    User newUser(username, password);
    users.push_back(newUser);

    // Write the new username and password to the file
    fstream outfile("register.txt", ios::out);
    if (outfile.is_open()) {
        outfile << username << "*" << password << endl;
        outfile.close();
        cout << "Registration successful! Welcome, " << username << "!" << endl;
    } else {
        cout << "Unable to open file to save user information." << endl;
    }
}

int main() {
    registerUser(); // Example usage of registerUser function

    return 0;
}
