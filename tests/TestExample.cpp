#include "TestExample.h"

#include <iostream>

void TestExample::exampleTest() {
    bool testSucceeded = 2 != 1;
    std::cout << "Has test succeeded: " << (testSucceeded ? "YES" : "NO");
}
