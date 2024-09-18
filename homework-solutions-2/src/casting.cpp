#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;



int main() {
    int i = 2;
    float c_cast = (float)i;
    float s_cast = static_cast<float>(i);

    cout << "i: " << i << endl;

    /*
        When using reinterpret_cast, 'reinterprets' whatever is at the memory location as if it was a float
        This means that an int w value of 2 has different value in bits than a float with value of 2.
        Therefore, we also need to reinterpret the memory that stores our variable.
        If we don't do this, we get unpredictable behavior, sometimes you do get the 2 value to output, along with other random stuff
        Since floats have more bits than integers, the random stuff is whatever was stored in memory after the int
    */

    float f_value = 2.0f;
    memcpy(&i, &f_value, sizeof(float));  // reinterprets space in memory to that of a float
    float* r_cast = reinterpret_cast<float*>(&i);

    cout << endl;
    // sets precision to one decimal in all the outputs
    cout << fixed << setprecision(1);
    cout << "i: " << i << endl; // this will output something weird because of what we talked about earlier
    cout << "c_cast: " << c_cast << endl;
    cout << "s_cast: " << s_cast << endl;
    cout << "r_cast: " << *r_cast << endl;

    return 0;
}
