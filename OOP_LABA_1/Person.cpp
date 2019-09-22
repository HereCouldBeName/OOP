#include "Person.h"
#include "Company.h"

Person::Person(const string& name, const string& surname,const string& patronymic, const uint age, const uint salary) {
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->age = age;
    this->salary = salary;
}

const string &Person::getName()
{
    return name;
}

const string &Person::getSurname()
{
    return surname;
}

const string &Person::getPatronymic()
{
    return patronymic;
}

uint Person::getAge()
{
    return age;
}

uint Person::getSalary()
{
    return salary;
}

uint Person::getNumber_jobs()
{
    return number_jobs;
}

void Person::AddJob(void* allworks)
{
    Company* comp = (Company*)allworks;
    if(comp->GetMinSalary() < salary) {
        cout <<"I want more!! ("<<comp->GetName()<<")"<<endl;
        return;
    }
    if(number_jobs >= 5) {
        cout<<"I have so more work...\n";
        return;
    }
    comp->AcceptWorker(*this);
}

void Person::add_number_jobs()
{
    number_jobs++;
}
