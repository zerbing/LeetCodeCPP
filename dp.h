#pragma once

// 32. 最长有效括号 (困难)
namespace N32
{
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
class Solution {
public:
  int longestValidParentheses(string s) {
    int n = static_cast<int>(s.size());
    // dp[i] 表示以 s[i] **结尾**的最长有效括号的长度
    // 注意dp[n-1]并不是最终结果，dp[i]的最大值才是最终结果
    vector<int> dp(n, 0);
    int maxLen = 0;
    for (int i = 1; i < n; ++i)
    {
      if (s[i] == ')')
      {
        if (s[i - 1] == '(')
        {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        }
        else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
        {
          dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxLen = max(maxLen, dp[i]);
      }
    }
    return maxLen;
  }
};
}

// 45. 跳跃游戏 II (中等)
namespace N45
{
//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//
//每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//
//0 <= j <= nums[i]
//i + j < n
//  返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
class Solution {
public:
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
      {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[nums.size() - 1];
  }
};
}

// 55. 跳跃游戏 (中等)
namespace N55
{
//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
class Solution {
public:
  bool canJump(vector<int>& nums) {
    // dp[i]表示到达i位置时剩余的最大步数
    vector<int> dp(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i)
    {
      // 要么使用上一步的剩余步数，要么使用当前位置的步数
      dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
      if (dp[i] < 0)
      {
        return false;
      }
    }
    return true;
  }
};
}

// 64. 最小路径和 (中等)
namespace N64
{
//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= grid.size(); ++i)
    {
      for (int j = 1; j <= grid[0].size(); ++j)
      {
        if (i == 1 && j == 1)
        {
          continue;
        }
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return dp[grid.size()][grid[0].size()];
  }
};
}

// 87. 扰乱字符串 (困难) // todo
namespace N87
{
//使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
//如果字符串的长度为 1 ，算法停止
//如果字符串的长度 > 1 ，执行下述步骤：
//在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
//随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
//在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
//给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
class Solution {
public:
  bool isScramble([[maybe_unused]] string s1, [[maybe_unused]] string s2) {
    return false;
  }
};
}

// 91. 解码方法 (中等)
namespace N91
{
//一条包含字母 A - Z 的消息通过以下映射进行了 编码 ：
//
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//
//"AAJF" ，将消息分组为(1 1 10 6)
//"KJF" ，将消息分组为(11 10 6)
//注意，消息不能分组为(1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//
//题目数据保证答案肯定是一个 32 位 的整数。
class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
    {
      return 0;
    }
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i] == '0')
      {
        if (s[i - 1] != '1' && s[i - 1] != '2')
        {
          return 0;
        }
        dp[i + 1] = dp[i - 1];
      }
      else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
      {
        dp[i + 1] = dp[i] + dp[i - 1];
      }
      else
      {
        dp[i + 1] = dp[i];
      }
    }
    return dp[s.size()];
  }
};
}

// 118. 杨辉三角 (简单)
namespace N118
{
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i)
    {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j)
      {
        row[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res.push_back(row);
    }
    return res;
  }
};
}

// 119. 杨辉三角 II (简单)
namespace N119
{
//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex; ++i)
    {
      for (int j = i - 1; j > 0; --j)
      {
        res[j] += res[j - 1];
      }
    }
    return res;
  }
};
}

// 139. 单词拆分 (中等)
namespace N139
{
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i)
    {
      for (const string& word : wordDict)
      {
        int len = static_cast<int>(word.size());
        if (i >= len && s.substr(i - len, len) == word)
        {
          dp[i] = dp[i - len];
          if (dp[i])
          {
            break;
          }
        }
      }
    }
    return dp[s.size()];
  }
};
}

// 152. 乘积最大子数组 (中等)
namespace N152
{
//给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//测试用例的答案是一个 32 - 位 整数。
//
//子数组 是数组的连续子序列。
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    // dp[i].first表示以nums[i]结尾的最大乘积，dp[i].second表示以nums[i]结尾的最小乘积
    vector<pair<int, int>> dp(nums.size(), {INT_MIN, INT_MAX});
    dp[0] = {nums[0], nums[0]};
    int maxProduct = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      dp[i].first = max({dp[i - 1].first * nums[i], dp[i - 1].second * nums[i], nums[i]});
      dp[i].second = min({dp[i - 1].first * nums[i], dp[i - 1].second * nums[i], nums[i]});
      maxProduct = max(maxProduct, dp[i].first);
    }
    return maxProduct;
  }
};
}

// 174. 地下城游戏 (困难)
namespace N174
{
//恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。地下城是由 m x n 个房间组成的二维网格。我们英勇的骑士最初被安置在 左上角 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
//
//骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
//
//有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
//
//为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。
//
//返回确保骑士能够拯救到公主所需的最低初始健康点数。
//
//注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    // dp[i][j]表示进入dungeon[i][j]时的最小初始健康点数
    vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
    // 由于骑士任意时刻的健康点数都不能小于1，所以需要反向dp
    dp[dungeon.size()][dungeon[0].size() - 1] = 1;
    dp[dungeon.size() - 1][dungeon[0].size()] = 1;
    for (int i = static_cast<int>(dungeon.size()) - 1; i >= 0; --i)
    {
      for (int j = static_cast<int>(dungeon[0].size()) - 1; j >= 0; --j)
      {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};
}

// 198. 打家劫舍 (中等)
namespace N198
{
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
class Solution {
public:
  int rob(vector<int>& nums) {
    // dp[i].first表示偷窃到第i个房屋时的最大金额，dp[i].second表示不偷窃第i个房屋时的最大金额
    vector<pair<int, int>> dp(nums.size() + 1, {0, 0});
    for (int i = 1; i <= nums.size(); ++i)
    {
      dp[i].first = dp[i - 1].second + nums[i - 1];
      dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    return max(dp[nums.size()].first, dp[nums.size()].second);
  }
};
}

// 213. 打家劫舍 II (中等)
namespace N213
{
//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1)
    {
      return nums[0];
    }
    int res = 0;
    // dp[i].first表示偷窃到第i个房屋时的最大金额，dp[i].second表示不偷窃第i个房屋时的最大金额
    vector<pair<int, int>> dp(nums.size(), { 0, 0 });
    // 不偷窃第一个房屋
    for (int i = 1; i < nums.size(); ++i)
    {
      if (1 == i)
      {
        dp[i].first = nums[i];
        dp[i].second = 0;
      }
      else
      {
        dp[i].first = dp[i - 1].second + nums[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
      }
    }
    res = max(dp[nums.size() - 1].first, dp[nums.size() - 1].second);
    // 偷窃第一个房屋
    vector<pair<int, int>> dp2(nums.size(), { 0, 0 });
    for (int i = 0; i < nums.size() - 1; ++i)
    {
      if (0 == i)
      {
        dp2[i].first = nums[i];
        dp2[i].second = 0;
      }
      else
      {
        dp2[i].first = dp2[i - 1].second + nums[i];
        dp2[i].second = max(dp2[i - 1].first, dp2[i - 1].second);
      }
    }
    res = max(res, max(dp2[nums.size() - 2].first, dp2[nums.size() - 2].second));
    return res;
  }
};
}

// 221. 最大正方形 (中等)
namespace N221
{
//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxSide = 0;
    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (matrix[i - 1][j - 1] == '1')
        {
          dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }
    return maxSide * maxSide;
  }
};
}

// 264. 丑数 II (中等)
namespace N264
{
//给你一个整数 n ，请你找出并返回第 n 个 丑数 。
//
//丑数 就是质因子只包含 2、3 和 5 的正整数。
class Solution {
public:
  int nthUglyNumber(int n) {
    // dp[i]表示第i-1个丑数
    vector<int> dp(n, 0);
    dp[0] = 1;
    // p2, p3, p5分别表示dp中的哪个位置的丑数乘以2, 3, 5可以得到下一个丑数
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; ++i)
    {
      dp[i] = min({ dp[p2] * 2, dp[p3] * 3, dp[p5] * 5 });
      if (dp[i] == dp[p2] * 2)
      {
        p2++;
      }
      if (dp[i] == dp[p3] * 3)
      {
        p3++;
      }
      if (dp[i] == dp[p5] * 5)
      {
        p5++;
      }
    }
    return dp[n - 1];
  }
};
}

// 309. 买卖股票的最佳时机含冷冻期 (中等)
namespace N309
{
//给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
//
//设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票） :
//
//卖出股票后，你无法在第二天买入股票(即冷冻期为 1 天)。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // dp[i][0]表示第i天持有股票的最大收益，dp[i][1]表示第i天不持有股票的最大收益，dp[i][2]表示第i天不持有股票且处于冷冻期的最大收益
    vector<tuple<int, int, int>> dp(prices.size(), { 0, 0, 0 });
    dp[0] = { -prices[0], 0, 0 };
    for (int i = 1; i < prices.size(); ++i)
    {
      dp[i] = { max(get<0>(dp[i - 1]), get<1>(dp[i - 1]) - prices[i]), max(get<1>(dp[i - 1]), get<2>(dp[i - 1])), get<0>(dp[i - 1]) + prices[i] };
    }
    return max(get<1>(dp[prices.size() - 1]), get<2>(dp[prices.size() - 1]));
  }
};
}

// 343. 整数拆分 (中等)
namespace N343
{
//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//
//返回 你可以获得的最大乘积 。
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
      for (int j = 1; j < i; ++j)
      {
        dp[i] = max({ dp[i], j * (i - j), j * dp[i - j] });
      }
    }
    return dp[n];
  }
};
}

// 375. 猜数字大小 II
namespace N375
{
//我们正在玩一个猜数游戏，游戏规则如下：
//
//我从 1 到 n 之间选择一个数字。
//你来猜我选了哪个数字。
//如果你猜到正确的数字，就会 赢得游戏 。
//如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
//每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
//给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。
class Solution {
public:
  int getMoneyAmount(int n) {
    // dp[i][j]表示从i到j猜中任意一个数的最小花费
    //  当解释动态规划（DP）时，我们通常需要考虑以下几个方面：问题的定义、状态转移方程、初始条件和边界情况。让我逐步解释这些内容。
    //  首先，让我们来看看问题的定义。在这个问题中，我们需要猜一个范围在1到n之间的数字。每次猜测一个数字后，系统会告诉我们猜的数字是正确的、太大了还是太小了。我们的目标是猜中这个数字，并且要使得猜中任意一个数字的最小花费最小化。
    //  接下来，我们来看看状态转移方程。在这个问题中，我们可以使用一个二维数组dp来表示状态。dp[i][j]表示从数字i到数字j猜中任意一个数字的最小花费。我们需要填充整个dp数组，从左上角到右下角。
    //  为了填充dp数组，我们需要考虑不同的猜测范围长度。我们从长度为2的范围开始，逐渐增加范围长度，直到达到整个范围1到n。对于每个范围长度，我们需要遍历范围内的所有可能的起始数字i，并计算猜中任意一个数字的最小花费。
    //  对于每个范围长度和起始数字i，我们需要遍历范围内的所有可能的猜测数字k。我们可以将范围分为两部分：左边的范围[i, k - 1]和右边的范围[k + 1, j]。我们需要选择一个最优的猜测数字k，使得猜中任意一个数字的最小花费最小化。
    //  根据题目要求，我们需要考虑两种情况：如果我们猜的数字k比实际数字大，那么我们需要在左边的范围[i, k - 1]中继续猜测；如果我们猜的数字k比实际数字小，那么我们需要在右边的范围[k + 1, j]中继续猜测。我们可以使用dp数组来获取左边和右边范围的最小花费，然后将它们加上当前猜测的数字k的花费k，得到总的最小花费。
    //  最后，我们需要注意初始条件和边界情况。在这个问题中，当范围长度为1时，即i和j相等时，猜中任意一个数字的最小花费为0，因为我们已经猜中了。此外，我们需要从范围长度为2开始填充dp数组。
    //  综上所述，我们可以使用动态规划来解决这个问题。通过填充dp数组，我们可以得到从1到n猜中任意一个数字的最小花费。最后，我们返回dp[1][n]作为结果。
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; ++len)
    {
      for (int i = 1; i + len - 1 <= n ; ++i)
      {
        int j = i + len - 1;
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k)
        {
          dp[i][j] = min(dp[i][j], k + max(k - 1 >= i ? dp[i][k - 1] : 0, k + 1 <= j ? dp[k + 1][j] : 0));
        }
      }
    }
    return dp[1][n];
  }
};
}

// 377. 组合总和 Ⅳ (中等)
namespace N377
{
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//
//题目数据保证答案符合 32 位整数范围。
//请注意，顺序不同的序列被视作不同的组合。
//nums 中的数可以被重复选取。
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
      for (int num : nums)
      {
        if (i >= num)
        {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};
}

// 396. 旋转函数 (中等)
namespace N396
{
//给定一个长度为 n 的整数数组 nums 。
//
//假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
//
//F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
//返回 F(0), F(1), ..., F(n - 1)中的最大值 。
//
//生成的测试用例让答案符合 32 位 整数。
class Solution {
public:
  int maxRotateFunction(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int res = INT_MIN;
    int cur = 0;
    size_t n = nums.size();
    for (size_t i = 0; i < n; ++i)
    {
      cur += static_cast<int>(i * nums[i]);
    }
    for (size_t i = 0; i < n; ++i)
    {
      cur += nums[i] * static_cast<int>(n) - sum;
      res = max(res, cur);
    }
    return res;
  }
};
}

// 2645. 构造有效字符串的最少插入数 (中等)
namespace N2645
{
//给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 word 有效 需要插入的最少字母数。
//
//如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。
//word 仅由字母 "a"、"b" 和 "c" 组成
class Solution {
public:
  int addMinimum(string word) {
    int n = static_cast<int>(word.size());
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = dp[i - 1] + 2;
      if (i >= 1 && word[i] > word[i - 1])
      {
        dp[i] -= 3;
      }
    }
    return dp[n];
  }
};
}