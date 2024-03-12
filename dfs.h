#pragma once

// 97. �����ַ��� (�е�)
namespace n97
{
//���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ���� ��ɵġ�
//
//�����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ� ���ַ�����
//
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//| n - m| <= 1
//���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
//ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�
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

// 120. ��������С·���� (�е�)
namespace n120
{
//����һ�������� triangle ���ҳ��Զ����µ���С·���͡�
//
//ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��
//���磬���������Σ�
//   2
//  3 4
// 6 5 7
//4 1 8 3
//�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����
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

// 130. ��Χ�Ƶ����� (�е�)
namespace n130
{
// ����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣
class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int m = static_cast<int>(board.size());
    int n = static_cast<int>(board[0].size());

    // �����������
    set<vector<int>> visited;
    vector<vector<int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, {-1, 0} };
    function<bool(int, int)> dfs = [&](int i, int j) -> bool
      {
        if (visited.find({ i, j }) != visited.end())
        {
          return true;
        }
        // ���������Ȧ���ж��Ƿ��ӳ�
        if (i <= 0 || i >= m - 1 || j <= 0 || j >= n - 1)
        {
          // �����Ե��x������Χ
          if (board[i][j] == 'X')
          {
            return true;
          }
          // �����Ե��o�����ӳ�
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

// 200. �������� (�е�)
namespace n200
{
//����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
//
//�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ����� / ����ֱ���������ڵ�½�������γɡ�
//
//���⣬����Լ��������������߾���ˮ��Χ��
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

// 329. �����е������·�� (����)
namespace n329
{
//����һ�� m x n �������� matrix ���ҳ����� �����·�� �ĳ��ȡ�
//
//����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� �� ���� �� �Խ��� �������ƶ����ƶ��� �߽��⣨���������ƣ���
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

// 397. �����滻 (�е�)
namespace n397
{
//����һ�������� n ������������²�����
//
//��� n ��ż�������� n / 2�滻 n ��
//��� n ��������������� n + 1��n - 1�滻 n ��
//���� n ��Ϊ 1 ����� ��С�滻���� ��
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
          // ����ֱ��ִ���������Լ��ٵݹ����
          memo[n] = min(dfs(n / 2), dfs(n / 2 + 1)) + 2;
        }
        return memo[n];
      };
    return static_cast<int>(dfs(n));
  }
};
}