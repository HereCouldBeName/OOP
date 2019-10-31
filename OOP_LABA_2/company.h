#ifndef COMPANY_H
#define COMPANY_H

#include "boss.h"
#include "employee.h"

class Company {
private:
    Boss* boss;
    vector<Employee*> worker;
    string name;
    uint minSalary;
    uint maxEge;
    uint minUsefulness;
public:
    Company(const string& name, const uint salary, const uint age, const uint minusefulness, Boss& boss);
    uint getMinSalary();
    uint getMaxEge();
    void addEmployee(Employee &employee);
    uint getMinUsefulness();
    vector<Employee *> &getAllWorker();
    Boss &getBoss();
    void infoPeopleByName(const string& name, const string& surname, const string& patronymic);
    const string& getName();
    bool findEmployee(const Employee &employee);
};

#endif // COMPANY_H
