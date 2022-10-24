//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"
#include <stdio.h>
#include <iostream>

#define LOG_VAR(x)      printf("%s=%s\n", #x, x )

#define LOG(x)          printf("DEBUG: %s   -- at %s:%d\n", x, __FILE__, __LINE__)

#define SAFE_LOG(x)     do { printf("SAFE: %s   -- at %s:%d\n", x, __FILE__, __LINE__); } while(false)

using namespace std;



// -----------------------------
//
// My Test Go here 
// 
// -----------------------------


void testLogMacro() {
    std::cout << "Test LOG\n";
    const char *str1 = "testString1";

    LOG_VAR(str1);
    LOG("Another logging");
    SAFE_LOG("Testing");             // ken: this need to add semicolon
}


void test1() {
    std::cout << "Test1\n";
}



// -----------------------------
//
// Core Testing Functions 
// 
// -----------------------------
// For Single and Temp testing
void runSingleTest() {
    std::cout << "Run Single Test\n";
    
    testLogMacro();
    //test1();
    
    std::cout << "End of Single Test\n";
}

void runAllTest() {
    std::cout << "Run All Test\n";

    test1();
}

int main(int argc, char** argv) {
    printf("Running UnitTest: %d\n", argc);

    if(argc <= 1) {
        runSingleTest();
        return 0;
    }
    // std::cout << "Input: " <<  argv[1] << "\n";
    if(strcasecmp(argv[1], "all") == 0) {
        runAllTest();
    } else {
        runSingleTest();
    }

    return 0;
} 
