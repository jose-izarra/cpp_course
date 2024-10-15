// include/sum.h
#pragma once
#include <type_traits>
#include <iostream>
#include <tuple>

namespace homework{
    /**
    * @brief Metafunction for summing the elements of a vector holding
    elements of any type↪→
    * @param s The vector to sum
    * @param v The initial value of the sum
    * @tparam T The type of the elements in the vector
    * @return The sum of the elements in the vector, plus the initial value
    */
    template <typename Container, typename U = typename Container::value_type>
    U sum_elements(const Container& s, U v = U()) {
        // We will abstract the container type to be inferred by the compiler when the input is passed
        // This will allow it to work for other containers other than std::vector --- for the advanced milestone

        for (const auto& element: s) {
            v += element;
        }
        return v;
    }

    // template specialization for strings
    template <typename Container>
    std::string sum_elements(const Container& s, std::string v) {
        std::cout << "Elements of the vector: ";
        for (const std::string& element: s) {
            std::cout << element << ", " << std::endl;
            v += element;
        }
        return v;
    }

    template <typename... Args>
    auto make_tuple(Args&&... args) {
        return std::tuple<Args...>(std::forward<Args>(args)...);
    }

} // namespace homework
