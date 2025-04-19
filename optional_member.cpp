#include <assert.h>
#include <optional>

struct Hat {};

class Head {
public:
    Head() {assert(!hat_);}
    auto set_hat(const Hat& hat) {
        hat_ = hat;
    }
    auto has_hat() const {
        return hat_;
    }
    auto& get_hat() const {
        assert(hat_.has_value());
        return *hat_;
    }
    auto remove_hat() {
        hat_ = {};
    }

private:
    std::optional<Hat> hat_;
};