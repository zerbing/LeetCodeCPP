#pragma once

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