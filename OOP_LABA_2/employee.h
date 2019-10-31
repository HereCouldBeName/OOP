#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "people.h"

class Company;

class Employee : public People {
public:
    Employee(const string& name, const string& surname,const string& patronymic, const uint age, const uint salary);
    uint getUsefulness();
    void setUsefulness(uint value);
    uint getNumberJobs();
    void addJob(Company& comp);
    bool operator==(const Employee a) {
        if(age == a.age && name == a.name && surname == a.surname && patronymic == a.patronymic
                && number_jobs == a.number_jobs && salary == a.salary) {
            return true;
        } else {
            return false;
        }
    }
private:
    uint number_jobs;
    uint usefulness;
};

#endif // EMPLOYEE_H
