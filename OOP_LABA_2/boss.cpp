#include "boss.h"
#include "employee.h"
#include "company.h"

Boss::Boss(const string &name, const string &surname, const string &patronymic, const uint age, const uint salary)  : People(name, surname, patronymic, age, salary) {
    isholiday = false;
}

bool Boss::acceptWorker(Employee &employee) {
    if(isholiday) {
        cout << "Director of the company " << comp->getName() << " " << name << " on holiday" << endl;
        return false;
    }
    if(employee.getAge() > comp->getMaxEge()) {
        cout << employee.getName() << " old to work in the company " << comp->getName() << endl;
        return false;
    }
    this->comp->addEmployee(employee);
    return true;
}

void Boss::setBoss(Company& comp) {
    this->comp = &comp;
}

void Boss::SetHoliday(bool value) {
    this->isholiday = value;
}

void Boss::setUsefulness(Employee& employee, uint value) {
    employee.setUsefulness(value);
}

void Boss::Dismiss_Worker() {
    for(auto it = this->comp->getAllWorker().begin(); it != this->comp->getAllWorker().end();) {
        if(this->comp->getMinUsefulness() > (*it)->getUsefulness()) {
            this->comp->getAllWorker().erase(it);
        } else {
            it++;
        }
    }
}
