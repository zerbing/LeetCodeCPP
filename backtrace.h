#pragma once

// 39. ����ܺ� (�е�)
namespace n39
{
class Solution {
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(vector<int>&, int, int)> backtrace = [&](vector<int>& path, int target, int cur)
      {
        if (target == 0)
        {
          res.push_back(path);
          return;
        }
        if (target < 0)
        {
          return;
        }
        for (int i = cur; i < candidates.size(); ++i)
        {
          // ����ѡ��
          path.push_back(candidates[i]);
          backtrace(path, target - candidates[i], i);
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace(path, target, 0);
    return res;
  }
};
}

// 40. ����ܺ� II (�е�)
namespace n40
{
class Solution {
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    function<void(int, int)> backtrace = [&](int target, int cur)
      {
        if (target == 0)
        {
          res.push_back(path);
          return;
        }
        if (target < 0)
        {
          return;
        }
        for (int i = cur; i < candidates.size(); ++i)
        {
          // �ų��ظ���ѡ��
          if (i > cur && candidates[i] == candidates[i - 1])
          {
            continue;
          }
          // ����ѡ��
          path.push_back(candidates[i]);
          backtrace(target - candidates[i], i + 1);
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace(target, 0);
    return res;
  }
};
}

// 47. ȫ���� II (�е�)
namespace n47
{
class Solution {
  // ����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ����
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    function<void()> backtrace = [&]()
      {
        if (path.size() == nums.size())
        {
          res.emplace_back();
          vector<int>& tmp = res.back();
          for (auto it = path.begin(); it != path.end(); ++it)
          {
            tmp.push_back(nums[*it]);
          }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
          // �ų��ظ���ѡ��
          if (count(path.begin(), path.end(), i))
          {
            continue;
          }
          if (i > 0 && nums[i] == nums[i - 1] && !count(path.begin(), path.end(), i - 1))
          {
            continue;
          }
          // ����ѡ��
          path.push_back(i);
          backtrace();
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace();
    return res;
  }
};
}

// 52. N �ʺ� II (����)
namespace n52
{
class Solution {
public:
  int totalNQueens(int n) {
    vector<int> path;
    int res = 0;
    function<void(int)> backtrace = [&](int row)
      {
        if (row == n)
        {
          res++;
          return;
        }
        for (int col = 0; col < n; ++col)
        {
          if (isValid(path, row, col))
          {
            path.push_back(col);
            backtrace(row + 1);
            path.pop_back();
          }
        }
      };
    backtrace(0);
    return res;
  }
  bool isValid(vector<int>& path, int row, int col)
  {
    for (int i = 0; i < path.size(); ++i)
    {
      if (path[i] == col || abs(row - i) == abs(col - path[i]))
      {
        return false;
      }
    }
    return true;
  }
};
}

// 79. �������� (�е�)
namespace n79
{
//����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��
//
//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
class Solution {
  public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    function<bool(int, int, int)> dfs = [&](int row, int col, int index)
      {
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col] != word[index])
        {
          return false;
        }
        if (index == word.size() - 1)
        {
          return true;
        }
        visited[row][col] = true;
        bool res = dfs(row - 1, col, index + 1) || dfs(row + 1, col, index + 1) || dfs(row, col - 1, index + 1) || dfs(row, col + 1, index + 1);
        visited[row][col] = false;
        return res;
      };
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (dfs(i, j, 0))
        {
          return true;
        }
      }
    }
    return false;
  }
};
}

// 140. ���ʲ�� II (����)
namespace n140
{
//����һ���ַ��� s ��һ���ַ����ֵ� wordDict �����ַ��� s �����ӿո�������һ�����ӣ�ʹ�þ��������еĵ��ʶ��ڴʵ��С�������˳�� ����������Щ���ܵľ��ӡ�
//
//ע�⣺�ʵ��е�ͬһ�����ʿ����ڷֶ��б��ظ�ʹ�ö�Ρ�
class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> res;
    function<void(vector<int>&)> dfs = [&](vector<int>& seprators) {
      if (seprators.back() == s.size())
      {
        string sentence;
        for (int i = 1; i < seprators.size(); ++i)
        {
          sentence += s.substr(seprators[i - 1], seprators[i] - seprators[i - 1]) + " ";
        }
        sentence.pop_back();
        res.push_back(sentence);
        return;
      }
      else
      {
        for (const string& word : wordDict)
        {
          int len = static_cast<int>(word.size());
          if (s.substr(seprators.back(), len) == word)
          {
            seprators.push_back(seprators.back() + len);
            dfs(seprators);
            seprators.pop_back();
          }
        }
      }
      };
    vector<int> seprators = { 0 };
    dfs(seprators);
    return res;
  }
};
}

// 357. ͳ�Ƹ�λ���ֶ���ͬ�����ָ���
namespace n357
{
// ����һ������ n ��ͳ�Ʋ����ظ�λ���ֶ���ͬ������ x �ĸ��������� 0 <= x < 10^n ��
// Ч�ʵͣ�ָ������
class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    int res = 0;
    set<int> memo;
    function<void(int)> dfs = [&](int depth) {
      res++;
      if (depth == n)
      {
        return;
      }
      for (int i = 0; i < 10; ++i)
      {
        if (i == 0 && depth == 0)
        {
          continue;
        }
        if (memo.count(i))
        {
          continue;
        }
        memo.insert(i);
        dfs(depth + 1);
        memo.erase(i);
      }
      };
    dfs(0);
    return res;
  }
};
// ���ţ���ѧ����
class Solution2 {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
    {
      return 1;
    }
    int res = 10;
    int cur = 9;
    for (int i = 2; i <= n; ++i)
    {
      cur *= 11 - i;
      res += cur;
    }
    return res;
  }
};
}