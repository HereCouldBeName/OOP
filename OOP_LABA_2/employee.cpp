#include "employee.h"
#include "company.h"

Employee::Employee(const string &name, const string &surname, const string &patronymic, const uint age, const uint salary) : People(name, surname, patronymic, age, salary) {
    number_jobs = 0;
}

uint Employee::getUsefulness() {
    return usefulness;
}

void Employee::setUsefulness(uint value) {
    usefulness = value;
}

uint Employee::getNumberJobs() {
    return number_jobs;
}

void Employee::addJob(Company& comp) {
    if(comp.findEmployee(*this)) {
        cout << name << " is already working in " << comp.getName() << " company" << endl;
        return;
    }
    if(comp.getMinSalary() < salary) {
        cout << name << " want more!! (" << comp.getName() << ")" << endl;
        return;
    }
    if(number_jobs >= 5) {
        cout << name << " have so more work..." << endl;
        return;
    }
    if(comp.getBoss().acceptWorker(*this)) {
        cout << name << " got a job in a company " << comp.getName() << endl;
        number_jobs++;
        return;
    }
}
