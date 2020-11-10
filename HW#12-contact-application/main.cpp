#include <iostream>
#include <string>
#include "contact.h"
#include <fstream>
using namespace std;

#define MAX_NUM 1000 // can be given by standard input

int main() {
    string file_name;
    Contact* contacts;
    contacts = new Contact(MAX_NUM);
    int cmd, num;
    bool running = true;
    string name, birthday, email, phone;

    while (running) {

        cout << "Enter command : (1) load  (2) save  (3) insert  (4) delete  (5) retrieve  (6) sort  (7) print  (8) exit" << endl;
        cin >> cmd;

        switch (cmd) {
        case 1:
            cout << "file name of contact data:" << endl;
            cin >> file_name;
            contacts->load(file_name);
            break;

        case 2:
            contacts->save();
            break;

        case 3:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter birthday: ";
            cin >> birthday;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter phone number: ";
            cin >> phone;
            contacts->insert(name, birthday, email, phone);
            break;

        case 4:
            cout << "Enter name you wish to delete: ";
            cin.ignore();
            getline(cin, name);
            contacts->remove(name);
            break;

        case 5:
            cout << "Enter name or email to retrieve: ";
            cin.ignore();
            getline(cin, name);
            contacts->retrieve(name);
            break;
         
        case 6:
            cout << "How would you like to sort by: (1) By name  (2) By birthday" << endl;
            cin >> num;
            contacts->Sort(num);
            break;

        case 7:
            contacts->print();
            break;

        case 8:
            cout << "Exited Contact Application" << endl;
            running = false;
            break;

        default:
            cout << "Wrong command input enter again" << endl;
            break;
        }
    }

    delete (contacts);
    return 0;
}