#pragma once

// 29. 两数相除 (中等）
namespace n29
{
//给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。
//
//整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ， - 2.7335 将被截断至 - 2 。
//
//返回被除数 dividend 除以除数 divisor 得到的 商 。
//
//注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是[−231, 231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 - 231 ，则返回 - 231 。
class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    return dividend / divisor;
  }
};
}

// 43. 字符串相乘 (中等）
namespace n43
{
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int m = static_cast<int>(num1.size()), n = static_cast<int>(num2.size());
    vector<int> res(m + n, 0);
    for (int i = m - 1; i >= 0; i--)
    {
      int x = num1[i] - '0';
      for (int j = n - 1; j >= 0; j--)
      {
        int y = num2[j] - '0';
        res[i + j + 1] += x * y;
      }
    }
    for (int i = m + n - 1; i > 0; i--)
    {
      res[i - 1] += res[i] / 10;
      res[i] %= 10;
    }
    int index = res[0] == 0 ? 1 : 0;
    string str;
    while (index < m + n)
    {
      str.push_back(static_cast<char>(res[index] + '0'));
      index++;
    }
    return str;
  }
};
}

// 60. 排列序列 (困难）
namespace n60
{
//给出集合[1, 2, 3, ..., n]，其所有元素共有 n!种排列。
//
//按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//给定 n 和 k，返回第 k 个排列。
class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> factorial(n);
    factorial[0] = 1;
    for (int i = 1; i < n; i++)
    {
      factorial[i] = factorial[i - 1] * i;
    }
    --k;
    string res;
    set<int> nums;
    for (int i = 1; i <= n; i++)
    {
      int order = k / factorial[n - i] + 1;
      // 从1开始找到第order个未使用的数字
      int num = 0;
      while (order > 0)
      {
        if (nums.find(++num) == nums.end())
        {
          order--;
        }
      }
      res.push_back(static_cast<char>(num + '0'));
      nums.insert(num);
      k %= factorial[n - i];
    }
    return res;
  }
};
}

// 2591. 将钱分给最多的儿童 (简单）
namespace n2591
{
//给你一个整数 money ，表示你总共有的钱数（单位为美元）和另一个整数 children ，表示你要将钱分配给多少个儿童。
//
//你需要按照如下规则分配：
//
//所有的钱都必须被分配。
//每个儿童至少获得 1 美元。
//没有人获得 4 美元。
//请你按照上述规则分配金钱，并返回 最多 有多少个儿童获得 恰好 8 美元。如果没有任何分配方案，返回 - 1 。
class Solution {
public:
  int distMoney(int money, int children) {
    money -= children;
    if (money < 0) return -1;
    int res = money / 7;
    int left = money % 7;
    if (res > children || res == children && left > 0)
    {
      return children - 1;
    }
    else if (res == children - 1 && left == 3)
    {
      return children - 2;
    }
    return res;
  }
};
}