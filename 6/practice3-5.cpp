#include <iostream>
using namespace std;

extern "C" int decode1(long* x, long* y, long* z);

int main(){
    long x, y, z;
    x = 10000; y = 20000; z = 30000;
    cout << "before decode1(): " << "x: " << x << " y: " << y << " z: " << z << endl;
    decode1(&x, &y, &z);
    cout << "after decode1(): " << "x: " << x << " y: " << y << " z: " << z << endl;
    return 0;
}
