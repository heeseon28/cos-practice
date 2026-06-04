#ifndef __FACULTY_H__
#define __FACULTY_H__

class Faculty
{
private:
    const char *id;
    int age;
    const char *name;

public:
    Faculty(const char *id, int age, const char *name);
    Faculty(const char *id, const char *name);
    const char *getID();
    void setID(const char *id);
    int getAge();
    void setAge(int age);
    const char *getName();
    void setName(const char *name);
    void print();
};

#endif /* __FACULTY_H__ */
