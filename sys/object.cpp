#include "sys/object.h"

#include "sys/type.h"

namespace sys {
Type Object::GetType() const { return Type(); }
}  // namespace sys