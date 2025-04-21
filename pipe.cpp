#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for std::find

template <typename T>
struct ContainsProxy { const T& value_; };  // <- Added semicolon

template <typename Range, typename T>
auto operator|(const Range& r, const ContainsProxy<T>& proxy) {
    const auto& v = proxy.value_;
    return std::find(r.begin(), r.end(), v) != r.end();
}

template <typename T>
auto contains(const T& v) { return ContainsProxy<T>{v}; }

int main() {
    auto penguins = std::vector<std::string>{"Ping", "Roy", "Silo"};

    if (penguins | contains("Silo")) {
        std::cout << "found silo\n";
    }
}
