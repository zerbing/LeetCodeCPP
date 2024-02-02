#pragma once

// 2085. 统计出现过一次的公共字符串
namespace N2085
{
// 给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。
class Solution {
public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    for (int i = 0; i < words1.size(); ++i)
    {
      m1[words1[i]]++;
    }
    for (int i = 0; i < words2.size(); ++i)
    {
      m2[words2[i]]++;
    }
    int res = 0;
    for (auto it = m1.begin(); it != m1.end(); ++it)
    {
      if (it->second == 1 && m2[it->first] == 1)
      {
        res++;
      }
    }
    return res;
  }
};
}

// 2670. 找出不同元素数目差数组
namespace N2670
{
//给你一个下标从 0 开始的数组 nums ，数组长度为 n 。
//
//nums 的 不同元素数目差 数组可以用一个长度为 n 的数组 diff 表示，其中 diff[i] 等于前缀 nums[0, ..., i] 中不同元素的数目 减去 后缀 nums[i + 1, ..., n - 1] 中不同元素的数目。
//
//返回 nums 的 不同元素数目差 数组。
//
//注意 nums[i, ..., j] 表示 nums 的一个从下标 i 开始到下标 j 结束的子数组（包含下标 i 和 j 对应元素）。特别需要说明的是，如果 i > j ，则 nums[i, ..., j] 表示一个空子数组。
class Solution {
public:
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    unordered_map<int, int> pre;
    unordered_map<int, int> suf;
    for (size_t i = 0; i < nums.size(); ++i)
    {
      suf[nums[i]]++;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
      pre[nums[i]]++;
      suf[nums[i]]--;
      if (suf[nums[i]] == 0)
      {
        suf.erase(nums[i]);
      }
      res[i] = static_cast<int>(pre.size()) - static_cast<int>(suf.size());
    }
    return res;
  }
};
}

// LCR 004. 只出现一次的数字 II
namespace LCR004
{
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
class Solution {
  int singleNumber(vector<int>& nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
      m[nums[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
      if (it->second == 1)
      {
        return it->first;
      }
    }
    return 0;
  }
};
}