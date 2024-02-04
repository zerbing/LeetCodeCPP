#pragma once

// 39. 组合总和 (中等)
namespace N39
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
          // 做出选择
          path.push_back(candidates[i]);
          backtrace(path, target - candidates[i], i);
          // 撤回选择
          path.pop_back();
        }
      };
    backtrace(path, target, 0);
    return res;
  }
};
}

// 40. 组合总和 II (中等)
namespace N40
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
          // 排除重复的选择
          if (i > cur && candidates[i] == candidates[i - 1])
          {
            continue;
          }
          // 做出选择
          path.push_back(candidates[i]);
          backtrace(target - candidates[i], i + 1);
          // 撤回选择
          path.pop_back();
        }
      };
    backtrace(target, 0);
    return res;
  }
};
}

// 47. 全排列 II (中等)
namespace N47
{
class Solution {
  // 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列
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
          // 排除重复的选择
          if (count(path.begin(), path.end(), i))
          {
            continue;
          }
          if (i > 0 && nums[i] == nums[i - 1] && !count(path.begin(), path.end(), i - 1))
          {
            continue;
          }
          // 做出选择
          path.push_back(i);
          backtrace();
          // 撤回选择
          path.pop_back();
        }
      };
    backtrace();
    return res;
  }
};
}

// 52. N 皇后 II (困难)
namespace N52
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

// 140. 单词拆分 II (困难)
namespace N140
{
//给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序 返回所有这些可能的句子。
//
//注意：词典中的同一个单词可能在分段中被重复使用多次。
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

// 357. 统计各位数字都不同的数字个数
namespace N357
{
// 给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n 。
// 效率低
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
// 更优
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