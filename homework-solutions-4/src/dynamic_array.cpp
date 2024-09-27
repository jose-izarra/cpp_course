#include"dynamic_array.h"
#include<iostream>
#include<string>
#include<random>

using namespace oop;

namespace oop {

    DynamicArray createRandomArray(){
        static std::default_random_engine generator;
        static std::uniform_int_distribution<int> distribution(1,100);
        DynamicArray a(10);
        for(int i = 0; i < 10; i++){
        a[i] = distribution(generator);
        }
        return a;
    }
}

int main()
{

    DynamicArray a(10, 1); // 10 elements, all initialized to 1
    a[0] = 2; a[1] = 3;
    DynamicArray b = a; // Copy assignment operator
    DynamicArray c = createRandomArray(); // Move assignment operator
    DynamicArray d(b); // Copy constructor
    DynamicArray e(createRandomArray()); // Move constructor




    DynamicArray f = a + b; // Addition operator, concatenates the arrays

    std::cout << "A: " << a << std::endl; // Stream insertion operator
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "E: " << e << std::endl;
    std::cout << "F: " << f << std::endl;

    if(f.size() != a.size() + b.size()){
        std::cerr << "Error: size of f is not the sum of sizes of a and b" <<
        std::endl;
    }

    // All instances of the class will be deleted after main has run
    // This is because of its delete operator ~DynamicArray
    return 0;
}
