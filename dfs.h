#pragma once

// 97. 交错字符串 (中等)
namespace N97
{
//给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
//
//两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
//
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//| n - m| <= 1
//交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
//注意：a + b 意味着字符串 a 和 b 连接。
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
    {
      return false;
    }
    map<pair<int, int>, bool> memo;
    function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
      if (memo.count({ i, j }))
      {
        return memo[{i, j}];
      }
      if (k == s3.size())
      {
        return true;
      }
      if (i < s1.size() && s1[i] == s3[k] && dfs(i + 1, j, k + 1))
      {
        return true;
      }
      if (j < s2.size() && s2[j] == s3[k] && dfs(i, j + 1, k + 1))
      {
        return true;
      }
      memo[{i, j}] = false;
      return false;
      };
    return dfs(0, 0, 0);
  }
};
}

// 120. 三角形最小路径和 (中等)
namespace N120
{
//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//例如，给定三角形：
//   2
//  3 4
// 6 5 7
//4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> memo;
    for (size_t i = 0; i < triangle.size(); ++i)
    {
      memo.push_back(vector<int>(triangle[i].size(), INT_MAX));
    }
    int res = INT_MAX;
    function<void(int, int, int)> dfs = [&](int i, int j, int sum) {
      if (i == triangle.size())
      {
        res = min(res, sum);
        return;
      }
      if (memo[i][j] <= sum)
      {
        return;
      }
      memo[i][j] = sum;
      dfs(i + 1, j, sum + triangle[i][j]);
      dfs(i + 1, j + 1, sum + triangle[i][j]);
      };
    dfs(0, 0, 0);
    return res;
  }
};
}

// 329. 矩阵中的最长递增路径 (困难)
namespace N329
{
//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
//
//对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxLen = 0;
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    vector<vector<int>> dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    function<void(size_t, size_t, int)> dfs = [&](size_t i, size_t j, int curLen)
      {
        if (memo[i][j] >= curLen)
        {
          return;
        }
        memo[i][j] = curLen;
        maxLen = max(maxLen, curLen);
        for (const auto& dir : dirs)
        {
          size_t x = i + dir[0];
          size_t y = j + dir[1];
          if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
          {
            dfs(x, y, curLen + 1);
          }
        }
      };
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        dfs(i, j, 1);
      }
    }
    return maxLen;
  }
};
}

// 397. 整数替换 (中等)
namespace N397
{
//给定一个正整数 n ，你可以做如下操作：
//
//如果 n 是偶数，则用 n / 2替换 n 。
//如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
//返回 n 变为 1 所需的 最小替换次数 。
class Solution {
public:
  int integerReplacement(int n) {
    unordered_map<long long, long long> memo;
    function<long long(long long)> dfs = [&](long long n) -> long long
      {
      if (n == 1)
      {
        return 0;
      }
      if (memo.count(n))
      {
        return memo[n];
      }
      if (n % 2 == 0)
      {
        memo[n] = dfs(n / 2) + 1;
      }
      else
      {
        // 这里直接执行两步可以减少递归次数
        memo[n] = min(dfs(n / 2), dfs(n / 2 + 1)) + 2;
      }
      return memo[n];
      };
    return static_cast<int>(dfs(n));
  }
};
}