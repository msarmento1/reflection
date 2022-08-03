#pragma once

#include <string>

#include "sys/reflection/member_info.h"

namespace sys {
class Type : public reflection::MemberInfo {
 public:
  std::string Name;
  std::string HashCode;
};
}  // namespace sys