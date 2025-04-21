#include <string>
#include <algorithm> // for std::equal>
#include <cstdio>    // for printf

class String {
public:
    String() = default;
    String(std::string str) : str_(std::move(str)) {}
    std::string str_;
};

struct ConcatProxy {
    const std::string& a;
    const std::string& b;

    // Allows implicit conversion of ConcatProxy to a String (only on rvalue)
    operator String() && {
        return String{a + b};  // Concatenates a and b into a new String
    }
};

auto is_concate_equal(const std::string& a, const std::string& b, const std::string& c) -> bool {
    if (a.size() + b.size() != c.size()) return false;
    if (!std::equal(a.begin(), a.end(), c.begin())) return false;
    return std::equal(b.begin(), b.end(), c.begin() + a.size());
}

auto operator+(const String &a, const String &b) -> ConcatProxy {
    return ConcatProxy{a.str_, b.str_};
}

auto operator==(ConcatProxy concat, const String &c) -> bool {
    return is_concate_equal(concat.a, concat.b, c.str_);
}

int main() {
    auto a = String{"Hello"};
    auto b = String{"World"};
    auto c = String{"HelloWorld"};

    if ((a + b) == c) {
        printf("Concatenation matches\n");
    } else {
        printf("Does not match\n");
    }

    // Also test the conversion to String
    String d = std::move(a + b); // Uses operator String()
    printf("Result of move(a + b): %s\n", d.str_.c_str());
}
