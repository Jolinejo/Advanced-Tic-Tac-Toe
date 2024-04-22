
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void split_after_star(const string& s, string(&result)[2]);

string get_name(string username, string password)
{
    vector<string> users;
    string username;
    string password;
    string splitted_strings[2];
    fstream myfile;
    myfile.open("register.txt", ios::in); // reading from file

    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {
            users.push_back(line);
        }

        myfile.close(); // close the file once we have read all the lines

    }
    split_after_star(line, splitted_strings);
    if (username == splitted_strings[0] && password == splitted_strings[1])
    {
        return "Correct email and password!";
    }
    else {

        return "invalid email or password please try again";


    }

        for (const string& user : users)
        {
            split_after_star(user, splitted_strings);
            if (username == splitted_strings[0] && password == splitted_strings[1])
            {
                cout << "Correct username and password!" << endl;
                opened = true;
                break;
            }
        }

        if (!opened)
        {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }
    return 0;
}

void split_after_star(const string& s, string(&result)[2]) {
    size_t index = s.find('*');

    if (index != string::npos) {
        // Copy the substring before '*' into the first element of the array
        result[0] = s.substr(0, index);

        // Copy the substring after '*' into the second element of the array
        result[1] = s.substr(index + 1);
    }
    else {
        // If '*' is not found, copy the whole string into the first element of the array
        result[0] = s;
        // Set the second element of the array as an empty string
        result[1] = "";
    }
}
