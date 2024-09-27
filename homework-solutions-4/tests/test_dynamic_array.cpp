#include "gtest/gtest.h"
#include "dynamic_array.h"
#include<iostream>


using namespace oop;

TEST(DynamicArrayTest, ConstructorsTests) {
    DynamicArray a(10, 1); // 10 elements, all initialized to 1
    DynamicArray b(10); // 10 elements, all initialized to 0
    DynamicArray c; // 0 elements

    EXPECT_EQ(a.size(), 10);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[9], 1);

    EXPECT_EQ(b.size(), 10);
    EXPECT_EQ(b[0], 0);
    EXPECT_EQ(b[9], 0);

    EXPECT_EQ(c.size(), 0);
}


TEST(DynamicArrayTest, CopyConstructorTest) {
    // done by copilot
    DynamicArray a(10, 1); // 10 elements, all initialized to 1
    DynamicArray b(a); // Copy constructor

    EXPECT_EQ(a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(a[i], b[i]);
    }
}


TEST(DynamicArrayTest, MoveConstructorTest) {
    // done by copilot
    DynamicArray a(10, 1); // 10 elements, all initialized to 1
    DynamicArray b(std::move(a)); // Move constructor

    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(b.size(), 10);
    EXPECT_EQ(b[0], 1);
}


TEST(DynamicArrayTest, AdditionOperator) {
    DynamicArray a(10, 1); // 10 elements, all initialized to 1
    DynamicArray b(10, 2); // 10 elements, all initialized to 2
    DynamicArray c = a + b; // Addition operator, concatenates the arrays

    EXPECT_EQ(c.size(), 20);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(c[i], 1);
    }
    for (int i = 10; i < 20; i++) {
        EXPECT_EQ(c[i], 2);
    }

    EXPECT_EQ(c.size(), a.size() + b.size());

}
