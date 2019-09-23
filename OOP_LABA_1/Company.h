#ifndef JODS_H
#define JODS_H

#include "Person.h"
#include "algorithm"

class Person;

struct Worker {
    Person* people;
    uint usefulness;
    bool isdirector;
    bool isholiday;
    uint salary;
};

class Company
{
private:
    vector<Worker> worker;
    string name;
    uint minsalary = 0;
    uint maxege;
    uint minusefulness;
    bool CheckPeople(Person& people, const string& name, const string& surname,const string& patronymic);
    Worker CreateWorker(Person& people, uint usefulness, bool isdirector, bool isholiday, uint salary);
public:
    Company(const string& name, const uint salary, const uint age, const uint minusefulness, Person& director);
    bool AcceptWorker(Person& people);
    void SetHoliday(Person& person, bool value);
    uint GetMinSalary();
    void InfoPersonByName(const string& name, const string& surname, const string& patronymic);
    Person* GetPersonByName(const string& name, const string& surname, const string& patronymic);
    const string& GetName();
    void setUsefulness(Person& people, uint value);
    void Dismiss_Worker();
};

#endif // JODS_H
