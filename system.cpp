#include <iostream>
#include <fstream> //file handling
#include <sstream> // templates and types that enable interoperation between stream buffers and string objects.
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, password, name, age, user, username, word, word1;
    string creds[2], cp[2];

    cout << "Security System" << endl;
    cout << "--------------------------------" << endl;
    cout << "----------------Register---------------" << endl;
    cout << "----------------Login---------------" << endl;
    cout << "----------------Change Password---------------" << endl;
    cout << "----------------End program-------------------" << endl
         << endl;
    do{
        cout << endl
             << endl;
        cout << "Enter your choice:- ";
        cin>>a;
        switch(a){
            case 1:
                cout << "--------------------------------" << endl
                    << endl;
                cout << "Enter your username" << endl;
                cin >> user;
                cout << "Enter your password" << endl;
                cin >> pass;

                ofstream of1; // read the file
                of1.open("data.txt");
                if (of1.is_open())
                {
                    of1 << user << "\n";
                    of1 << pass;
                    cout << "Register Successfully" << endl;
                }
                break;
            case 2:
                i = 0;
                cout << "--------------------------------" << endl
                    << endl;
                ifstream if1;
                if1.open("data.txt");
                cout << "Please enter your username" << endl;
                cin >> username;
                cout << "Please enter your password" << endl;
                cin >> password;
                if (if1.is_open())
                {
                    while (!if1.eof())
                    {
                        while (getline(if1, text))
                        {
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if (username == creds[0] && password == creds[1])
                        {
                            cout << "Login successful" << endl;
                            cout << endl
                                << endl;
                        }
                        else
                        {
                            cout << endl
                                << endl;
                            cout << "Login failed, Enter correct details" << endl;
                            cout << "| 1. Press 2 to login |" << endl;
                            cout << "| 2. Press 3 to Change Password |" << endl;
                            break;
                        }
                }
            }

            break;
        case 3:

            ifstream if2;
            if2.open("data.txt");
            cout << "Enter your old Password" << endl;
            cin >> old;
            if (if2.is_open())
            {
                while (!if2.eof())
                {
                    while (getline(if1, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        cp[i] = word;
                        i++;
                    }

                    if (old == creds[1])
                    {
                        if2.close();
                        ofstream of2;
                        if (of1.is_open())
                        {
                            cout << "Enter your new password" << endl;
                            cin >> password1;
                            cout << "Renter your new password" << endl;
                            cin >> password2;

                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password changed" << endl;
                            }
                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Password entered incorrect" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Please enter a valid password" << endl;
                        break;
                    }
                }
            }
            break;
        case 4:
            cout << "-----------THE END-----------" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (a != 4);

    return 0;
}