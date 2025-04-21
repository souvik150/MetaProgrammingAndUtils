#include <cmath>
#include <compare>
#include <iostream>
#include <ostream>

class LengthProxy {
public:
    LengthProxy(float x, float y) : squared_(x * x + y * y) {}

    bool operator==(const LengthProxy& other) const = default;
    auto operator<=>(const LengthProxy& other) const = default;

    friend auto operator<=>(const LengthProxy& proxy, float len) {
        return proxy.squared_ <=> (len * len);
    }

    //operator float() const {
    //    return std::sqrt(squared_);
    //}

    operator float() const && { return std::sqrt(squared_); }

private:
    float squared_{};
};

class Vec2D {
public:
    Vec2D(float x, float y) : x_{x}, y_{y} {}
    auto length() const {
        return LengthProxy{x_, y_};
    }
    float x_{};
    float y_{};
};

int main() {
    auto a = Vec2D{23, 42};
    auto b = Vec2D{33, 40};

    //auto len = a.length();
    //float fo = len;

    bool a_is_shortest = a.length() < b.length();

    std::cout<<a_is_shortest<<std::endl;

    auto c = Vec2D{23, 42};
    float len = c.length();

    std::cout<<len<<std::endl;
}