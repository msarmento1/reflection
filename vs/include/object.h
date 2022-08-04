#pragma once

// Forward declaration
namespace vs {
class Type;
}  // namespace vs

namespace vs {
class Object {
 public:
  // virtual Int32 GetHashCode() const;
  Type GetType() const;
};
}  // namespace vs
