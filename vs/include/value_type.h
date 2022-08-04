#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include "object.h"

namespace vs {
template <typename T>
class ValueType : public Object {
 protected:
  std::optional<T> value_;

 public:
  ValueType() = default;
  ValueType(const T& rhs) { value_ = rhs; }
  operator T() const { return value_.value_or(T()); }
  bool HasValue() const { return value_.has_value(); }

  // demangle here
};

using Int8 = ValueType<int8_t>;
using Int16 = ValueType<int16_t>;
using Int32 = ValueType<int32_t>;
using String = ValueType<std::string>;
}  // namespace vs
