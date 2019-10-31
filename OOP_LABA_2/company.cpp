#include "company.h"

Company::Company(const string &name, const uint salary, const uint age, const uint minusefulness, Boss &boss) {
    this->name = name;
    this->minSalary = salary;
    this->maxEge = age;
    this->minUsefulness = minusefulness;
    boss.setBoss(*this);
    this->boss = &boss;
}

uint Company::getMinSalary() {
    return minSalary;
}

uint Company::getMaxEge() {
    return maxEge;
}

void Company::addEmployee(Employee &employee) {
    worker.push_back(&employee);
}

uint Company::getMinUsefulness() {
    return minUsefulness;
}

vector<Employee *>& Company::getAllWorker() {
    return worker;
}

Boss& Company::getBoss() {
    return *boss;
}

void Company::infoPeopleByName(const string &name, const string &surname, const string &patronymic) {
    if(boss->getName() == name && boss->getSurname() == surname && boss->getPatronymic() == patronymic) {
        cout<<"Person "<<name<<" "<<surname<<" "<<patronymic<<" work in company: "<<this->name << endl;
        cout<<"Job title: Boss"<<endl;
        cout<<"Salary: "<<boss->getSalary()<<endl;
        return;
    }
    for(auto& it: worker) {
        if(it->getName() == name && it->getSurname() == surname && it->getPatronymic() == patronymic) {
            cout<<"Person "<<name<<" "<<surname<<" "<<patronymic<<" work in company: "<<this->name << endl;
            cout<<"Job title: Worker"<<endl;
            cout<<"Usefulness: "<<it->getUsefulness()<<endl;
            cout<<"Salary: "<<it->getSalary()<<endl;
            return;
        }
    }
    cout << "No member " << name << " " << surname << " " << patronymic << " in company " << this->name <<endl;
}

const string &Company::getName() {
    return name;
}

bool Company::findEmployee(const Employee &employee) {
    for(auto& it: worker) {
        if(*it == employee) {
            return true;
        }
    }
    return false;
}
