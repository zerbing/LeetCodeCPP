#include "pch.h"
#include "source.h"
#include "gtest/gtest.h"

// 96. 不同的二叉搜索树
namespace N96
{
struct TestCase
{
  int input;
  int expectedOutput;
};

class N96SolutionTest : public ::testing::TestWithParam<TestCase>
{
public:
  Solution solution1;
  Solution2 solution2;
};

TEST_P(N96SolutionTest, HandlesInput)
{
  TestCase testCase = GetParam();

  int result1 = solution1.numTrees(testCase.input);
  EXPECT_EQ(result1, testCase.expectedOutput);

  int result2 = solution2.numTrees(testCase.input);
  EXPECT_EQ(result2, testCase.expectedOutput);
}

INSTANTIATE_TEST_CASE_P(
  TestWithParameters,
  N96SolutionTest,
  ::testing::Values(
    TestCase{ 1, 1 },
    TestCase{ 2, 2 },
    TestCase{ 3, 5 },
    TestCase{ 4, 14 },
    TestCase{ 5, 42 },
    TestCase{ 6, 132 },
    TestCase{ 7, 429 },
    TestCase{ 8, 1430 },
    TestCase{ 9, 4862 },
    TestCase{ 10, 16796 },
    TestCase{ 11, 58786 },
    TestCase{ 12, 208012 },
    TestCase{ 13, 742900 },
    TestCase{ 14, 2674440 },
    TestCase{ 15, 9694845 },
    TestCase{ 16, 35357670 },
    TestCase{ 17, 129644790 },
    TestCase{ 18, 477638700 },
    TestCase{ 19, 1767263190 }
  )
);
}

// 2085. 统计出现过一次的公共字符串
namespace N2085
{
class N2085SolutionTest : public ::testing::TestWithParam<std::tuple<std::vector<std::string>, std::vector<std::string>, int>>
{
public:
  Solution solution;
};

TEST_P(N2085SolutionTest, CountWordsReturnsExpected)
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
  N2085SolutionTest,
  ::testing::Values(
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry"}, std::vector<std::string>{"apple", "banana", "cherry"}, 3),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry", "apple"}, std::vector<std::string>{"apple", "banana", "cherry"}, 2),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry"}, std::vector<std::string>{"apple", "banana", "cherry", "apple"}, 2),
    std::make_tuple(std::vector<std::string>{"apple", "banana", "cherry", "apple"}, std::vector<std::string>{"apple", "banana", "cherry", "apple"}, 2)
  )
);
}

// 2670. 找出不同元素数目差数组
namespace N2670
{
TEST(N2670SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { -3, -1 ,1 ,3 ,5 };
    EXPECT_EQ(solution.distinctDifferenceArray(input), expected);
  }
  {
    std::vector<int> input = { 3, 2, 3, 4, 2 };
    std::vector<int> expected = { -2, -1, 0, 2, 3 };
    EXPECT_EQ(solution.distinctDifferenceArray(input), expected);
  }
}
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(filter) = "*N96*";
  return RUN_ALL_TESTS();
}