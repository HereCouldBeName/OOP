#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>
using namespace  std;

class Company;

class Person {
private:
    string name;
    string surname;
    string patronymic;
    uint age;
    uint number_jobs;
    uint salary;

public:
    Person(const string& name, const string& surname,const string& patronymic, const uint age, const uint salary);
    const string& getName();
    const string& getSurname();
    const string& getPatronymic();
    uint getAge();
    uint getSalary();
    uint getNumber_jobs();
    void AddJob(Company& comp);
    void Add_Number_Jobs();
    bool operator==(const Person a) {
        if(age == a.age && name == a.name && surname == a.surname && patronymic == a.patronymic
                && number_jobs == a.number_jobs && salary == a.salary) {
            return true;
        } else {
            return false;
        }
    }
};

#endif // PERSON_H
