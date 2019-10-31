#include "people.h"


People::People(const string &name, const string &surname, const string &patronymic, const uint age, const uint salary) {
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->age = age;
    this->salary = salary;
}

const string &People::getName() {
    return name;
}

const string &People::getSurname() {
    return surname;
}

const string &People::getPatronymic() {
    return patronymic;
}

uint People::getSalary() {
    return salary;
}

uint People::getAge() {
    return age;
}
