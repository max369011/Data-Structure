#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "contact.h"
#include <list>
//#include "list.h"

using namespace std;

void Contact::load(string file_name) {
    char c_str[1024];
    char in_line[1024];
    fstream inFile;
    total_num = 0;
    list1.clear();
    strcpy(c_str, file_name.c_str()); //copying string to c_str (char array)  cstr == filename
    inFile.open(file_name);

    while (inFile.getline(in_line, 1024)) {
        persons[total_num] = str2person(in_line);
        list1.push_back(persons[total_num]);
        total_num++;
    }

    if (inFile.is_open()) {
        cout << "Contact Loaded!" << endl;
    }
    else
        cout << "No such file" << endl;
}


Date Contact::str2date(char* str) {
    Date date;
    char temp[15];

    strncpy(temp, str, 4);
    temp[4] = 0;
    date.year = atoi(temp);

    strncpy(temp, str + 4, 2);
    temp[2] = 0;
    date.month = atoi(temp);

    strncpy(temp, str + 6, 3);
    temp[3] = 0;
    date.day = atoi(temp);
    return date;
}


void Contact::save() {
    ofstream file;
    string file_name;

    cout << "Enter file to save: ";
    cin >> file_name;

    file.open(file_name);

    for (iter = list1.begin(); iter != list1.end(); iter++) {
        file << iter->name << "; " << iter->dob.year << iter->dob.month << iter->dob.day << ";" << iter->email << ";" << iter->phone << endl;
    }
    
    cout << "Saved Contacts" << endl;
}

void Contact::insert(string name, string birthday, string email, string phone) {
    string line;
    char c_line[1024];

    line = name + "; " + birthday + "; " + email + "; " + phone;
    
    strcpy(c_line, line.c_str());
    persons[total_num] = str2person(c_line);
    list1.push_back(persons[total_num++]);
}

void Contact::remove(string name) {
    iter = list1.begin();
    bool found = false;
    while (iter != list1.end()) {
        if (iter->name == name) {
            iter = list1.erase(iter);
            found = true;
            cout << name <<" removed from contact!" << endl;
        } else
            iter++;
    }
    
    if(!found)
      cout << "No such person in contact!" << endl;
}

void Contact::retrieve(string input) {
    string value;
    bool found = false;

    for (iter = list1.begin(); iter != list1.end(); iter++) {
        if (iter->name == input) {
            cout << iter->name << "; " << iter->dob.year << iter->dob.month << iter->dob.day << ";" << iter->email << ";" << iter->phone << endl;
            found = true;
        }
        else if (iter->email == ' ' + input) {
            cout << iter->name << "; " << iter->dob.year << iter->dob.month << iter->dob.day << ";" << iter->email << ";" << iter->phone << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Not found" << endl;
}

void Contact::print() {
    for (iter = list1.begin(); iter != list1.end(); iter++) {
        cout << iter->name << "; " << iter->dob.year << iter->dob.month << iter->dob.day << ";" << iter->email << ";" << iter->phone << endl;
    }
    
}


void Contact::Sort(int num) {

    switch (num) {
    case 1:
        vec.resize(list1.size());
        copy(list1.begin(), list1.end(), vec.begin());
        sort(vec.begin(), vec.end(), person::compareByName);
        copy(vec.begin(), vec.end(), list1.begin());
        cout << "Contacts sorted by name!" << endl;
        break;

    case 2:
        vec.resize(list1.size());
        copy(list1.begin(), list1.end(), vec.begin());
        sort(vec.begin(), vec.end(), person::compareByDate);
        copy(vec.begin(), vec.end(), list1.begin());
        cout << "Contacts sorted by birthday!" << endl;
        break;

    default:
        cout << "Wrong input" << endl;
        break;
    
    }
}

Person Contact::str2person(char* person_name) {
    Person persons;
    char* token;
    char temp[64];
    int count = 0;

    token = strtok(person_name, ";");

    while (token) {
        strcpy(temp, token);
        switch (count) {
        case 0: strcpy(persons.name, temp); break;
        case 1: persons.dob = str2date(temp); break;
        case 2: strcpy(persons.email, temp);  break;
        case 3: strcpy(persons.phone, temp); break;
        }
        count++;
        token = strtok(NULL, ";");
    }
    return persons;
}
