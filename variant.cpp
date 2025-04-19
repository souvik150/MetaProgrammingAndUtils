#include <iostream>
#include <string>
#include <variant>

int main() {
    using VariantType = std::variant<int, std::string, bool>;
    VariantType v{};

    std::cout << std::boolalpha;
    std::cout << "holds int: " << std::holds_alternative<int>(v) << std::endl;
    v = 7;
    std::cout << "holds int: " << std::holds_alternative<int>(v) << std::endl;
    v = std::string{"Jedi"};
    std::cout << "holds string: " << std::holds_alternative<std::string>(v) << std::endl;
    v = false;
    std::cout << "holds bool: " << std::holds_alternative<bool>(v) << std::endl;


    std::cout << "VariantType: = " << sizeof(VariantType) << std::endl;
    std::cout << "std::string: = " << sizeof(std::string) << std::endl;
    std::cout << "std::size_t: = " << sizeof(std::size_t) << std::endl;
}