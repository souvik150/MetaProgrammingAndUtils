#include <iostream>

template<typename T>
auto pow_n(const T& v, int n){
  auto product = T{1};
  for(int i=0; i<n; i++){
    product *= v;
  }
  return product;
}

template<typename T>
class Rectange {
public:
  Rectange(T x, T y, T w, T h) : x_{x}, y_{y}, w_{w}, h_{h} {};
  auto area() const {return h_*w_;}
  auto width() const {return w_;}
  auto height() const {return h_;}
private:
  T x_{}, y_{}, w_{}, h_{};
};

template<typename T>
auto is_square(const Rectange<T>&r){
  return r.height()==r.width();
}

template <int N, typename T>
auto const_pow_n(const T& v){
  auto product = T{1};
  for(int i=0; i<N; i++){
    product *= v;
  }
  return product;
}

int main(){
  auto x = pow_n(2.3f, 3);
  auto y = pow_n(3, 2);

  std::cout<<"x "<<x<<" y "<<y<<'\n';

  auto r1 = Rectange<float>{2.0f, 2.0f, 4.0f, 4.0f};

  std::cout<< "area " <<r1.area()<<'\n';
  std::cout<< "height " << r1.height()<<'\n';
  std::cout<< "width " <<r1.width()<<'\n';

  std::cout<< "is square " <<is_square(r1)<<'\n';

  std::cout<<const_pow_n<2>(3)<<'\n';
  std::cout<<const_pow_n<3>(3)<<'\n';

  return 0;
}