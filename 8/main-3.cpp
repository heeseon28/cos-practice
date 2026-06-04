#include <iostream>
#include "student.h"
#include "faculty.h"
using namespace std;

int main()
{
    cout << "h1 >>>" << endl;
    Human *h1 = new Student("Alice", 20, "20220001");
    cout << "h2 >>>" << endl;
    Student *h2 = new Student("Bob", 20, "20220002");
    cout << "h3 >>>" << endl;
    Human *h3 = new Human("Carol", 20);
    Student *h4 = (Student *)h1;
    Student *h5 = (Student *)h3;
    Faculty *hf1 = new Faculty("20221000", 20, "David");
    Human *h6 = (Human *)hf1;
    Student *h7 = (Student *)hf1;
    h1->print();
    h2->print();
    h3->print();
    h4->print();
    h5->print();
    h6->print();
    h7->print();
    return 0;
}
