#include <iostream>

auto pow_n(const auto& v, int n){
     auto product = decltype(v){1};
     for (int i=0; i<n; i++) { product *= v;}
     return product;
}


int main(){
  auto pow_n = []<class T>(const T& v, int n){
    auto product = T{1};
    for (int i=0; i<n; i++) { product *= v;}
    return product;
  };

  auto x = pow_n(2.3f, 3);
  auto y = pow_n(3, 2);

  std::cout << "x "<<x<<" y "<<y<<'\n';
  return 0;
}