
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>

template <size_t Index, typename Tuple, typename Func>
void tuple_at(const Tuple& t, Func f) {
    const auto& v = std::get<Index>(t);
    std::invoke(f, v);
}

template <typename Tuple, typename Func, size_t Index=0>
void tuple_for_each(const Tuple& t, const Func& f) {
    constexpr auto n = std::tuple_size_v<Tuple>;
    if constexpr (Index < n) {
        tuple_at<Index>(t, f);
        tuple_for_each<Tuple, Func, Index + 1>(t, f);
    }
}

int main() {
    // auto t = std::tuple<int, std::string, bool>{};
    auto t2 = std::tuple{0, std::string{}, false};

    auto t3 = std::make_tuple(42, "ABC", true);

    auto a = std::get<0>(t3);
    auto b = std::get<1>(t3);
    auto c = std::get<2>(t3);

    std::cout << a << b << c << std::endl;

    auto t = std::tuple{1, true, std::string{"Jedi"}};
    tuple_for_each(t, [](const auto& v) {std::cout << v << " " << std::endl;});

    return 0;
}
