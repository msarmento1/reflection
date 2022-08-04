#pragma once

// Forward declaration
namespace vs {
class Type;
}  // namespace vs

namespace vs::reflection {
class ICustomAttributeProvider {
 public:
  virtual bool IsDefined(const Type& attributeType, bool inherit) = 0;
};
}  // namespace vs::reflection