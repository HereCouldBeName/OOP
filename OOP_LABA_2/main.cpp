#include <bits/stdc++.h>
#include "boss.h"
#include "company.h"
using namespace std;

int main() { 
    Boss* Misha = new Boss("Misha","Abramson","Yuryevich",40,2000);
    Boss* Pavel = new Boss("Pavel","Sville","Aleksandrovich",35,432);
    Boss* Petr = new Boss("Petr","Baranov","Anatolyevich",47,452);
    Boss* Genadii = new Boss("Genadii","Vanichev","Vyacheslavovna",35,8532);
    Boss* Mikhail = new Boss("Mikhail","Tkachenko","Valeryevna",45,6992);
    Boss* Maksim = new Boss("Maksim","Orlov","Victorovich",42,43242);
    Boss* Egor = new Boss("Egor","Korneev","Mikhaylovich",18,3000);
    Boss* Ivan = new Boss("Ivan","Ivanov","Vasilyevich",43,30000);

    Employee* Yuri = new Employee("Yuri","Petrov","Anatolyevich",20,35000);
    Employee *Martin = new Employee("Martin", "Elder", "Mikhaylovich", 40, 25000);
    Employee *Mark = new Employee("Mark", "Wall", "Aleksandrovich", 19, 245562);
    Employee *Evan = new Employee("Evan", "Cake","Yuryevich", 56,5678);
    Employee *Zor = new Employee("Zor", "Brasco", "Vyacheslavovna", 18,2000);
    Employee *Alex = new Employee("Alex", "Johnson", "Anatolyevich", 18,5000);
    Employee *Lil = new Employee("Lil", "Elder", "Vasilyevich", 28,500);

    Company* Microsoft = new Company("Microsoft",93213,32,35,*Misha);
    Company* Sky = new Company("Sky",51632,42,25,*Pavel);
    Company* Google = new Company("Google",64234,50,30,*Petr);
    Company* Yandex = new Company("Yandex",44241,48,30,*Genadii);
    Company* mail = new Company("mail",40211,32,20,*Mikhail);
    Company* Nike = new Company("Nike",9000,80,10,*Maksim);
    Company* Abibas = new Company("Abibas",5000,150,5,*Egor);
    Company* Cleaning = new Company("Cleaning",50,150,0,*Ivan);

    Sky->getBoss().SetHoliday(true);
    Yuri->addJob(*Sky);

    Yuri->addJob(*Yandex);
    Mark->addJob(*Yandex);
    Evan->addJob(*Yandex);
    Martin->addJob(*Yandex);
    Zor->addJob(*Yandex);
    Alex->addJob(*Yandex);
    Lil->addJob(*Yandex);

    Zor->addJob(*Sky);
    Zor->addJob(*Abibas);
    Zor->addJob(*Microsoft);
    Zor->addJob(*Google);
    Zor->addJob(*Nike);
    Zor->addJob(*mail);
    Zor->addJob(*Cleaning);
    Zor->addJob(*Yandex);

    Genadii->setUsefulness(*Lil, 34);
    Genadii->setUsefulness(*Yuri, 50);
    Genadii->setUsefulness(*Martin, 25);
    Genadii->setUsefulness(*Zor, 18);
    Genadii->setUsefulness(*Alex, 60);

    Genadii->Dismiss_Worker();

    Yandex->infoPeopleByName(Alex->getName(),Alex->getSurname(), Alex->getPatronymic());
    Yandex->infoPeopleByName(Zor->getName(),Zor->getSurname(), Zor->getPatronymic());
    Yandex->infoPeopleByName(Yandex->getBoss().getName(),Yandex->getBoss().getSurname(), Yandex->getBoss().getPatronymic());
}
