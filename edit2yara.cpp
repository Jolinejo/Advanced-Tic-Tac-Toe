
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


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

int main()
{
    bool opened = false;
    string username;
    string password;
    string splitted_strings[2];
    fstream myfile;
    myfile.open("yarayoyo.txt", ios::in); //reading from file
    if (myfile.is_open())
    {
        string line;
        while (!opened)
        {


            while(getline(myfile,line))
            {

            getline(myfile, line);
            cout << "--------enter username--------" << endl;
            cin >> username;
            cout << "--------enter password--------" << endl;
            cin >> password;
            split_after_star(line, splitted_strings);
            if (username == splitted_strings[0] && password == splitted_strings[1])
            {
                cout << "Correct username and password!" << endl;
                opened = true;
                break;
            }



        }

        if(!opened)
        {
            cout<<"invalid username or password please try again"<<endl;
        }
        // Reset the file pointer to read from the top again
    myfile.clear(); // Clear any error flags
    myfile.seekg(0, ios::beg); // Move the file pointer to the beginning



        }

    }



    return 0;
}















