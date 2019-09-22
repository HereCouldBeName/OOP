#include "Company.h"

Company::Company(const string& name, const uint salary, const uint age, Person& director)
{
    this->name = name;
    this->minSalary = salary;
    this->maxEge = age;
    this->AcceptWorker(director);
}

bool Company::AcceptWorker(Person& people) {
    for(auto it = worker.begin(); it != worker.end(); it++) {
        if((*it).IsDirector) {
            if((*it).IsHoliday == true) {
                cout << "Director on holiday (" << name<<")"<<endl;
                return false;
            }
            if(people.getAge() > maxEge) {
                cout << "Man is too old (" << name<<")"<<endl;
                return false;
            }
            Worker NewWorker;
            NewWorker.people = &people;
            NewWorker.usefulness = 0;
            NewWorker.IsDirector = false;
            NewWorker.IsHoliday = false;
            NewWorker.salary = minSalary;
            worker.push_back(NewWorker);
            return true;
        }
    }
    Worker NewWorker;
    NewWorker.people = &people;
    NewWorker.usefulness = 100;
    NewWorker.IsDirector = true;
    NewWorker.IsHoliday = false;
    NewWorker.salary = minSalary * 5;
    worker.push_back(NewWorker);
    people.add_number_jobs();
    return true;
}

void Company::SetHoliday(Person* person, bool value) {
    for(auto it = worker.begin(); it != worker.end(); it++) {
        if((*(*it).people) == *person) {
            (*it).IsHoliday = value;
        }
    }
}

uint Company::GetMinSalary()
{
    return minSalary;
}

void Company::InfoPersonByName(const string& name, const string& surname,const string& patronymic)
{
    for(auto it = worker.begin(); it != worker.end(); it++) {
        if((*it).people->getName() == name && (*it).people->getSurname() == surname &&
                                            (*it).people->getPatronymic() == patronymic) {
            cout<<"Person "<<name<<" "<<surname<<" "<<patronymic<<" work in company: "<<this->name << endl;
            if((*it).IsDirector == true) {
                cout<<"Job title: Director"<<endl;
            } else {
                cout<<"Job title: Worker"<<endl;
            }
            cout<<"Usefulness: "<<(*it).usefulness<<endl;
            cout<<"Salary: "<<(*it).salary<<endl;
            return;
        }
    }
    cout<<"No member\n";
}

Person* Company::GetPersonByName(const string& name, const string& surname, const string& patronymic)
{
    for(auto it = worker.begin(); it != worker.end(); it++) {
        if((*it).people->getName() == name && (*it).people->getSurname() == surname &&
                                            (*it).people->getPatronymic() == patronymic) {
            return (it->people);
        }
    }
    return nullptr;
}

string &Company::GetName()
{
    return name;
}

void Company::setUsefulness(Person& people, uint value)
{
    for(auto it = worker.begin(); it != worker.end(); it++) {
        if((*(*it).people) == people) {
            (*it).usefulness = value;
        }
    }
}

void Company::Dismiss_Worker()
{
    uint min = worker[0].usefulness;
    vector<Worker>::iterator number = worker.begin() ;
    for(auto it = number + 1; it != worker.end(); it++) {
        if(min>(*it).usefulness) {
            min = (*it).usefulness;
            number = it;
        }
    }
    worker.erase(number);
}
