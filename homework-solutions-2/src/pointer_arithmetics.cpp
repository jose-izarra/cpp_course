#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;




double vector_sum_val(vector<int> array) {
    auto sum = accumulate(array.begin(), array.end(), 0.0f);
    return sum;
}


double vector_sum_ref(const vector<int>& array) {
    auto sum = 0;
    for (auto& i: array) {
        sum += i;
    }
    return sum;
}


double vector_sum_ptr(int* ptr, int size) {
    if (size == 0) {
        // if the size of the vector is 0, probably means the vector doesn't exist, or hasn't been defined yet
        cerr << "error: size of the vector is zero " << endl;
    }

    double sum = 0;
    for (int i=0; i < size; i++) {
        // add the value stored at the ptr, using dereferencing
        sum += *ptr;
        // increase the ptr value to be able to access the next value
        ptr++;
    }

    return sum;
}

int main() {
    constexpr int size = 1000;
    vector<int> v(size);

    iota(v.begin(), v.end(), 0);

    std::cout<<vector_sum_val(v)<<std::endl;
    std::cout<<vector_sum_ref(v)<<std::endl;

    v.clear();
    auto* ptr = v.data();

    // auto* ptr = &v[0]; // This is equivalent
    std::cout<<vector_sum_val(v)<<std::endl;
    std::cout<<vector_sum_ptr(ptr, v.size())<<std::endl;



    return 0;
}
