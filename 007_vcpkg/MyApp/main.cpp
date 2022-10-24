#include <stdio.h>
#include <cmath>
#include <iostream>
#include <MyLib.h>
#include <fmt/core.h>


int main() {
    std::cout << "testing" << "\n'";
    for(int i=0; i<20; i++) {
        float result = square(i * 1.0);
        fmt::print("{} result: {}.\n", i, result);

        //std::cout << "## i=" << i << " result=" << result << "\n";
    }

    return 0;
}
