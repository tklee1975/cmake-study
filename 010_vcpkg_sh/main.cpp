#include <stdio.h>
#include <cmath>
#include <iostream>
#include <fmt/core.h>


int main() {
    int var1 = 1;
    int8_t int8_a = 123;
    const char *hello = "Testing";

    fmt::print("var={} int8={} str={}\n", var1, int8_a, hello);

    return 0;
}
