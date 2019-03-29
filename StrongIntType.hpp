#pragma once

#include <type_traits>

template<typename TypeId,
         typename IntegerValue,
         typename = std::enable_if_t<std::is_integral<IntegerValue>::value &&
                                     !std::is_same<IntegerValue, bool>::value>>
class StrongIntType final {
public:
    using ValueType = IntegerValue;

    constexpr StrongIntType() = default;
    constexpr explicit StrongIntType(ValueType v) noexcept : v{v} {}
    constexpr StrongIntType(const StrongIntType& s) noexcept : v{s.v} {}
    constexpr StrongIntType& operator=(const StrongIntType& s) noexcept {
        v = s.v;
        return *this;
    }
    constexpr explicit operator ValueType() const noexcept { return v; }
    constexpr ValueType value() const noexcept { return v; }

private:
    ValueType v;
};

template<typename TypeId, typename Value>
constexpr bool operator==(StrongIntType<TypeId, Value> lhs,
                          StrongIntType<TypeId, Value> rhs) noexcept {
    return lhs.value() == rhs.value();
}

template<typename TypeId, typename Value>
constexpr bool operator<=(StrongIntType<TypeId, Value> lhs,
                          StrongIntType<TypeId, Value> rhs) noexcept {
    return lhs.value() <= rhs.value();
}

template<typename TypeId, typename Value>
constexpr bool operator<(StrongIntType<TypeId, Value> lhs,
                         StrongIntType<TypeId, Value> rhs) noexcept {
    return lhs.value() < rhs.value();
}

template<typename TypeId, typename Value>
constexpr bool operator>=(StrongIntType<TypeId, Value> lhs,
                          StrongIntType<TypeId, Value> rhs) noexcept {
    return lhs.value() >= rhs.value();
}

template<typename TypeId, typename Value>
constexpr bool operator>(StrongIntType<TypeId, Value> lhs,
                         StrongIntType<TypeId, Value> rhs) noexcept {
    return lhs.value() > rhs.value();
}

template<typename TypeId, typename Value>
constexpr StrongIntType<TypeId, Value> operator+(StrongIntType<TypeId, Value> lhs,
                                                 StrongIntType<TypeId, Value> rhs) noexcept {
    return StrongIntType<TypeId, Value>{lhs.value() + rhs.value()};
}

template<typename TypeId, typename Value>
constexpr StrongIntType<TypeId, Value> operator-(StrongIntType<TypeId, Value> lhs,
                                                 StrongIntType<TypeId, Value> rhs) noexcept {
    return StrongIntType<TypeId, Value>{lhs.value() - rhs.value()};
}

template<typename TypeId, typename Value>
constexpr StrongIntType<TypeId, Value> operator*(StrongIntType<TypeId, Value> lhs,
                                                 StrongIntType<TypeId, Value> rhs) noexcept {
    return StrongIntType<TypeId, Value>{lhs.value() * rhs.value()};
}

template<typename TypeId, typename Value>
constexpr StrongIntType<TypeId, Value> operator/(StrongIntType<TypeId, Value> lhs,
                                                 StrongIntType<TypeId, Value> rhs) noexcept {
    return StrongIntType<TypeId, Value>{lhs.value() / rhs.value()};
}
