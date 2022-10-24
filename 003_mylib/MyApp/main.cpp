#include <stdio.h>
#include <cmath>
#include <iostream>
#include <MyLib.h>

int main() {
    
    for(int i=0; i<20; i++) {
        int result = square(i);

        std::cout << "i=" << i << " square=" << result << "\n";
    }

    return 0;
}