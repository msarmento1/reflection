#pragma once

#include "object.h"
#include "reflection/icustom_attribute_provider.h"

namespace vs::reflection {
class MemberInfo : public Object, public ICustomAttributeProvider {
 public:
  bool IsDefined(const Type& attributeType, bool inherit) override;
};
}  // namespace vs::reflection