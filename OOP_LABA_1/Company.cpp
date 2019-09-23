#include "Company.h"
#include "Person.h"

bool Company::CheckPeople(Person& people, const string &name, const string &surname, const string &patronymic)
{
    if(people.getName() == name && people.getSurname() == surname && people.getPatronymic() == patronymic) {
        return true;
    }
    return false;
}

Worker Company::CreateWorker(Person &people, uint usefulness, bool isdirector, bool isholiday, uint salary)
{
    Worker NewWorker;
    NewWorker.people = &people;
    NewWorker.usefulness = usefulness;
    NewWorker.isdirector = isdirector;
    NewWorker.isholiday = isholiday;
    NewWorker.salary = salary;
    return NewWorker;
}

Company::Company(const string& name, const uint salary, const uint age, const uint minusefulness, Person& director)
{
    this->name = name;
    this->minsalary = salary;
    this->maxege = age;
    this->minusefulness = minusefulness;
    this->AcceptWorker(director);
}

bool Company::AcceptWorker(Person& people) {
    for(auto& it: worker) {
        if(it.isdirector) {
            if(it.isholiday) {
                cout << "Director on holiday (" << name<<")"<<endl;
                return false;
            }
            if(people.getAge() > maxege) {
                cout << "Man is too old (" << name<<")"<<endl;
                return false;
            }
            worker.push_back(CreateWorker(people,0,false,false,minsalary));
            return true;
        }
    }
    worker.push_back(CreateWorker(people,100,true,false,minsalary*5));
    people.Add_Number_Jobs();
    return true;
}

void Company::SetHoliday(Person &person, bool value) {
    for(auto& it: worker) {
        if(*(it.people) == person) {
            it.isholiday = value;
        }
    }
}

uint Company::GetMinSalary()
{
    return minsalary;
}

void Company::InfoPersonByName(const string& name, const string& surname, const string& patronymic)
{
    for(auto& it: worker) {
        if(CheckPeople(*(it.people),name,surname,patronymic)) {
            cout<<"Person "<<name<<" "<<surname<<" "<<patronymic<<" work in company: "<<this->name << endl;
            if(it.isdirector == true) {
                cout<<"Job title: Director"<<endl;
            } else {
                cout<<"Job title: Worker"<<endl;
            }
            cout<<"Usefulness: "<<it.usefulness<<endl;
            cout<<"Salary: "<<it.salary<<endl;
            return;
        }
    }
    cout<<"No member\n";
}

Person* Company::GetPersonByName(const string& name, const string& surname, const string& patronymic)
{
    for(auto& it: worker) {
        if(CheckPeople(*(it.people),name,surname,patronymic)){
            return it.people;
        }
    }
    return nullptr;
}

const string &Company::GetName()
{
    return name;
}

void Company::setUsefulness(Person& people, uint value)
{
    for(auto& it: worker) {
        if(*(it.people) == people) {
            it.usefulness = value;
        }
    }
}

void Company::Dismiss_Worker()
{
    for(auto it = worker.begin(); it != worker.end();) {
        if(minusefulness > (*it).usefulness) {
            worker.erase(it);
        } else {
            it++;
        }
    }
}
