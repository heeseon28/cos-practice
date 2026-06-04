#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "human.h"

class Student : public Human
{
private:
    const char *id;

public:
    Student(const char *name, int age, const char *id);
    Student(const char *name, int age);
    const char *getStudentID();
    void setStudentID(const char *id);
    void print();
};

#endif /* __STUDENT_H__ */
