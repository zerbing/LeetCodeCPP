#pragma once

// 97. 交错字符串 (中等)
namespace n97
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
namespace n120
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

// 130. 被围绕的区域 (中等)
namespace n130
{
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int m = static_cast<int>(board.size());
    int n = static_cast<int>(board[0].size());

    // 深度优先搜索
    set<vector<int>> visited;
    vector<vector<int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, {-1, 0} };
    function<bool(int, int)> dfs = [&](int i, int j) -> bool
      {
        if (visited.find({ i, j }) != visited.end())
        {
          return true;
        }
        // 如果到最外圈，判断是否逃出
        if (i <= 0 || i >= m - 1 || j <= 0 || j >= n - 1)
        {
          // 如果边缘是x代表被包围
          if (board[i][j] == 'X')
          {
            return true;
          }
          // 如果边缘是o代表逃出
          else
          {
            return false;
          }
        }
        else if (board[i][j] == 'X')
        {
          return true;
        }
        else
        {
          visited.insert({ i, j });
          return dfs(i + directions[0][0], j + directions[0][1]) &&
            dfs(i + directions[1][0], j + directions[1][1]) &&
            dfs(i + directions[2][0], j + directions[2][1]) &&
            dfs(i + directions[3][0], j + directions[3][1]);
        }
      };

    for (int i = 1; i < m - 1; ++i)
    {
      for (int j = 1; j < n - 1; ++j)
      {
        visited.clear();
        if (dfs(i, j))
        {
          for (auto& position : visited)
          {
            board[position[0]][position[1]] = 'X';
          }
        }
      }
    }
  }
};
}

// 200. 岛屿数量 (中等)
namespace n200
{
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
//岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。
//
//此外，你可以假设该网格的四条边均被水包围。
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    function<void(int, int)> dfs = [&](int x, int y)
      {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
        {
          return;
        }
        grid[x][y] = '0';
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
      };
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == '1')
        {
          result++;
          dfs(i, j);
        }
      }
    }
    return result;
  }
};
}

// 329. 矩阵中的最长递增路径 (困难)
namespace n329
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
namespace n397
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