#include <iostream>
#include "faculty.h"
using namespace std;

Faculty::Faculty(const char *id, int age, const char *name)
{
    cout << "Faculty constructor" << endl;
    this->id = id;
    this->age = age;
    this->name = name;
}

Faculty::Faculty(const char *id, const char *name)
{
    cout << "Faculty constructor" << endl;
    this->id;
    this->name = name;
}

const char *Faculty::getID()
{
    return this->id;
}

// Please implement setter and getter functions

void Faculty::print()
{
    if (!this->age)
        cout << " Faculty) name: " << this->name << ", age: unknown, id: " << this->id << endl;
    else
        cout << "Faculty) name: " << this->name << ", age:" << this->age << ", id : " << this->id << endl;
}
