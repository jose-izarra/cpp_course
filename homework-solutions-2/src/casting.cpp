#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;



int main() {
    int i = 2;
    float c_cast = (float)i;
    float s_cast = static_cast<float>(i);


    /*
        reinterpret_cast doesn't actually change the type (as in the previous types of casting)
        It changes the way the bit patterns are interpreted for the different types

        Therefore, 0x40000000 is the interpretation of the bit pattern for 2.0 as a float
        We can assume the bit pattern for 2.0 as an int would be different
    */

    // Bit pattern for 2.0 in IEEE 754 floating-point format
    int intForReinterpret = 0x40000000; // had to look this up
    float r_cast = *reinterpret_cast<float*>(&intForReinterpret);

    cout << endl;
    // sets precision to one decimal in all the outputs
    cout << fixed << setprecision(1);
    cout << "i: " << i << endl; // this will output something weird because of what we talked about earlier
    cout << "c_cast: " << c_cast << endl;
    cout << "s_cast: " << s_cast << endl;
    cout << "r_cast: " << r_cast << endl;

    return 0;
}
