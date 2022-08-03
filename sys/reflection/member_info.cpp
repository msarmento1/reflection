#include "sys/reflection/member_info.h"

#include "sys/type.h"

namespace sys::reflection {
bool MemberInfo::IsDefined(const Type& attributeType, bool inherit) {
  return false;
}
}  // namespace sys::reflection