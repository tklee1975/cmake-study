#include <stdio.h>
#include <cmath>
#include <iostream>
#include <MyLib.h>

int main() {
    
    for(int i=0; i<20; i++) {
        float result = square(i * 1.0);
        //std::string floatToStr(const float &value);
        std::string str = floatToStr(result);
        
        std::cout << "## i=" << i << " str=" << str << "\n";
    }

    return 0;
}