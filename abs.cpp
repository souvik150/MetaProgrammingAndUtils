#include <iostream>
#include <limits>

template<int N>
struct AbsVal {
  static_assert(N != std::numeric_limits<int>::min());
  static constexpr int value = (N < 0) ? -N : N;
};

int main() {
  std::cout << AbsVal<5>::value << '\n';   // prints 5
  std::cout << AbsVal<-10>::value << '\n'; // prints 10
  // std::cout << AbsVal<std::numeric_limits<int>::min()>::value << '\n';
  return 0;
}
