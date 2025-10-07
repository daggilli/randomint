#include <cstdint>
#include <iostream>
#include <randomint.hpp>

using RandByte = RandomInt::RandomByteGenerator;
using RandI32 = RandomInt::RandomInt32Generator;

int main() {
  auto rbyte = RandByte{0, 3};  // set tange to [lower, upper)
  std::cout << rbyte() << "\n";

  // we can use a different range with the same RNG instance
  std::cout << rbyte(15, 200) << "\n";

  // default constructor has range [0, max(this integral type)]
  auto ran32 = RandI32{};
  std::cout << ran32() << "\n";
  std::cout << ran32(1, 100) << "\n";

  // OK to copy
  auto ran32Copy(ran32);
  std::cout << ran32Copy() << "\n";
  std::cout << ran32Copy(-105, 200) << "\n";

  // won't compile because double doesn't satisfy template requirements
  // RandomInt::RandomIntGenerator<double> rfig(1, 10);

  return 0;
}
