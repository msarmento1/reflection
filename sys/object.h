#pragma once

// Forward declaration
namespace sys {
class Int32;
class Type;
}  // namespace sys

namespace sys {
class Object {
 public:
  virtual Int32 GetHashCode() const;
  Type GetType() const;
};
}  // namespace sys
