#pragma once

#include <optional>

#include "sys/object.h"

namespace sys {
template <typename T>
class ValueType : public Object {
 protected:
  std::optional<T> value_;

 public:
  operator T() const { return value_.value_or(0); }
};
}  // namespace sys
