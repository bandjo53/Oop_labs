#include "mytemplates.h"
#include <iostream>

int main() {
    Container<int> test;
    test.add1(42);  // проверьте, всё ли работает
    test.info();
    return 0;
}