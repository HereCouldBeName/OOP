#ifndef JODS_H
#define JODS_H

#include "Person.h"
#include "algorithm"

struct Worker {
    Person* people;
    uint usefulness;
    bool IsDirector;
    bool IsHoliday;
    uint salary;
};

class Company
{
private:
    vector<Worker> worker;
    string name;
    uint minSalary = 0;
    uint maxEge;
public:
    Company(const string& name, const uint salary, const uint age, Person& director);
    bool AcceptWorker(Person& people);
    void SetHoliday(Person* person, bool value);
    uint GetMinSalary();
    void InfoPersonByName(const string& name, const string& surname,const string& patronymic);
    Person* GetPersonByName(const string& name, const string& surname,const string& patronymic);
    string &GetName();
    void setUsefulness(Person& people, uint value);
    void Dismiss_Worker();
};

#endif // JODS_H
