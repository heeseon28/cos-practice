#include <iostream>
#include "human.h"
using namespace std;

Human::Human(const char *name, int age)
{
    cout << "Human constructor" << endl;
    this->name = name;
    this->age = age;
}

Human::Human(const char *name)
{
    cout << "Human constructor" << endl;
    this->name = name;
    this->age = 0;
}

const char *Human::getName()
{
    return this->name;
}

void Human::setAge(int age)
{
    this->age = age;
}

int Human::getAge()
{
    return this->age;
}

void Human::print()
{
    if (!this->age)
        cout << "Human) name: " << this->name << ", age: Unknown" << endl;
    else
        cout << "Human) name: " << this->name << ", age: " << this->age << endl;
}
