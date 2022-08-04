#pragma once

#include <string>

#include "reflection/member_info.h"

namespace vs {
class Type : public reflection::MemberInfo {
 public:
  std::string Name;
  std::string HashCode;
};
}  // namespace vs