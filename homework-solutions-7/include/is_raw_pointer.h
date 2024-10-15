#pragma once



namespace homework {

    /**
     * @brief Primary template to determine if a type is a raw pointer.
     *
     * This primary template sets the `value` member to `false` for all non-pointer types.
     * Specializations of this template are provided to set `value` to `true` for raw pointer types.
     *
     * @tparam T The type to check.
     */
    template <typename T>
    struct IsRawPointer {
        static constexpr bool value = false;
    };

    /**
     * @brief Partial specialization of IsRawPointer for raw pointers.
     *
     * This specialization sets `value` to `true` for any type that is a raw pointer (T*).
     *
     * @tparam T The type to check (pointer type).
     */
    template <typename T>
    struct IsRawPointer<T*> {
        static constexpr bool value = true;
    };

    /**
    * @brief Partial specialization of IsRawPointer for const raw pointers.
    *
    * This specialization sets `value` to `true` for any type that is a const raw pointer (const T*).
    *
    * @tparam T The type to check (const pointer type).
    */
    template <typename T>
    struct IsRawPointer<const T*> {
        static constexpr bool value = true;
    };

    /**
     * @brief Helper variable template to check if a type is a raw pointer.
     *
     * This variable template provides a shorthand way to access `IsRawPointer<T>::value`.
     *
     * @tparam T The type to check.
     */
    template <typename T>
    constexpr bool IsRawPointer_v = IsRawPointer<T>::value;



} // namespace homework
