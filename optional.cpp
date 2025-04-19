#include <iostream>
#include <optional>

struct Point {
    double x, y;
};

struct Line {
    double slope, y_intercept;
};

// Checks if two lines are parallel
auto lines_are_parallel(Line a, Line b) -> bool {
    return a.slope == b.slope;
}

// Assumes lines are not parallel
auto compute_intersection(Line a, Line b) -> Point {
    double x = (b.y_intercept - a.y_intercept) / (a.slope - b.slope);
    double y = a.slope * x + a.y_intercept;
    return Point{x, y};
}

auto get_intersection(const Line a, const Line b) -> std::optional<Point> {
    if (!lines_are_parallel(a, b)) {
        return std::optional{compute_intersection(a, b)};
    } else {
        return std::nullopt;
    }
}

void set_magic_point(Point p) {
    std::cout << "Magic Point set to (" << p.x << ", " << p.y << ")\n";
}

int main() {
    Line line0{-1.0, 1.0}; // y = 2x + 1
    Line line1{-1.0, 4.0}; // y = -x + 4

    auto intersection = get_intersection(line0, line1);
    if (intersection.has_value()) {
        set_magic_point(intersection.value());
    } else {
        std::cout << "Lines are parallel. No intersection.\n";
    }

    return 0;
}
