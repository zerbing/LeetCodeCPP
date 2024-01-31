#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <array>
#include <map>
#include <sys/timeb.h>
#include <time.h>
#include <random>
#include <unordered_map>
#include <stack>
#include <functional>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;
using namespace std::chrono;

// 18. 四数之和
namespace N18
{
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4)
    {
      return res;
    }
    sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n - 3; ++i)
    {
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }
      for (int j = i + 1; j < n - 2; ++j)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
        {
          continue;
        }
        int left = j + 1;
        int right = n - 1;
        while (left < right)
        {
          long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
          if (sum == target)
          {
            res.push_back({ nums[i], nums[j], nums[left], nums[right] });
            while (left < right && nums[left] == nums[left + 1])
            {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1])
            {
              right--;
            }
            left++;
            right--;
          }
          else if (sum < target)
          {
            left++;
          }
          else
          {
            right--;
          }
        }
      }
    }
    return res;
  }
};
}

// 19. 删除链表的倒数第 N 个结点
namespace N19
{
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    while (n-- && fast != nullptr)
    {
      fast = fast->next;
    }
    ListNode* slow = dummy;
    while (fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }
    // 删除倒数第n个节点
    slow->next = slow->next->next;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// 20. 有效的括号
namespace N20
{
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

//  有效字符串需满足：

//  左括号必须用相同类型的右括号闭合。
//  左括号必须以正确的顺序闭合。
//  每个右括号都有一个对应的相同类型的左括号
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      {
        st.push(s[i]);
      }
      else
      {
        if (st.empty())
        {
          return false;
        }
        if (s[i] == ')' && st.top() != '(')
        {
          return false;
        }
        if (s[i] == ']' && st.top() != '[')
        {
          return false;
        }
        if (s[i] == '}' && st.top() != '{')
        {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};
}

// 21. 合并两个有序链表
namespace N21
{
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (list1 != nullptr && list2 != nullptr)
    {
      if (list1->val < list2->val)
      {
        cur->next = list1;
        list1 = list1->next;
      }
      else
      {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    cur->next = list1 != nullptr ? list1 : list2;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// 39. 组合总和
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

// 40. 组合总和 II
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

// 47. 全排列 II
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

// 52. N 皇后 II
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

// 94. 二叉树的中序遍历
namespace N94
{
//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 栈解法，推荐
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty())
    {
      while (cur != nullptr)
      {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      res.push_back(cur->val);
      cur = cur->right;
    }
    return res;
  }
};
// 递归解法
class Solution2 {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    function<void(TreeNode*)> inorder = [&](TreeNode* root)
      {
        if (root == nullptr)
        {
          return;
        }
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
      };
    inorder(root);
    return res;
  }
};
}

// 117. 填充每个节点的下一个右侧节点指针 II
namespace N117
{
//给定一个二叉树：

//struct Node {
//  int val;
//  Node* left;
//  Node* right;
//  Node* next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

//初始状态下，所有 next 指针都被设置为 NULL 。
//Definition for a Node.
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr)
    {
      return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
      int size = static_cast<int>(q.size());
      for (int i = 0; i < size; ++i)
      {
        Node* node = q.front();
        q.pop();
        if (i < size - 1)
        {
          node->next = q.front();
        }
        if (node->left != nullptr)
        {
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
    }
    return root;
  }
};
}

// 383. 赎金信
namespace N383
{
class Solution {
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < magazine.size(); ++i)
    {
      cnt[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); ++i)
    {
      cnt[ransomNote[i] - 'a']--;
      if (cnt[ransomNote[i] - 'a'] < 0)
      {
        return false;
      }
    }
    return true;
  }
};
}

// 410. 分割数组的最大值
namespace N410
{
//给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组。
//
//设计一个算法使得这 k 个子数组各自和的最大值最小。
class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    vector<int> preSum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    vector<vector<int>> dp(k, vector<int>(nums.size() + 1, 0));
    dp[0] = preSum;
    for (int i = 1; i < k; ++i)
    {
      for (int j = i; j <= nums.size(); j++)
      {
        int tmp = INT_MAX;
        for (int a = j - 1; a >= i - 1; --a)
        {
          // 通过前缀和计算新增分组的大小
          int sum = preSum[j] - preSum[a];
          tmp = min(tmp, max(sum, dp[i - 1][a]));
          // 由于sum随i递减，dp[i-1][a]随i递增，经过交叉点后即可退出循环
          if (sum >= dp[i - 1][a])
          {
            break;
          }
        }
        dp[i][j] = tmp;
      }
    }
    return dp[k - 1][nums.size()];
  }
};
}

// 447. 回旋镖的数量
namespace N447
{
class Solution {
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    vector<vector<int>> dis(points.size(), vector<int>(points.size(), 0));
    for (int i = 0; i < points.size(); ++i)
    {
      for (int j = i + 1; j < points.size(); ++j)
      {
        int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
          (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        dis[i][j] = distance;
        dis[j][i] = distance;
      }
    }

    for (int i = 0; i < points.size(); ++i)
    {
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); ++j)
      {
        if (i != j)
        {
          m[dis[i][j]]++;
        }
      }
      for (auto it = m.begin(); it != m.end(); ++it)
      {
        if (it->second >= 2)
        {
          res += it->second * (it->second - 1);
        }
      }
    }
    return res;
  }
};
}

// 466. 统计重复个数 // todo
namespace N466
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
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
  }
};
}

// 670. 最大交换
namespace N670
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

// 2171. 拿出最少数目的魔法豆
namespace N2171
{
//给定一个 正整数 数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。
//
//请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少还有一颗 魔法豆的袋子）魔法豆的数目 相等。一旦把魔法豆从袋子中取出，你不能再将它放到任何袋子中。
//
//请返回你需要拿出魔法豆的 最少数目。
class Solution {
public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    // 前缀和
    vector<long long> preSum(beans.size() + 1, 0);
    for (int i = 1; i <= beans.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + beans[i - 1];
    }
    long long res = INT64_MAX;
    for (int i = 0; i < beans.size(); ++i)
    {
      // 前i-1个袋子中的魔法豆数目
      long long sum = preSum[i];
      // 后n-i-1个袋子中的魔法豆数目
      sum += preSum[beans.size()] - preSum[i] - beans[i] * (beans.size() - i);
      res = min(res, sum);
    }
    return res;
  }
};
}

// 2645. 构造有效字符串的最少插入数
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

// 2678. 老人的数目
namespace N2678
{
//给你一个下标从 0 开始的字符串 details 。details 中每个元素都是一位乘客的信息，信息用长度为 15 的字符串表示，表示方式如下：
//
//前十个字符是乘客的手机号码。
//接下来的一个字符是乘客的性别。
//接下来两个字符是乘客的年龄。
//最后两个字符是乘客的座位号。
//请你返回乘客中年龄 严格大于 60 岁 的人数。
class Solution {
public:
  int countSeniors(vector<string>& details) {
    int res = 0;
    for (size_t i = 0; i < details.size(); ++i)
    {
      string age = details[i].substr(11, 2);
      if (stoi(age) > 60)
      {
        res++;
      }
    }
    return res;
  }
};
}

// 2696. 删除子串后的字符串最小长度
namespace N2696
{
class Solution {
public:
  int minLength(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (!st.empty() && s[i] == 'B' && st.top() == 'A')
      {
        st.pop();
      }
      else if (!st.empty() && s[i] == 'D' && st.top() == 'C')
      {
        st.pop();
      }
      else
      {
        st.push(s[i]);
      }
    }
    return static_cast<int>(st.size());
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

// 2707. 字符串中的额外字符
namespace N2707
{
//给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在 dictionary 中出现过。s 中可能会有一些 额外的字符 不在任何子字符串中。
//请你采取最优策略分割 s ，使剩下的字符 最少 。
class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<string, int> m;
    // 统计字典中每个单词出现的次数
    for (int i = 0; i < dictionary.size(); ++i)
    {
      m[dictionary[i]]++;
    }
    int n = static_cast<int>(s.size());
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = dp[i - 1] + 1;
      for (int j = 0; j < i; ++j)
      {
        string tmp = s.substr(j, i - j);
        if (m.count(tmp))
        {
          dp[i] = min(dp[i], dp[j]);
        }
      }
    }
    return dp[n];
  }
};
}

// 2719. 统计整数数目 // todo
namespace N2719
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
  int count(string num1, string num2, int min_sum, int max_sum) {
  }
};
}

// 2744. 最大字符串配对数目
namespace N2744
{
//给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。
//
//如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：
//
//字符串 words[i] 等于 words[j] 的反转字符串。
//0 <= i < j < words.length
//请你返回数组 words 中的 最大 匹配数目。
//
//注意，每个字符串最多匹配一次。
class Solution {
public:
  int maximumNumberOfStringPairs(vector<string>& words) {
    int ans = 0;
    unordered_set<string> occ;
    for (auto& word : words)
    {
      string tmp = word;
      reverse(tmp.begin(), tmp.end());
      if (occ.count(tmp))
      {
        ans++;
      }
      occ.insert(word);
    }
    return ans;
  }
};
}

// 2765. 最长交替子数组
namespace N2765
{
//给你一个下标从 0 开始的整数数组 nums 。如果 nums 中长度为 m 的子数组 s 满足以下条件，我们称它是一个 交替子数组 ：
//
//m 大于 1 。
//s1 = s0 + 1 。
//下标从 0 开始的子数组 s 与数组[s0, s1, s0, s1, ..., s(m - 1) % 2] 一样。也就是说，s1 - s0 = 1 ，s2 - s1 = -1 ，s3 - s2 = 1 ，s4 - s3 = -1 ，以此类推，直到 s[m - 1] - s[m - 2] = (-1)m 。
//请你返回 nums 中所有 交替 子数组中，最长的长度，如果不存在交替子数组，请你返回 - 1 。
//
//子数组是一个数组中一段连续 非空 的元素序列。
class Solution {
public:
  int alternatingSubarray(vector<int>& nums) {
    int res = -1;
    int cur = 1;
    int flag = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
      if ((nums[i] - nums[i - 1]) * flag == 1)
      {
        flag *= -1;
        cur += 1;
        res = max(res, cur);
      }
      else if (nums[i] - nums[i - 1] == 1)
      {
        cur = 2;
        flag = -1;
      }
      else
      {
        cur = 1;
        flag = 1;
      }
    }
    return res;
  }
};
}

// 2788. 按分隔符拆分字符串
namespace N2788
{
//给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。
//
//返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。
//
//注意
//
//separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
//拆分可能形成两个以上的字符串。
//结果字符串必须保持初始相同的先后顺序。
class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> res;
    for (auto word : words)
    {
      string tmp;
      for (auto c : word)
      {
        if (c == separator)
        {
          if (!tmp.empty())
          {
            res.push_back(tmp);
            tmp.clear();
          }
        }
        else
        {
          tmp.push_back(c);
        }
      }
      if (!tmp.empty())
      {
        res.push_back(tmp);
      }
    }
    return res;
  }
};
}

// 2809. 使数组和小于等于 x 的最少时间 // todo
namespace N2809
{
//给你两个长度相等下标从 0 开始的整数数组 nums1 和 nums2 。每一秒，对于所有下标 0 <= i < nums1.length ，nums1[i] 的值都增加 nums2[i] 。操作 完成后 ，你可以进行如下操作：
//
//  选择任一满足 0 <= i < nums1.length 的下标 i ，并使 nums1[i] = 0 。
//  同时给你一个整数 x 。
//
//  请你返回使 nums1 中所有元素之和 小于等于 x 所需要的 最少 时间，如果无法实现，那么返回 - 1 。
class Solution {
public:
  int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
  }
};
}

// 2810. 故障键盘
namespace N2810
{
//你的笔记本键盘存在故障，每当你在上面输入字符 'i' 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。
//
//给你一个下标从 0 开始的字符串 s ，请你用故障键盘依次输入每个字符。
//
//返回最终笔记本屏幕上输出的字符串。
class Solution {
public:
  string finalString(string s) {
    string res;
    for (auto c : s)
    {
      if (c == 'i')
      {
        reverse(res.begin(), res.end());
      }
      else
      {
        res.push_back(c);
      }
    }
    return res;
  }
};
}

// 2846. 边权重均等查询 // todo
namespace N2846
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
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
  }
};
}

// 2865. 美丽塔 I
namespace N2865
{
//给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
//
//你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
//
//如果以下条件满足，我们称这些塔是 美丽 的：
//
//1 <= heights[i] <= maxHeights[i]
//heights 是一个 山脉 数组。
//如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：
//
//对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
//  对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
//  请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
class Solution {
public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    vector<long long> leftHeights(maxHeights.size(), 0);
    vector<long long> rightHeights(maxHeights.size(), 0);
    // 计算左边的高度
    stack<int> st;
    int n = static_cast<int>(maxHeights.size());
    for (int i = 0; i < n; ++i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        leftHeights[i] = static_cast<long long>(maxHeights[i]) * (i + 1);
      }
      else
      {
        leftHeights[i] = leftHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (i - st.top());
      }
      st.push(i);
    }
    // 计算右边的高度
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        rightHeights[i] = static_cast<long long>(maxHeights[i]) * (maxHeights.size() - i);
      }
      else
      {
        rightHeights[i] = rightHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (st.top() - i);
      }
      st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < maxHeights.size(); ++i)
    {
      res = max(res, leftHeights[i] + rightHeights[i] - maxHeights[i]);
    }
    return res;
  }
};
}

// LCR 004. 只出现一次的数字 II
namespace LCR004
{
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

// LCR 077. 排序链表
namespace LCR077
{
class Solution {
  struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
  };
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (left != nullptr && right != nullptr)
    {
      if (left->val < right->val)
      {
        cur->next = left;
        left = left->next;
      }
      else
      {
        cur->next = right;
        right = right->next;
      }
      cur = cur->next;
    }
    cur->next = left != nullptr ? left : right;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}