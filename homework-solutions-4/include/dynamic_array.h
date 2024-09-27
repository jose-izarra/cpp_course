#pragma once
#include <iostream>
#include <string>



namespace oop
{


    /*
        to navigate and keep track of the state of the dynamic array we need a pointer and its size
        - the pointer pointing to the beginning of the array
        - size holds the amount of numbers in the array

        This will help us access its items and populate the array directly in memory
    */
    class DynamicArray
    {
        private:
            int* ptr;   // pointer
            int a_size;   // array size
        public:

            // returns the size of the array
            int size() {
                return this->a_size;
            }

            // Default Constructor
            DynamicArray() {
                this->a_size = 0;
                this->ptr = nullptr;
            };

            // One parameter Constructor
            DynamicArray(int size): a_size(size), ptr(new int[size]) {};

            // Two parameter constructor
            DynamicArray(int size, int value) {
                this->a_size = size;
                this->ptr = new int[size];
                for (int i = 0; i < size; i++) {
                    this->ptr[i] = value;
                }
            };

            // Move constructor
            DynamicArray(DynamicArray&& other) noexcept : a_size(0), ptr(nullptr) {
                // Steal the data
                ptr = other.ptr;
                a_size = other.a_size;

                // Leave 'other' in a valid state
                other.ptr = nullptr;
                other.a_size = 0;
            }

            // Destructor
            ~DynamicArray() {
                delete[] ptr;
            };

            // [] operator
            int& operator[](int index) {
                if (index >= this->a_size) {
                    std::cerr << "Cannot index element out of bounds" << std::endl;
                    exit(1);
                }
                return this->ptr[index];
            }

            // Copy Constructor
            DynamicArray(const DynamicArray& other) {
                a_size = other.a_size;
                ptr = new int[a_size];
                for (int i = 0; i < a_size; i++) {
                    ptr[i] = other.ptr[i];
                }
            }

            // Copy assignment operator
            DynamicArray operator=(DynamicArray& other) {
                if (this == &other) {
                    return *this;
                } // 1. Check for self-assignment

                delete[] ptr; // 2. Free existing resources

                a_size = other.a_size;
                ptr = new int[a_size]; // 3. Allocate new memory
                for (int i = 0; i < a_size; i++) {
                    ptr[i] = other.ptr[i]; // 4. Copy elements
                }

                return *this;
            }


            // Add operator
            DynamicArray operator+(const DynamicArray& other) const {
                // Create a new DynamicArray large enough to hold both arrays
                DynamicArray result(a_size + other.a_size);

                // Copy elements from the first array (this)
                for (int i = 0; i < a_size; ++i) {
                    result.ptr[i] = ptr[i];
                }

                // Copy elements from the second array (other)
                for (int i = 0; i < other.a_size; ++i) {
                    result.ptr[a_size + i] = other.ptr[i];
                }

                return result; // Return the new concatenated array
            }

            friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
                for (int i = 0; i < arr.a_size; i++) {
                    os << arr.ptr[i] << " ";
                }
                return os;
            }


    };
};

/*

Copy constructor
            DynamicArray(const DynamicArray& other) {
                this->array_size = other.array_size;
                this->ptr_array = new int[this->array_size];
                for (int i = 0; i < this->array_size; i++) {
                    this->ptr_array[i] = other.ptr_array[i];
                }
            };

            // Move constructor
            DynamicArray(DynamicArray&& other) {
                this->array_size = other.array_size;
                this->ptr_array = other.ptr_array;
                other.ptr_array = nullptr;
                other.array_size = 0;
            };


            // Add operator
            DynamicArray operator+(const DynamicArray& other) {
                DynamicArray new_array;
                new_array.array_size = this->array_size + other.array_size;
                new_array.ptr_array = new int[new_array.array_size];
                for (int i = 0; i < this->array_size; i++) {
                    new_array.ptr_array[i] = this->ptr_array[i];
                }
                for (int i = 0; i < other.array_size; i++) {
                    new_array.ptr_array[this->array_size + i] = other.ptr_array[i];
                }


                return new_array;
            };

            // allows for array indexing
            int& operator[](int index) {
                return this->ptr_array[index];
            };

            // Comparison operators
            bool operator==(const DynamicArray& other) {
                if (this->array_size != other.array_size) {
                    return false;
                }
                for (int i = 0; i < this->array_size; i++) {
                    if (this->ptr_array[i] != other.ptr_array[i]) {
                        return false;
                    }
                }
                return true;
            };

            // Inequality operator
            bool operator!=(const DynamicArray& other) {
                return !(*this == other);
            };

            // Stream insertion operator
            friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
                for (int i = 0; i < arr.array_size; i++) {
                    os << arr.ptr_array[i] << " ";
                }
                return os;
            }

            // Copy assingment operator
            DynamicArray& operator=(const DynamicArray& other) {
                if (this == &other) {
                    return *this;
                }
                this->array_size = other.array_size;
                this->ptr_array = new int[this->array_size];
                for (int i = 0; i < this->array_size; i++) {
                    this->ptr_array[i] = other.ptr_array[i];
                }
                return *this;
            };

            // Move assignment constructor
            DynamicArray (DynamicArray& other): array_size(other.array_size), ptr_array(other.ptr_array) {
                other.array_size = 0;
                other.ptr_array = nullptr;
            }


            // Move assignment operator
            DynamicArray& operator=(DynamicArray&& other) noexcept {
                if (this != &other) {
                    ptr_array = other.ptr_array;
                    array_size = other.array_size;
                    other.ptr_array = nullptr;
                    other.array_size = 0;
                }

                return *this;
            };


*/
