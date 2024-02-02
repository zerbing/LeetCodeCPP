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