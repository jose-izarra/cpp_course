#include <iostream>


using namespace std;

void explode() {
    cout << "executing explode" << endl;
    int* ptr = nullptr;
    *ptr = 10;
}

class Buggy{
    int value = 0;

    public:
        Buggy(int value) {
            value = value;
        }

        void do_something() {
            auto mod = 123 % value;
            std::cout << "The remainder of 123 divided by value is " << mod << std::endl;
        }
};

int main() {
    Buggy b(10);
    cout << "b is declared" << endl;

    // explode is causing the bug by trying to dereference a nullptr

    // explode();
    // cout << "explode in main" << endl;

    b.do_something();
    cout << "do_somethin" << endl;

    return 0;
}
