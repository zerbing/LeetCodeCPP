#include "pch.h"
#include "source.h"
#include "gtest/gtest.h"

namespace N2085
{
class SolutionTest : public ::testing::TestWithParam<std::tuple<std::vector<std::string>, std::vector<std::string>, int>>
{
public:
  Solution solution;
};

TEST_P(SolutionTest, CountWordsReturnsExpected)
{
  auto parameters = GetParam();
  auto words1 = std::get<0>(parameters);
  auto words2 = std::get<1>(parameters);
  auto expected = std::get<2>(parameters);

  auto result = solution.countWords(words1, words2);

  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
  TestWithParameters,
  SolutionTest,
  ::testing::Values(
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry"}, std::vector<std::string>{"apple", "banana", "cherry"}, 3),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry", "apple"}, std::vector<std::string>{"apple", "banana", "cherry"}, 2),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry"}, std::vector<std::string>{"apple", "banana", "cherry", "apple"}, 2),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry", "apple"}, std::vector<std::string>{"apple", "banana", "cherry", "apple"}, 2)
  )
);
}

namespace N2670
{
TEST(N2670Test, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { -3, -1 ,1 ,3 ,5 };
    EXPECT_EQ(solution.distinctDifferenceArray(input), expected);
  }
  {
    std::vector<int> input = { 3, 2, 3, 4, 2 };
    std::vector<int> expected = { -2, 1, 0, 2, 3 };
  }
}
}

