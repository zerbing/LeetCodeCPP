#pragma once

// 32. 最长有效括号
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

// 45. 跳跃游戏 II
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

// 2645. 构造有效字符串的最少插入数
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