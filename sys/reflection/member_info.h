#pragma once

#include "sys/object.h"
#include "sys/reflection/icustom_attribute_provider.h"

namespace sys::reflection {
class MemberInfo : public Object, public ICustomAttributeProvider {
 public:
  bool IsDefined(const Type& attributeType, bool inherit) override;
};
}  // namespace sys::reflection