#include "Company.h"

int main() {
    Person* Misha = new Person("Misha","Abramson","Yuryevich",40,2000);
    Person* Pavel = new Person("Pavel","Sville","Aleksandrovich",35,432);
    Person* Petr = new Person("Petr","Baranov","Anatolyevich",55,452);
    Person* Genadii = new Person("Genadii","Vanichev","Vyacheslavovna",65,8532);
    Person* Mikhail = new Person("Mikhail","Tkachenko","Valeryevna",45,6992);
    Person* Maksim = new Person("Maksim","Orlov","Victorovich",42,43242);
    Person* Egor = new Person("Egor","Korneev","Mikhaylovich",18,3000);
    Person* Ivan = new Person("Ivan","Ivanov","Vasilyevich",43,30000);

    Company* Microsoft = new Company("Microsoft",93213,32,*Misha);
    Company* Sky = new Company("Sky",51632,42,*Pavel);
    Company* Google = new Company("Google",64234,50,*Petr);
    Company* Yandex = new Company("Yandex",44241,48,*Genadii);
    Company* mail = new Company("mail",40211,32,*Mikhail);
    Company* Nike = new Company("Nike",9000,80,*Maksim);
    Company* Abibas = new Company("Abibas",5000,150,*Ivan);
    Company* Cleaning = new Company("Cleaning",50,150,*Ivan);

    Sky->SetHoliday(Pavel,true);

    Misha->AddJob(Yandex);
    Genadii->AddJob(Yandex);
    Petr->AddJob(Yandex);
    Egor->AddJob(Sky);
    Egor->AddJob(Abibas);
    Egor->AddJob(Microsoft);
    Egor->AddJob(Google);
    Egor->AddJob(Nike);
    Egor->AddJob(mail);
    Egor->AddJob(Cleaning);
    Egor->AddJob(Yandex);

    Yandex->setUsefulness(*Misha,10);
    Yandex->setUsefulness(*Genadii,95);
    Yandex->setUsefulness(*Petr,45);

    Abibas->InfoPersonByName(Egor->getName(),Egor->getSurname(),Egor->getPatronymic());
    cout << Cleaning->GetPersonByName(Ivan->getName(), Ivan->getSurname(),Ivan->getPatronymic())->getNumber_jobs() << endl;
    Yandex->Dismiss_Worker();
    Abibas->InfoPersonByName(Misha->getName(),Misha->getSurname(),Misha->getPatronymic());
}
