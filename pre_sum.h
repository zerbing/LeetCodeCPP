#pragma once

// 410. 分割数组的最大值 (困难)
namespace N410
{
//给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组。
//
//设计一个算法使得这 k 个子数组各自和的最大值最小。
class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    vector<int> preSum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    vector<vector<int>> dp(k, vector<int>(nums.size() + 1, 0));
    dp[0] = preSum;
    for (int i = 1; i < k; ++i)
    {
      for (int j = i; j <= nums.size(); j++)
      {
        int tmp = INT_MAX;
        for (int a = j - 1; a >= i - 1; --a)
        {
          // 通过前缀和计算新增分组的大小
          int sum = preSum[j] - preSum[a];
          tmp = min(tmp, max(sum, dp[i - 1][a]));
          // 由于sum随i递减，dp[i-1][a]随i递增，经过交叉点后即可退出循环
          if (sum >= dp[i - 1][a])
          {
            break;
          }
        }
        dp[i][j] = tmp;
      }
    }
    return dp[k - 1][nums.size()];
  }
};
}

// 2171. 拿出最少数目的魔法豆 (困难)
namespace N2171
{
//给定一个 正整数 数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。
//
//请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少还有一颗 魔法豆的袋子）魔法豆的数目 相等。一旦把魔法豆从袋子中取出，你不能再将它放到任何袋子中。
//
//请返回你需要拿出魔法豆的 最少数目。
class Solution {
public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    // 前缀和
    vector<long long> preSum(beans.size() + 1, 0);
    for (int i = 1; i <= beans.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + beans[i - 1];
    }
    long long res = INT64_MAX;
    for (int i = 0; i < beans.size(); ++i)
    {
      // 前i-1个袋子中的魔法豆数目
      long long sum = preSum[i];
      // 后n-i-1个袋子中的魔法豆数目
      sum += preSum[beans.size()] - preSum[i] - beans[i] * (beans.size() - i);
      res = min(res, sum);
    }
    return res;
  }
};
}