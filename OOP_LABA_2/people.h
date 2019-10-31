#ifndef PEOPLE_H
#define PEOPLE_H

#include <bits/stdc++.h>
using namespace std;

class People {
public:
    People(const string& name, const string& surname,const string& patronymic, const uint age, const uint salary);
    const string& getName();
    const string& getSurname();
    const string& getPatronymic();
    uint getSalary();
    uint getAge();
protected:
    string name;
    string surname;
    string patronymic;
    uint age;
    uint salary;
};

#endif // PEOPLE_H
