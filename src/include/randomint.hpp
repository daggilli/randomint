#ifndef RANDOMINT_H__
#define RANDOMINT_H__
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>
#include <utility>

namespace RandomInt {
#if __cpp_concepts
  template <typename IntegralType>
  concept Integral = std::is_integral<IntegralType>::value;

  template <Integral IntType>
#else
  template <typename IntType, typename = std::enable_if_t<std::is_integral<IntType>::value> >
#endif
  class RandomIntGenerator {
   public:
    RandomIntGenerator() = default;
    RandomIntGenerator(const IntType lower, const IntType upper) : lower{lower}, upper{upper} {}
    RandomIntGenerator(const RandomIntGenerator<IntType> &gen)
        : lower{gen.lower}, upper{gen.upper}, engine{gen.engine} {}
    RandomIntGenerator(RandomIntGenerator<IntType> &&gen) = default;
    RandomIntGenerator<IntType> &operator=(const RandomIntGenerator<IntType> &gen) = default;
    RandomIntGenerator<IntType> &operator=(RandomIntGenerator<IntType> &&gen) = default;

    IntType operator()() { return std::uniform_int_distribution<IntType>{lower, upper}(engine); }
    IntType operator()(const IntType low, const IntType upp) {
      return std::uniform_int_distribution<IntType>{low, upp}(engine);
    }

   private:
    IntType lower{std::numeric_limits<IntType>::min()};
    IntType upper{std::numeric_limits<IntType>::max()};
    std::mt19937 engine{std::random_device{}()};
  };

  using RandomInt8Generator = RandomIntGenerator<int8_t>;
  using RandomUint8Generator = RandomIntGenerator<uint8_t>;
  using RandomByteGenerator = RandomIntGenerator<uint8_t>;
  using RandomInt16Generator = RandomIntGenerator<int16_t>;
  using RandomUint16Generator = RandomIntGenerator<uint16_t>;
  using RandomInt32Generator = RandomIntGenerator<int32_t>;
  using RandomUint32Generator = RandomIntGenerator<uint32_t>;
  using RandomInt64Generator = RandomIntGenerator<int64_t>;
  using RandomUint64Generator = RandomIntGenerator<uint64_t>;
};  // namespace RandomInt

#endif
