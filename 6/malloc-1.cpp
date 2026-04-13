#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]){
    int *p;
    int i;

    p = (int *)malloc(sizeof(int) * 10);
    for (i=0; i<10; i++)
        p[i] = 10 - i;
    for (i=0; i<10; i++)
        cout << "p[" << i << "]= " << p[i] << endl;
    free(p); // 할당받은 공간을 반납하는 것.

    return 0;
}

// malloc은 동적으로 개발자의 요청으로 메모리 공간을 빌리는 것. 
