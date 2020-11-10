#define _CRT_SECURE_NO_WARNINGS
#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <list>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;


typedef struct date{
    int year;
    int month;
    int day;
   
} Date;

typedef struct person{
    char name[64];
    Date dob;
    char email[64];
    char phone[14];


    static bool compareByName(const person& lhs, const person& rhs)
    {
        return (strcmp(lhs.name, rhs.name) < 0);
    }


    static bool compareByDate(const person& lhs, const person& rhs)
    {
        if (lhs.dob.year < rhs.dob.year)
            return true;
        else if (lhs.dob.year == rhs.dob.year && lhs.dob.month < rhs.dob.month)
            return true;
        else if (lhs.dob.year == rhs.dob.year && lhs.dob.month == rhs.dob.month && lhs.dob.day < rhs.dob.day)
            return true;
        else
            return false;
    }
} Person;

class Contact {
private:
    Person* persons;
    int total_num;
    Person str2person(char*);
    Date str2date(char*);
    list<Person> list1;
    list<Person>::iterator iter;
    vector<Person> vec;
    vector<Person>::iterator it;

public:
    Contact(int size) {
        total_num = 0;
        persons = new Person[size];
    }
    ~Contact() { 
        delete persons;
    }

    void retrieve(string);
    void Sort(int);
    void save();
    void insert(string, string, string, string);
    void remove(string);
    void load(string);
    void print();
};

#endif
