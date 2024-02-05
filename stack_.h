#pragma once

// 20. 有效的括号 (简单)
namespace N20
{
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

//  有效字符串需满足：

//  左括号必须用相同类型的右括号闭合。
//  左括号必须以正确的顺序闭合。
//  每个右括号都有一个对应的相同类型的左括号
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      {
        st.push(s[i]);
      }
      else
      {
        if (st.empty())
        {
          return false;
        }
        if (s[i] == ')' && st.top() != '(')
        {
          return false;
        }
        if (s[i] == ']' && st.top() != '[')
        {
          return false;
        }
        if (s[i] == '}' && st.top() != '{')
        {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};
}

// 316. 去除重复字母 (中等)
namespace N316
{
//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // 记录每个字符最后出现的位置
    vector<int> lastIdx(26, -1);
    for (int i = 0; i < s.size(); ++i)
    {
      lastIdx[s[i] - 'a'] = i;
    }
    stack<char> st;
    vector<bool> visited(26, false);
    for (int i = 0; i < s.size(); ++i)
    {
      if (visited[s[i] - 'a'])
      {
        continue;
      }
      while (!st.empty() && st.top() > s[i] && lastIdx[st.top() - 'a'] > i)
      {
        visited[st.top() - 'a'] = false;
        st.pop();
      }
      st.push(s[i]);
      visited[s[i] - 'a'] = true;
    }
    string res;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
}

// 2865. 美丽塔 I (困难)
namespace N2865
{
//给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
//
//你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
//
//如果以下条件满足，我们称这些塔是 美丽 的：
//
//1 <= heights[i] <= maxHeights[i]
//heights 是一个 山脉 数组。
//如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：
//
//对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
//  对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
//  请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
class Solution {
public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    vector<long long> leftHeights(maxHeights.size(), 0);
    vector<long long> rightHeights(maxHeights.size(), 0);
    // 计算左边的高度
    // 单调递增栈
    stack<int> st;
    int n = static_cast<int>(maxHeights.size());
    for (int i = 0; i < n; ++i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        leftHeights[i] = static_cast<long long>(maxHeights[i]) * (i + 1);
      }
      else
      {
        leftHeights[i] = leftHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (i - st.top());
      }
      st.push(i);
    }
    // 计算右边的高度
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        rightHeights[i] = static_cast<long long>(maxHeights[i]) * (maxHeights.size() - i);
      }
      else
      {
        rightHeights[i] = rightHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (st.top() - i);
      }
      st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < maxHeights.size(); ++i)
    {
      res = max(res, leftHeights[i] + rightHeights[i] - maxHeights[i]);
    }
    return res;
  }
};
}