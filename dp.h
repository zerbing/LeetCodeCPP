#pragma once

// 32. 最长有效括号 (困难)
namespace N32
{
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
class Solution {
public:
  int longestValidParentheses(string s) {
    int n = static_cast<int>(s.size());
    // dp[i] 表示以 s[i] **结尾**的最长有效括号的长度
    // 注意dp[n-1]并不是最终结果，dp[i]的最大值才是最终结果
    vector<int> dp(n, 0);
    int maxLen = 0;
    for (int i = 1; i < n; ++i)
    {
      if (s[i] == ')')
      {
        if (s[i - 1] == '(')
        {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        }
        else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
        {
          dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxLen = max(maxLen, dp[i]);
      }
    }
    return maxLen;
  }
};
}

// 45. 跳跃游戏 II (中等)
namespace N45
{
//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//
//每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//
//0 <= j <= nums[i]
//i + j < n
//  返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
class Solution {
public:
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
      {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[nums.size() - 1];
  }
};
}

// 55. 跳跃游戏 (中等)
namespace N55
{
//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
class Solution {
public:
  bool canJump(vector<int>& nums) {
    // dp[i]表示到达i位置时剩余的最大步数
    vector<int> dp(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i)
    {
      // 要么使用上一步的剩余步数，要么使用当前位置的步数
      dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
      if (dp[i] < 0)
      {
        return false;
      }
    }
    return true;
  }
};
}

// 64. 最小路径和 (中等)
namespace N64
{
//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= grid.size(); ++i)
    {
      for (int j = 1; j <= grid[0].size(); ++j)
      {
        if (i == 1 && j == 1)
        {
          continue;
        }
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return dp[grid.size()][grid[0].size()];
  }
};
}

// 87. 扰乱字符串 (困难) // todo
namespace N87
{
//使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
//如果字符串的长度为 1 ，算法停止
//如果字符串的长度 > 1 ，执行下述步骤：
//在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
//随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
//在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
//给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
class Solution {
public:
  bool isScramble([[maybe_unused]] string s1, [[maybe_unused]] string s2) {

  }
};
}

// 91. 解码方法 (中等)
namespace N91
{
//一条包含字母 A - Z 的消息通过以下映射进行了 编码 ：
//
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//
//"AAJF" ，将消息分组为(1 1 10 6)
//"KJF" ，将消息分组为(11 10 6)
//注意，消息不能分组为(1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//
//题目数据保证答案肯定是一个 32 位 的整数。
class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
    {
      return 0;
    }
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i] == '0')
      {
        if (s[i - 1] != '1' && s[i - 1] != '2')
        {
          return 0;
        }
        dp[i + 1] = dp[i - 1];
      }
      else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
      {
        dp[i + 1] = dp[i] + dp[i - 1];
      }
      else
      {
        dp[i + 1] = dp[i];
      }
    }
    return dp[s.size()];
  }
};
}

// 118. 杨辉三角 (简单)
namespace N118
{
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i)
    {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j)
      {
        row[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res.push_back(row);
    }
    return res;
  }
};
}

// 119. 杨辉三角 II

// 2645. 构造有效字符串的最少插入数 (中等)
namespace N2645
{
//给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 word 有效 需要插入的最少字母数。
//
//如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。
//word 仅由字母 "a"、"b" 和 "c" 组成
class Solution {
public:
  int addMinimum(string word) {
    int n = static_cast<int>(word.size());
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = dp[i - 1] + 2;
      if (i >= 1 && word[i] > word[i - 1])
      {
        dp[i] -= 3;
      }
    }
    return dp[n];
  }
};
}