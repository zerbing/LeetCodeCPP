#include "pch.h"

// 76. ��С�����Ӵ� (����)
namespace n76
{
class N76SolutionTest : public ::testing::Test {
protected:
  Solution solution;
};
TEST_F(N76SolutionTest, HandleNormalInput) {
  {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string expected = "BANC";
    EXPECT_EQ(solution.minWindow(s, t), expected);
  }
  {
    std::string s = "a";
    std::string t = "a";
    std::string expected = "a";
    EXPECT_EQ(solution.minWindow(s, t), expected);
  }
  {
    std::string s = "a";
    std::string t = "aa";
    std::string expected = "";
    EXPECT_EQ(solution.minWindow(s, t), expected);
  }
}
}

// 79. �������� (�е�)
namespace n79
{
class N79SolutionTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(N79SolutionTest, HandleNormalInput) {
  {
    std::vector<std::vector<char>> board = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    std::string word = "ABCCED";
    EXPECT_TRUE(solution.exist(board, word));
  }
  {
    std::vector<std::vector<char>> board = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    std::string word = "SEE";
    EXPECT_TRUE(solution.exist(board, word));
  }
  {
    std::vector<std::vector<char>> board = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    std::string word = "ABCB";
    EXPECT_FALSE(solution.exist(board, word));
  }
}
}

// 87. �����ַ��� (����)
namespace n87
{
TEST(N87SolutionTest, HandlePositiveInput) {
  Solution solution;
  EXPECT_TRUE(solution.isScramble("great", "rgeat"));
  EXPECT_FALSE(solution.isScramble("abcde", "caebd"));
  EXPECT_TRUE(solution.isScramble("a", "a"));
}
}

// 93. ��ԭIP��ַ (�е�)
namespace n93
{
class N93SolutionTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(N93SolutionTest, HandleNormalInput) {
  {
    std::string s = "25525511135";
    std::vector<std::string> expected = { "255.255.11.135", "255.255.111.35" };
    std::vector<std::string> actual = solution.restoreIpAddresses(s);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(actual, expected);
  }
  {
    std::string s = "0000";
    std::vector<std::string> expected = { "0.0.0.0" };
    std::vector<std::string> actual = solution.restoreIpAddresses(s);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(actual, expected);
  }
  {
    std::string s = "1111";
    std::vector<std::string> expected = { "1.1.1.1" };
    std::vector<std::string> actual = solution.restoreIpAddresses(s);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(actual, expected);
  }
  {
    std::string s = "010010";
    std::vector<std::string> expected = { "0.10.0.10","0.100.1.0" };
    std::vector<std::string> actual = solution.restoreIpAddresses(s);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(actual, expected);
  }
  {
    std::string s = "101023";
    std::vector<std::string> expected = { "1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3" };
    std::vector<std::string> actual = solution.restoreIpAddresses(s);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(actual, expected);
  }
}
}


// 96. ��ͬ�Ķ��������� (�е�)
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

// 213. ��ҽ��� II (�е�)
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

// 264. ���� II (�е�)
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

// 309. ���������Ʊʱ�����䶳�� (�е�)
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

// 321. ƴ������� (����)
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

// 375. �����ִ�С II (�е�)
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

// 396. ��ת���� (�е�)
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

// 581. ����������������� (�е�)
namespace n581
{
TEST(N581SolutionTest, HandleNormalInput) {
  Solution solution;
  {
    std::vector<int> input = { 2, 6, 4, 8, 10, 9, 15 };
    int expected = 5;
    EXPECT_EQ(solution.findUnsortedSubarray(input), expected);
  }
  {
    std::vector<int> input = { 1, 2, 3, 4 };
    int expected = 0;
    EXPECT_EQ(solution.findUnsortedSubarray(input), expected);
  }
  {
    std::vector<int> input = { 1 };
    int expected = 0;
    EXPECT_EQ(solution.findUnsortedSubarray(input), expected);
  }
}
}

// 2085. ͳ�Ƴ��ֹ�һ�εĹ����ַ��� (�е�)
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

// 2670. �ҳ���ͬԪ����Ŀ������ (�е�)
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

// LCP 30. ħ����Ϸ (�е�)
namespace lcp30
{
class LCP30SolutionTest : public ::testing::Test {
protected:
  Solution solution1;
  Solution2 solution2;
};

TEST_F(LCP30SolutionTest, HandlesNormalInput) {
  {
    std::vector<int> input = { 100, 100, 100, -250, -60, -140, -50, -50, 100, 150 };
    int expected = 1;
    EXPECT_EQ(solution1.magicTower(input), expected);
    EXPECT_EQ(solution2.magicTower(input), expected);
  }
  {
    std::vector<int> input = { -200, -300, 400, 500 };
    int expected = 2;
    EXPECT_EQ(solution1.magicTower(input), expected);
    EXPECT_EQ(solution2.magicTower(input), expected);
  }
  {
    std::vector<int> input = { 100, 100, 100, -10 };
    int expected = 0;
    EXPECT_EQ(solution1.magicTower(input), expected);
    EXPECT_EQ(solution2.magicTower(input), expected);
  }
}
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(filter) = "*N93*";
  return RUN_ALL_TESTS();
}