#include <iostream>
#include "student.h"
using namespace std;

Student::Student(const char *name, int age, const char *id)
    : Human(name, age)
{
    cout << "Student constructor" << endl;
    this->setStudentID(id);
}

Student::Student(const char *name, int age)
    : Human(name, age)
{
    cout << "Student constructor" << endl;
    this->setStudentID(NULL);
}

// Please implement getStudentID() and setStudentID()

void Student::print()
{
    if (!this->id)
        cout << "Student) name: " << this->getName() << ", age: " << this->getAge() << ", id: unknown" << endl;
    else
        cout << "Student) name: " << this->getName() << ", age: " << this->getAge() << ", id: " << this->getStudentID() << endl;
}
