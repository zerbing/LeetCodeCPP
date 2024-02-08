  #pragma once

// 466. 统计重复个数 (困难)
namespace n466
{
//定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。
//
//例如，str == ["abc", 3] == "abcabcabc" 。
//如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。
//
//例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
//现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2, n2] 。
//
//请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得
class Solution {
public:
  int getMaxRepetitions([[maybe_unused]] string s1, [[maybe_unused]] int n1, [[maybe_unused]] string s2, [[maybe_unused]] int n2) {
  }
};
}

// 2719. 统计整数数目 (困难)
namespace n2719
{
//给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum 和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：
//
//num1 <= x <= num2
//min_sum <= digit_sum(x) <= max_sum.
//请你返回好整数的数目。答案可能很大，请返回答案对 109 + 7 取余后的结果。
//
//注意，digit_sum(x) 表示 x 各位数字之和。
class Solution {
public:
  int count([[maybe_unused]] string num1, [[maybe_unused]] string num2, [[maybe_unused]] int min_sum, [[maybe_unused]] int max_sum) {
  }
};
}

// 2809. 使数组和小于等于 x 的最少时间 (困难)
namespace n2809
{
//给你两个长度相等下标从 0 开始的整数数组 nums1 和 nums2 。每一秒，对于所有下标 0 <= i < nums1.length ，nums1[i] 的值都增加 nums2[i] 。操作 完成后 ，你可以进行如下操作：
//
//  选择任一满足 0 <= i < nums1.length 的下标 i ，并使 nums1[i] = 0 。
//  同时给你一个整数 x 。
//
//  请你返回使 nums1 中所有元素之和 小于等于 x 所需要的 最少 时间，如果无法实现，那么返回 - 1 。
class Solution {
public:
  int minimumTime([[maybe_unused]] vector<int>& nums1, [[maybe_unused]] vector<int>& nums2, [[maybe_unused]] int x) {
  }
};
}

// 2846. 边权重均等查询 (困难)
namespace n2846
{
//现有一棵由 n 个节点组成的无向树，节点按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi, wi] 表示树中存在一条位于节点 ui 和节点 vi 之间、权重为 wi 的边。
//
//另给你一个长度为 m 的二维整数数组 queries ，其中 queries[i] = [ai, bi] 。对于每条查询，请你找出使从 ai 到 bi 路径上每条边的权重相等所需的 最小操作次数 。在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。
//
//注意：
//
//查询之间 相互独立 的，这意味着每条新的查询时，树都会回到 初始状态 。
//从 ai 到 bi的路径是一个由 不同 节点组成的序列，从节点 ai 开始，到节点 bi 结束，且序列中相邻的两个节点在树中共享一条边。
//返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 条查询的答案。

class Solution {
public:
  vector<int> minOperationsQueries([[maybe_unused]] int n, [[maybe_unused]] vector<vector<int>>& edges, [[maybe_unused]] vector<vector<int>>& queries) {

  }
};
}