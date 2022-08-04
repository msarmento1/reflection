
#include <reflection/value_type.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Int32", "[Type][Int32]") {
  vs::Int32 i;

  REQUIRE_FALSE(i.HasValue());
  REQUIRE(i == 0);

  i = 2;

  REQUIRE(i.HasValue());
  REQUIRE(i == 2);

  i = {};

  REQUIRE_FALSE(i.HasValue());
  REQUIRE(i == 0);
}

TEST_CASE("String", "[Type][String]") {
  vs::String s;

  REQUIRE_FALSE(s.HasValue());
  // REQUIRE(s == "");

  // s = "abc";

  // REQUIRE(s.HasValue());
  // REQUIRE(s == "abc");

  // s = {};

  // REQUIRE_FALSE(s.HasValue());
  // REQUIRE(s == "");
}