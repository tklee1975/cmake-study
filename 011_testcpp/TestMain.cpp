//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"
#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>

#define LOG_VAR(x) printf("%s=%s\n", #x, x)

#define LOG(x) printf("DEBUG: %s   -- at %s:%d\n", x, __FILE__, __LINE__)

#define PRINT_VAR(_x_) do { std::cout << #_x_ << ": " \
                    << _x_ << " address: " \
                    << &_x_ << "\n"; } while(false)

#define PRINT_VAR_2(_x_) do { std::cout << #_x_ << ": " << _x_ \
                    << " address: " << &_x_  \
                    << " size: " << sizeof(_x_) << "\n"; \
                    } while(false)


#define SAFE_LOG(x)                                                \
    do                                                             \
    {                                                              \
        printf("SAFE: %s   -- at %s:%d\n", x, __FILE__, __LINE__); \
    } while (false)

#define PTR_IS_NULL(_x)  std::cout << #_x ": " << (_x ? "not null" : "null") << '\n';

using namespace std;

class NormalData
{
public:
    int myData;

    void display()
    {
        std::cout << "myData: " << myData << " addr=" << &myData << "\n";
    }
};

class NoCopyData
{
public:
    NoCopyData() = default;
    NoCopyData(const NoCopyData &) = delete;
    NoCopyData &operator=(const NoCopyData &) = delete;

    int myData;

    void display()
    {
        std::cout << "myData: " << myData << " addr=" << &myData << "\n";
    }
};

class TestData
{
public:
    TestData()
    {
        std::cout << "Constructor is called\n";
    }

    TestData(const TestData &)
    {
        std::cout << "Copy Constructor is called\n";
    }

    void operator=(const TestData &data)
    {
        std::cout << "Assign operator is called\n";
        myData = data.myData;
    }

    int myData;

    void display()
    {
        std::cout << "myData: " << myData << " addr=" << &myData << "\n";
    }
};

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    void operator=(const NonCopyable &) = delete;
};

class CantCopyData : private NonCopyable
{
public:
    int myData = 0;

    void display()
    {
        std::cout << "myData: " << myData << " addr=" << &myData << "\n";
    }
};

struct Position {
    int x;
    int y;
    Position(int _x, int _y):x(_x), y(_y){}
};

// https://en.cppreference.com/w/cpp/memory/unique_ptr
// https://ithelp.ithome.com.tw/articles/10213866
class UniqueCharBuffer
{
public:
    UniqueCharBuffer()
    {
    }

    void initData()
    {
        // int len = 10;
        // char *data = (char *) malloc(len);

        // for(int i=0; i<(len-1); i++) {
        //     data[i] = 'x';
        // }
        // data[len] = '\0';
        //_data = std::make_unique(data);
        //_data = std::unique_ptr<char *>(data);
    }

    void display()
    {
        // char *data = (char *) _data.get();
        // if(_data == nullptr) {
        //     std::cout << "data is null\n";
        //     return;
        // }
        // //std::cout << std::string(_data) << "\n";
        // //char * data = _data.get()

        // for(int i=0; i<9; i++) {
        //     printf("%d\n", data[i]);
        // }

        //printf("%s\n", (const char *) _data.get());
        // printf("%s",;; _data);
    }

private:
    std::unique_ptr<char *> _data;
    //std::unique_ptr<char *> _data;
};

// -----------------------------
//
// Helpers
//
// -----------------------------
void printIntUniquePtr(const char *name, const std::unique_ptr<int> &u) {
    std::cout << name;
    std::cout << ": " << (u ? "not null" : "null");
    if(u) {
        std::cout << " value=[" << *u << "]";
    }
    std::cout << "\n";
}

void printStrUniquePtr(const char *name, const std::unique_ptr<char *> &u) {
    std::cout << name;
    std::cout << ": " << (u ? "not null" : "null");
    if(u) {
        std::cout << " value=[" << u << "]";
    }
    std::cout << "\n";
}

void printPosition(const Position &pos) {
    std::cout << "(" << pos.x << ", " << pos.y << ")\n";
}

void pause() {
    cout << "Paused! press enter to continue\n";
    cin.ignore();           // Ref: https://stackoverflow.com/questions/903221/press-enter-to-continue
}

// -----------------------------
//
// My Test Go here
//
// -----------------------------
int sum(int input[3]) {
    PRINT_VAR_2(input);
 
    int fnResult = 0;
    
    for(int i=0; i<3; i++) {
        fnResult += input[i];
    }
    
    PRINT_VAR_2(fnResult);
    
    return fnResult;
}


// ----
struct Tracer {     // ken: from C++ Crash Page 97
private:
    const char* const _name;     // const xxx const mean cannot alter both address and content
public:
    Tracer(const char *name)
            : _name{name} {
        cout << name << " is constructed\n";
    }
    
    ~Tracer() {
        cout << _name << " is destructed\n";
    }
};



void testObjectCycle() {
    Tracer tracer("Tracer 1");

    std::vector<unique_ptr<Tracer>> tracerList1;
    std::vector<shared_ptr<Tracer>> tracerList2;
    
    //
    // pause();
    
    cout << "\nCreate an object inside a block scope\n";
    {
        Tracer tracerInBlock("Tracer in Block");
    }   // tracerInBlock is destructed here
    
    
    cout << "\nCreate an object pointer inside a block scope\n";
    {
        Tracer *trackerPtr = new Tracer("Tracer Raw Pointer");
    }   // trackerPtr not destructed here.. it is dangerous

    cout << "\nCreate an unqiue pointer inside a block scope\n";
    {
        unique_ptr<Tracer> uPtr = make_unique<Tracer>("Tracer Unique Pointer");
        //tracerList1.push_back(std::move(uPtr));     // this line make the sPtr destructed after pause
    }   // Cool, unique_ptr can be clean up when the block is ended

    cout << "\nCreate an shared pointer inside a block scope\n";
    {
        shared_ptr<Tracer> sPtr = make_shared<Tracer>("Tracer Shared Pointer");
        //tracerList2.push_back(sPtr);       // this line make the sPtr destructed after pause
    }   // Cool, shared_ptr can be clean up when the block is ended

    
    pause();
    cout << "Program End\n";
}


// ----
void testSizeAddress() {
    int a = 1;
    int *ptrA = &a;
    
    PRINT_VAR_2(a);
    PRINT_VAR_2(ptrA);
    
    int array[3] = {1, 2, 3};
    PRINT_VAR_2(array);
    PRINT_VAR_2(array[0]);      // Same address as array
    
    int result = sum(array);
    
    PRINT_VAR_2(result);
}

void testPRINT_VAR() {
    int a = 1;
    
    PRINT_VAR(a);
    
    int b = a;
    
    PRINT_VAR(b);
    
    int& c = a;
    
    PRINT_VAR(c);
    
    
    const char *str1 = "hello world";
    
    PRINT_VAR(str1);
    
    char *str2 = (char *)str1;
    PRINT_VAR(str2);
    // free(str2);     // this cause runtime error, freeing a stack memory
    
    char *str3 = (char *)malloc(strlen(str1));
    strcpy(str3, str1);
    PRINT_VAR(str3);
    free(str3);         // this can be free
    
    char array1[10]("23");
    PRINT_VAR(array1);
    //free(array1);       // it is at stack too?
    
    
}

void testStringUniqueStruct()
{
    Position pos(10, 20);
    
    printPosition(pos);             // ken: using type
    
    Position *posPtr = new Position(10, 30);        // using pointer
    printPosition(*posPtr);                            // de-reference posPtr
    delete posPtr;
     
    std::unique_ptr<Position> posPtrU(new Position(22, 33));   //
                        // ken: Position * ptr <-> unique_ptr<Position> ptr
    
    cout << "1: x: " << posPtrU->x << " y: " << posPtrU->y << "\n";
    PTR_IS_NULL(posPtrU);
    printPosition(*posPtrU);                            // de-reference smart posPtr
    
    // Using De-reference
    Position& pt = *posPtrU;
    cout << "2: x: " << pt.x << " y: " << pt.y << "\n";
    PTR_IS_NULL(posPtrU);
    
    Position pt2 = *posPtrU;
    cout << "3: x: " << pt2.x << " y: " << pt2.y << "\n";
    PTR_IS_NULL(posPtrU);
    
    Position *pt3 = posPtrU.get();
    cout << "4: x: " << pt3->x << " y: " << pt3->y << "\n";
    
    PTR_IS_NULL(posPtrU);
    cout << "1: x: " << posPtrU->x << " y: " << posPtrU->y << "\n";
    
    // Special
//    delete pt;    // Not allow
//    cout << "pointer of smarter pointer deleted\n";
//    PTR_IS_NULL(posPtrU);
    //
    
    posPtrU.release();
    cout << "PosPtrU released\n";
    PTR_IS_NULL(posPtrU);
    
    std::shared_ptr<Position> posPtrS(new Position(33, 55));   //
    PTR_IS_NULL(posPtrS);
    printPosition(*posPtrS);                            // de-reference smart posPtr
    posPtrS.reset();
    
}

void testStringUniquePtr()
{
//    std::unique_ptr<char *> u1;
//    printStrUniquePtr("u1", u1);
//
//    char *test = (char *) malloc(10);
//    strcpy(test, "testing");
//    std::unique_ptr<char *> u2(test);
//    printStrUniquePtr("u2", u2);
    
//    std::unique_ptr<char *> u2;
//    char *data = (char *) malloc(10);
//    data[0] = '\0';
//    auto x =std::unique_ptr<char *>(&data);
//    u2 = std::move(x);
//    printStrUniquePtr("u2", u2);
}


// Reference:
//      http://www.cplusplus.com/reference/memory/unique_ptr/unique_ptr/
//
void testStdUniquePtr()
{
    std::unique_ptr<int> u1;

    std::cout << "u1: " << (u1 ? "not null" : "null") << '\n';
    if(u1) {
        std::cout << u1 << "\n";
    }

    std::unique_ptr<int> u2(new int(1));

    std::cout << "u2: " << (u2 ? "not null" : "null") << '\n';
    if(u2) {
        std::cout << *u2 << "\n";
    }
    printIntUniquePtr("u2", u2);

    // std::cout << "Testing Move\n";
    std::unique_ptr<int> u3;
    
    printIntUniquePtr("u3", u3);
    u3 = std::move(u2);
    
    cout << "After Move\n";
    
    printIntUniquePtr("u2", u2);
    printIntUniquePtr("u3", u3);
    // std::cout << "After copy\n";
}

void testUniquePtr()
{
    UniqueCharBuffer a;

    cout << "Data a\n";
    a.initData();
    //a.myData = 1234;
    a.display();
}

//https://en.cppreference.com/w/cpp/utility/move
void testTestCantCopy()
{
    CantCopyData a;

    cout << "Data a\n";
    a.myData = 1234;
    a.display();

    // cout << "Data b (using =) \n";
    // CantCopyData b;
    // b = a;         // this cause errors now
    // b.display();

    // cout << "Data c (Using copy constructor) \n";
    // CantCopyData c(a);          // this cause errors now
    // c.display();
}

void testTestData()
{
    TestData a;
    cout << "test Copy\n";

    cout << "Data a\n";
    a.myData = 1234;
    a.display();

    cout << "Data b (using =) \n";
    TestData b;
    b = a;
    b.display();

    cout << "Data c (Using copy constructor) \n";
    TestData c(a);
    c.display();

    cout << "Data d (Also using copy constructor) \n";
    TestData d(a);
    d.display();
}

//https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-copyable_Mixin
// ken: we use to prevent a single resource (fd, sock, pt) used by someone else
void testNoCopy()
{
    NoCopyData a;
    cout << "test Copy\n";

    cout << "Data a\n";
    a.myData = 1234;
    a.display();

    cout << "Data b\n";
    //NoCopyData b = a;    // this cause errors now
    // NoCopyData b(a);        // this cause errors now
    // b.display();
}

void testCopy()
{
    NormalData a;
    cout << "test Copy\n";

    cout << "Data a\n";
    a.myData = 1234;
    a.display();

    cout << "Data b\n";
    NormalData b = a;
    b.display();
}

void testLogMacro()
{
    std::cout << "Test LOG\n";
    const char *str1 = "testString1";

    LOG_VAR(str1);
    LOG("Another logging");
    SAFE_LOG("Testing"); // ken: this need to add semicolon
}

void test1()
{
    std::cout << "Test1\n";
}

// -----------------------------
//
// Core Testing Functions
//
// -----------------------------
// For Single and Temp testing
void runSingleTest()
{
    std::cout << "Run Single Test\n";

    testObjectCycle();
    // testSizeAddress();
    // testPRINT_VAR();
    // testStringUniqueStruct();
    // testStringUniquePtr();
    // testStdUniquePtr();
    // testUniquePtr();
    // testTestCantCopy();
    // testTestData();
    // testNoCopy();
    // testCopy();
    // testLogMacro();
    //test1();

    std::cout << "End of Single Test\n";
}

void runAllTest()
{
    std::cout << "Run All Test\n";

    test1();
}

int main(int argc, char **argv)
{
    printf("Running UnitTest: %d\n", argc);

    if (argc <= 1)
    {
        runSingleTest();
        return 0;
    }
    // std::cout << "Input: " <<  argv[1] << "\n";
    if (strcasecmp(argv[1], "all") == 0)
    {
        runAllTest();
    }
    else
    {
        runSingleTest();
    }

    return 0;
}
