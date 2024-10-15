// include/flexible_container.h
#pragma once
#include <vector>
#include <stdexcept>
#include <initializer_list>

namespace homework {
    /**
    * @brief A flexible container that can hold elements of any type.
    * @tparam T The type of the elements in the container with default type of int.
    */
    template <typename T=int>
    class FlexibleContainer {
        std::vector<T> container;
        public:
            /**
            * @brief Default constructor for an empty FlexibleContainer.
            */
            FlexibleContainer() = default;

            /**
            * @brief Constructor that initializes the container with an initializer list of elements.
            *
            * @param initial_values The initializer list of elements to add to the container.
            */
            FlexibleContainer(std::initializer_list<T> initial_values) {
                for (auto& element: initial_values) {
                    container.push_back(element);
                }
            }

            /**
            * @brief Adds an element to the container.
            *
            * @param value The element to add.
            */
            void add(const T& value) {
                container.push_back(value);
            }

            /**
            * @brief Retrieves an element at a specified index.
            *
            * @param i The index of the element to retrieve.
            * @return The element at the specified index.
            * @throws std::out_of_range if the index is out of bounds.
            */
            T get(size_t i) const{
                if (i >= container.size()) {
                    throw std::out_of_range("Index out of range");
                }
                return container[i];
            }

            /**
            * @brief Returns the number of elements in the container.
            *
            * @return The size of the container.
            */
            size_t size() const{
                return container.size();
            }

            /**
            * @brief Applies a given function to all elements in the container.
            *
            * @tparam Func The type of the transformation function.
            * @param function The function to apply to each element.
            */
            template <typename Function>
            void map(Function function) {
                for (auto& element: container) {
                    element = function(element);
                }
            }
    };
} // namespace homework
