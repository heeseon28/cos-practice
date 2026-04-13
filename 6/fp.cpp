#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct human_st {
    const char *name;
    int age;
    void (*print)(struct human_st *);
} human_t;

void print_info1(human_t *h) {
    cout << "name: "<< h->name << " age: " << h->age << endl; 
}

void print_info2(human_t *h) {
    cout << "name: "<< h->name << endl; 
}

int main(int argc, char *argv[]){
    human_t *hw;

    hw = (human_t *)malloc(sizeof(human_t));
    hw->name = "Hyunwoo";
    hw->age = 40;
    hw->print = print_info2;

    hw->print(hw);

    return 0;
}
