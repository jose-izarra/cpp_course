//include/transform.h
#pragma once
#include <utility>
namespace homework {
    /**
    * @brief A function that transforms each element of a container in
    place.
    * @tparam Container The type of the container.
    * @tparam UnaryFunction The type of the function that transforms the elements.
    * @param container The container to transform.
    * @param function The function that transforms the elements.
    */
    template <typename Container, typename UnaryFunction>
    void transform(Container& container, UnaryFunction function) {
        for (auto& element: container) {
            element = function(element); // apply the function to the element
        }
    }


} // namespace homework
