#include <iostream>
#include <memory>

// g++ -std=c++14 resource_class.cpp


class Resource {
    int i; // introduced a variable to visualize which resource is deleted at which point
    public:
        Resource(int i) {
            std::cout << "Resource acquired: "<< i << std::endl;
        }

        ~Resource() {
            std::cout << "Resource destroyed: " << i << std::endl;
        }
};


std::unique_ptr<Resource> create_resource() {
    return std::make_unique<Resource>(Resource(1));
};


int main() {

    /*
        Output when commenting out definition of ptr_2
            Resource acquired: 1
            Resource destroyed: 1
            Resource destroyed: 1
    */
    // auto ptr_1 = create_resource();


    auto ptr_2 = Resource(2);

    /*
        Output when commenting out ptr_1
            Resource acquired: 2
            Resource destroyed: 79551440
    */

    return 0;
}
