#include <cmath>
#include <cassert>
#include <ranges>
#include <algorithm>
#include <chrono>
#include <vector>
#include <iostream>

class Vec2D {
public:
    Vec2D(float x, float y) : x_{x}, y_{y} {}

    auto length_sqrd() const {
        return x_ * x_ + y_ * y_;
    }

    auto length() const {
        return std::sqrt(length_sqrd());
    }

private:
    float x_{};
    float y_{};
};

// slower
auto min_length_slow(const auto& r) -> float {
    assert(!r.empty());
    auto cmp = [](auto&& a, auto&& b) {
        return a.length() < b.length();
    };
    auto it = std::ranges::min_element(r, cmp);
    return it->length();
}

// faster
auto min_length_fast(const auto& r) -> float {
    assert(!r.empty());
    auto cmp = [](auto&& a, auto&& b) {
        return a.length_sqrd() < b.length_sqrd();
    };
    auto it = std::ranges::min_element(r, cmp);
    return it->length();
}

int main() {
    std::vector<Vec2D> points = {
        {3, 4}, {1, 1}, {2, 2}, {0, 5}
    };

    for (int i = 0; i < 1000; ++i) {
        points.emplace_back(i, i + 1);
    }

    constexpr int iterations = 10000;

    auto start_slow = std::chrono::high_resolution_clock::now();
    float result_slow = 0.0f;
    for (int i = 0; i < iterations; ++i) {
        result_slow += min_length_slow(points);
    }
    auto end_slow = std::chrono::high_resolution_clock::now();
    auto duration_slow = std::chrono::duration_cast<std::chrono::microseconds>(end_slow - start_slow).count();

    auto start_fast = std::chrono::high_resolution_clock::now();
    float result_fast = 0.0f;
    for (int i = 0; i < iterations; ++i) {
        result_fast += min_length_fast(points);
    }
    auto end_fast = std::chrono::high_resolution_clock::now();
    auto duration_fast = std::chrono::duration_cast<std::chrono::microseconds>(end_fast - start_fast).count();

    std::cout << "Slower min length (final value): " << result_slow / iterations << "\n";
    std::cout << "Faster min length (final value): " << result_fast / iterations << "\n";

    std::cout << "Slower total time: " << duration_slow << " µs\n";
    std::cout << "Faster total time: " << duration_fast << " µs\n";
}