//
//  CppTest.cpp
//  aTest
//
//  Created by kenlee on 26/3/2021.
//

#include "CppTest.hpp"
#include "TestHelper.h"
#include <iostream>
#include <vector>



// ------------------------------------------
void testCopyVector() {
    std::vector<int8_t> src(100);
    char data[] = "12345";
    for(char i : data) {
        src.push_back(i);
    }
    src.push_back('\0');
    
    std::string str;
    
    str.append(src.begin(), src.end());
    
    std::cout << "outString: " << str << "\n";
}

void testCasting() {
    std::cout << "Testing Casting\n";
    
    // Reference: C++ Crash Named Conversion Functions, P151
    // Sample Cast ing
    int intValue = 123;
    
    // To Short
    int8_t intValue_i8 = static_cast<int8_t>(intValue);         // OK
    float intValue_f = static_cast<float>(intValue);            // OK
    
    //char *intValue_ptr = static_cast<char *>(intValue);         // FAIL
    char *intValue_ptr = reinterpret_cast<char *>(intValue);      // OK, reinterpret_cast is very strong
    
    //
    int &intValueRef = intValue;
    // int8_t &intValueRef_i8 = static_cast<int8_t &>(intValueRef);    // NOT OKA
    
    std::vector<int8_t> buffer(3);
    buffer.push_back('a');
    buffer.push_back('b');
    PRINT_TYPE(buffer);
    
    PRINT_TYPE(buffer.data());
    
    // Const -> Not Consta
    const int &intConstRef = intValue;
    //int& nonConstRef = static_cast<int &>(intValue);     // OK??
    int& nonConstRef = const_cast<int &>(intValue);     // OK??
    nonConstRef = 222;
    std::cout << "nonConstRef: " << nonConstRef << "\n";
    std::cout << "intValue: " << intValue << "\n";
    
    //
    auto bufferDataType = buffer.data();
    PRINT_TYPE(bufferDataType);
    //char *pointer(buffer.data());
    //char *bufferPointer = static_cast<char *>(buffer.data());// NOT OK
    //char *bufferPointer = reinterpret_cast<char *>(&buffer[0]);//  OK
    std::cout << "PointerData: " << buffer.data() << "\n";
    
    std::vector<char>& bufferPointer = reinterpret_cast<std::vector<char>&>(buffer);// NOT OK
    std::cout << "PointerData: " << bufferPointer.data() << "\n";
    PRINT_TYPE(bufferPointer.data());
    
    std::string str;
    
    str.append(bufferPointer.data());
    
    std::cout << "str: " << str << "\n";
    //printf("%s", buffer.data());
    
    //const char *char_pointer2 = reinterpret_cast<char*>(buffer.data()); // OK
    // const char *char_pointer2 = const_cast<const char*>(buffer.data()); // OK
    
    
    //std::cout << "a: type: " << typeid(a).name() << "\n";
    //printf("%s", typeid(a).name());
    //PRINT_TYPE(a);
}

void testType() {
    std::cout << "Testing Casting\n";
    
    // Reference: C++ Crash Ch.4
    
    int intValue = 123;
    int8_t int8Value = 33;
    int16_t int16Value = 323;
    int32_t int32Value = 323;
    int64_t int64Value = 323;
    long longValue = 323;
    long long longlongValue = 323;
    char charValue = '\0';
    unsigned char ucharValue = '\0';
    
    
    std::string str;
    
    //std::cout << "a: type: " << typeid(a).name() << "\n";
    //printf("%s", typeid(a).name());
    std::cout << "Integral Type\n";
    
    PRINT_TYPE(intValue);
    PRINT_TYPE(int8Value);
    PRINT_TYPE(int16Value);
    PRINT_TYPE(int32Value);
    PRINT_TYPE(int64Value);
    PRINT_TYPE(longValue);
    PRINT_TYPE(longlongValue);
    PRINT_TYPE(charValue);
    PRINT_TYPE(ucharValue);
    
    PRINT_SEP;
    
    std::cout << "Const vs NonConst Type\n";
    int nonConstVal = 12345;
    const int constVal = 12345;
    
    PRINT_TYPE(nonConstVal);
    PRINT_TYPE(constVal);          
    
    
    
    
    PRINT_TYPE(str);
}

void testTypeName()
{
    const int value = 123;
    
    // Reference: https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
    
    //
   // std::cout << type_name<decltype(value)>() << '\n';
    
    std::cout << "decltype(i) is " << type_name<decltype(value)>() << '\n';
     
    auto autoValue = 2345;
    std::cout << "decltype(autoValue) is " << type_name<decltype(autoValue)>() << '\n';
    
    auto casted = static_cast<float>(value);
    std::cout << "decltype(casted) is " << type_name<decltype(casted)>() << '\n';
    
    //auto casted2 = reinterpret_cast<int>(value);
    auto casted2 = static_cast<int>(value);
    std::cout << "decltype(casted) is " << type_name<decltype(casted2)>() << '\n';
}

// ------------------------------------------

int main(int argc, char **argv)
{
    printf("Testing Cpp");
    
    testCopyVector();
    // testCasting();
    // testType();
    // testTypeName();
    
//
//    if (argc <= 1)
//    {
//        runSingleTest();
//        return 0;
//    }
//    // std::cout << "Input: " <<  argv[1] << "\n";
//    if (strcasecmp(argv[1], "all") == 0)
//    {
//        runAllTest();
//    }
//    else
//    {
//        runSingleTest();
//    }

    return 0;
}
