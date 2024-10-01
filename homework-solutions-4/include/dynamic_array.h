#pragma once
#include <iostream>
#include <string>



namespace oop
{

    class DynamicArray
    {

        private:
            int* ptr;  ///< Pointer to the array
            int a_size;   ///< Size of the array
        public:

            /**
             * @brief Gets the size of the array.
             * @return The size of the array.
             */
            int size() {
                return this->a_size;
            }


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
