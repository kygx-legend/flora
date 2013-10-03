#include <iostream>
#include "SmartPointer.h"
using namespace std;

int main() {
    int *p1 = new int();
    *p1 = 11111;
    int *p2 = new int();
    *p2 = 22222;
    SmartPointer<int> sp1(p1), sp2(p2);
    SmartPointer<int> spa = sp1;
    sp2 = spa;
    return 0;
}
