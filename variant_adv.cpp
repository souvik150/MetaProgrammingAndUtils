#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <variant>
#include <vector>

int main() {
    using VariantType = std::variant<int, std::string, bool>;
    auto container = std::vector<VariantType>{};

    container.push_back(false);
    container.push_back("I am a string");
    container.push_back("I am also a string");
    container.push_back(13);

    container.pop_back();
    std::reverse(container.begin(), container.end());

    for (const auto& v : container) {
        std::visit([](const auto& x) { std::cout << x << std::endl; }, v);
    }

    auto num_bools = std::count_if(container.begin(), container.end(), [](const auto& item) {
        return std::holds_alternative<bool>(item);
    });

    auto contains = std::any_of(container.begin(), container.end(), [](const auto& item) {
        return std::holds_alternative<std::string>(item) &&
               std::get<std::string>(item) == "I am a string";
    });

    std::cout << "Number of bools: " << num_bools << std::endl;
    std::cout << "Contains 'I am a string'? " << std::boolalpha << contains << std::endl;

    return 0;
}
