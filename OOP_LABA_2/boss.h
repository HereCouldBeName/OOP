#ifndef BOSS_H
#define BOSS_H

#include "people.h"

class Employee;
class Company;

class Boss : public People {
private:
    Company* comp;
    bool isholiday;
public:
    Boss(const string& name, const string& surname, const string& patronymic, const uint age, const uint salary);
    bool acceptWorker(Employee& employee);
    void setBoss(Company& comp);
    void SetHoliday(bool value);
    void setUsefulness(Employee &employee, uint value);
    void Dismiss_Worker();
};

#endif // BOSS_H
