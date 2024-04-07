#include "tbscalc.h"
#include "hello.h"

int main() {
    hello();
    PDSCHCalculator calculator;
    calculator.calculatePDSCH();
    return 0;
}

