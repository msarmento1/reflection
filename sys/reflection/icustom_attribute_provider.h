#pragma once

// Forward declaration
namespace sys {
class Type;
}  // namespace sys

namespace sys::reflection {
class ICustomAttributeProvider {
 public:
  virtual bool IsDefined(const Type& attributeType, bool inherit) = 0;
};
}  // namespace sys::reflection