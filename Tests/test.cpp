#include "pch.h"

// 87. 扰乱字符串
namespace n87
{
TEST(N87SolutionTest, HandlePositiveInput) {
  Solution solution;
  EXPECT_TRUE(solution.isScramble("great", "rgeat"));
  EXPECT_FALSE(solution.isScramble("abcde", "caebd"));
  EXPECT_TRUE(solution.isScramble("a", "a"));
}
}

// 96. 不同的二叉搜索树
namespace n96
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

// 213. 打家劫舍 II (中等)
namespace n213
{
TEST(N213SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input = { 2, 3, 2 };
    int expected = 3;
    EXPECT_EQ(solution.rob(input), expected);
  }
  {
    std::vector<int> input = { 1, 2, 3, 1 };
    int expected = 4;
    EXPECT_EQ(solution.rob(input), expected);
  }
  {
    std::vector<int> input = { 1, 2, 3 };
    int expected = 3;
    EXPECT_EQ(solution.rob(input), expected);
  }
}
}

// 264. 丑数 II (中等)
namespace n264
{
TEST(N264SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    int input = 10;
    int expected = 12;
    EXPECT_EQ(solution.nthUglyNumber(input), expected);
  }
  {
    int input = 1;
    int expected = 1;
    EXPECT_EQ(solution.nthUglyNumber(input), expected);
  }
}
}

// 309. 最佳买卖股票时机含冷冻期 (中等)
namespace n309
{
TEST(N309SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input = { 1, 2, 3, 0, 2 };
    int expected = 3;
    EXPECT_EQ(solution.maxProfit(input), expected);
  }
  {
    std::vector<int> input = { 1 };
    int expected = 0;
    EXPECT_EQ(solution.maxProfit(input), expected);
  }
}
}

// 321. 拼接最大数 (困难)
namespace n321
{
TEST(N321SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input1 = { 8, 9 };
    std::vector<int> input2 = { 3, 9 };
    int k = 3;
    std::vector<int> expected = { 9, 8, 9 };
    EXPECT_EQ(solution.maxNumber(input1, input2, k), expected);
  }
  {
    std::vector<int> input1 = { 3, 4, 6, 5 };
    std::vector<int> input2 = { 9, 1, 2, 5, 8, 3 };
    int k = 5;
    std::vector<int> expected = { 9, 8, 6, 5, 3 };
    EXPECT_EQ(solution.maxNumber(input1, input2, k), expected);
  }
  {
    std::vector<int> input1 = { 6, 7 };
    std::vector<int> input2 = { 6, 0, 4 };
    int k = 5;
    std::vector<int> expected = { 6, 7, 6, 0, 4 };
    EXPECT_EQ(solution.maxNumber(input1, input2, k), expected);
  }
}
}

// 375. 猜数字大小 II (中等)
namespace n375
{
TEST(N375SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    int input = 10;
    int expected = 16;
    EXPECT_EQ(solution.getMoneyAmount(input), expected);
  }
  {
    int input = 1;
    int expected = 0;
    EXPECT_EQ(solution.getMoneyAmount(input), expected);
  }
  {
    int input = 2;
    int expected = 1;
    EXPECT_EQ(solution.getMoneyAmount(input), expected);
  }
}
}

// 396. 旋转函数 (中等)
namespace n396
{
TEST(N396SolutionTest, HandlePositiveInput) {
  Solution solution;
  {
    std::vector<int> input = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int expected = 330;
    EXPECT_EQ(solution.maxRotateFunction(input), expected);
  }

  {
    std::vector<int> input = { 4, 3, 2, 6 };
    int expected = 26;
    EXPECT_EQ(solution.maxRotateFunction(input), expected);
  }
  {
    std::vector<int> input = { 100 };
    int expected = 0;
    EXPECT_EQ(solution.maxRotateFunction(input), expected);
  }
}

}

// 2085. 统计出现过一次的公共字符串
namespace n2085
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
namespace n2670
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
  ::testing::GTEST_FLAG(filter) = "*N321*";
  return RUN_ALL_TESTS();
}