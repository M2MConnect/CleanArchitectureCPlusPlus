#pragma once

#include <optional>
#include <stdexcept>
#include <utility>

namespace application::common {

template <typename TValue, typename TError>
class Result {
public:
    static Result success(TValue value) {
        return Result(std::move(value), std::nullopt);
    }

    static Result failure(TError error) {
        return Result(std::nullopt, std::move(error));
    }

    [[nodiscard]] bool hasValue() const noexcept {
        return value_.has_value();
    }

    [[nodiscard]] const TValue& value() const {
        if (!value_.has_value()) {
            throw std::logic_error("Result does not contain a value");
        }
        return *value_;
    }

    [[nodiscard]] const TError& error() const {
        if (!error_.has_value()) {
            throw std::logic_error("Result does not contain an error");
        }
        return *error_;
    }

private:
    Result(std::optional<TValue> value, std::optional<TError> error)
        : value_(std::move(value)),
          error_(std::move(error)) {
    }

    std::optional<TValue> value_;
    std::optional<TError> error_;
};

} // namespace application::common
