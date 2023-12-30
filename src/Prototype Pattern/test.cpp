#include <iostream>
#include <string>
#include "Prototype.h"
using namespace potye;
#ifdef _WIN32
#include<Windows.h>
#endif
int main() {
#ifdef _WIN32
    SetConsoleCP(936);
    SetConsoleOutputCP(936);
#endif
    test_pototype();
    std::cin.get();
}
