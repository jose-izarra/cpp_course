// g++ -std=c++14 infinite_loop.cpp
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Database {
    unique_ptr<vector<int>> data = make_unique<vector<int>>(10000000);
};

class Rectangle {
    public:
        Rectangle() {
            cout << "Rectangle created" << endl;
        }
        ~Rectangle() {
            cout << "Rectangle destroyed" << endl;
        }
};

void fun() {
    // Rectangle* p = new Rectangle();
    unique_ptr<Rectangle> p = make_unique<Rectangle>(Rectangle()); // infinite loop "should" be safe to run now hehe
}

int main(){

    // Infinite Loop
    // while (1) fun();

    int i =0;
    while (i < 1000) {
        fun();
        i++;
    }

    return 0;
}
