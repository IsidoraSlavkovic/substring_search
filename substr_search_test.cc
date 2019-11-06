#include "substr_search.h"
#include "gtest/gtest.h"
#include "substr_search_factory.h"

class SubstrSearchTest : public ::testing::TestWithParam<const char *> {
 protected:
  SubstrSearchTest() : kEmptyString(), kDummyString("ASDFGH") {}

  void SetUp() {}
  void TearDown() {}

  const std::string kEmptyString;
  const std::string kDummyString;
};

TEST_P(SubstrSearchTest, ZeroLengthText) {
  auto search =
      SubstrSearchFactory::Create(GetParam(), kDummyString, kEmptyString);
  ASSERT_NE(search, nullptr);
  EXPECT_EQ(search->Search(), -1);
}

TEST_P(SubstrSearchTest, ZeroLengthPattern) {
  auto search =
      SubstrSearchFactory::Create(GetParam(), kEmptyString, kDummyString);
  ASSERT_NE(search, nullptr);
  EXPECT_EQ(search->Search(), 0);
}

TEST_P(SubstrSearchTest, RegularBehaviour) {
  {
    auto search = SubstrSearchFactory::Create(GetParam(), "bar", "barbara");
    ASSERT_NE(search, nullptr);
    EXPECT_EQ(search->Search(), 0);
  }
  {
    auto search = SubstrSearchFactory::Create(GetParam(), "bara", "barbara");
    ASSERT_NE(search, nullptr);
    EXPECT_EQ(search->Search(), 3);
  }
  {
    auto search = SubstrSearchFactory::Create(GetParam(), "bara", "barabara");
    ASSERT_NE(search, nullptr);
    EXPECT_EQ(search->Search(), 0);
  }
  {
    auto search = SubstrSearchFactory::Create(GetParam(), "yes", "nonoyes");
    ASSERT_NE(search, nullptr);
    EXPECT_EQ(search->Search(), 4);
  }
}

INSTANTIATE_TEST_SUITE_P(ParametrizedSubstrSearchTest, SubstrSearchTest,
                         testing::Values("brute_force", "boyer_moore",
                                         "rabin_karp", "kmp", "z"));

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}