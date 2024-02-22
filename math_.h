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