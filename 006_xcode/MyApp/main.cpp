#include <stdio.h>
#include <cmath>
#include <iostream>
#include <MyLib.h>

int main() {
    
    for(int i=0; i<20; i++) {
        float result = square(i * 1.0);
        std::cout << "## i=" << i << " result=" << result << "\n";
    }

    return 0;
}