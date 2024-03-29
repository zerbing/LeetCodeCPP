#pragma once

// 292. Nim 游戏 (简单)
namespace n292
{
//你和你的朋友，两个人一起玩 Nim 游戏：
//
//桌子上有一堆石头。
//你们轮流进行自己的回合， 你作为先手 。
//每一回合，轮到的人拿掉 1 - 3 块石头。
//拿掉最后一块石头的人就是获胜者。
//假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
class Solution {
public:
  bool canWinNim(int n) {
    return n % 4 != 0;
  }
};
}

// 670. 最大交换 (中等)
namespace n670
{
// 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
class Solution {
public:
  int maximumSwap(int num) {
    vector<int> nums;
    while (num)
    {
      nums.push_back(num % 10);
      num /= 10;
    }
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
      int maxIndex = i;
      for (int j = i + 1; j < nums.size(); ++j)
      {
        if (nums[j] >= nums[maxIndex])
        {
          maxIndex = j;
        }
      }
      if (maxIndex != i && nums[maxIndex] != nums[i])
      {
        swap(nums[maxIndex], nums[i]);
        break;
      }
    }
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      res = res * 10 + nums[i];
    }
    return res;
  }
};
}

// 1686. 石子游戏 VI (中等)
namespace n1686
{
//Alice 和 Bob 轮流玩一个游戏，Alice 先手。

//一堆石子里总共有 n 个石子，轮到某个玩家时，他可以 移出 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 不一样的的评判标准 。双方都知道对方的评判标准。
//
//给你两个长度为 n 的整数数组 aliceValues 和 bobValues 。aliceValues[i] 和 bobValues[i] 分别表示 Alice 和 Bob 认为第 i 个石子的价值。
//
//所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 最优策略 进行游戏。
//
//请你推断游戏的结果，用如下的方式表示：
//
//如果 Alice 赢，返回 1 。
//如果 Bob 赢，返回 - 1 。
//如果游戏平局，返回 0 。
class Solution {
public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    size_t n = aliceValues.size();
    pair<long long, long long> score;
    multimap<long long, long long> value;
    for (size_t i = 0; i < n; ++i) {
      value.insert({ aliceValues[i] + bobValues[i], i });
    }
    bool aliceTurn = true;
    for (auto it = value.rbegin(); it != value.rend(); ++it) {
      if (aliceTurn) {
        score.first += aliceValues[it->second];
      }
      else {
        score.second += bobValues[it->second];
      }
      aliceTurn = !aliceTurn;
    }
    if (score.first > score.second) {
      return 1;
    }
    else if (score.first < score.second) {
      return -1;
    }
    else {
      return 0;
    }
  }
};
}

// 1402. 做菜顺序 (困难)
namespace n1402
{
//一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。
//
//一道菜的 「 like - time 系数 」定义为烹饪这道菜结束的时间（包含之前每道菜所花费的时间）乘以这道菜的满意程度，也就是 time[i] * satisfaction[i] 。
//
//返回厨师在准备了一定数量的菜肴后可以获得的最大 like - time 系数 总和。
//
//你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。
class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int sum = accumulate(satisfaction.begin(), satisfaction.end(), 0);
    int res = 0;
    // 评分低的菜越早做越好
    for (int i = 0; i < satisfaction.size(); ++i)
    {
      res += satisfaction[i] * (i + 1);
    }
    int tmp = res;
    // 逐步放弃评分最低的菜
    for (int i = 1; i <= satisfaction.size(); ++i)
    {
      tmp -= sum;
      res = max(res, tmp);
      sum -= satisfaction[i - 1];
    }
    return res;
  }
};
}