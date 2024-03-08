#pragma once

// 20. 有效的括号 (简单)
namespace n20
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

// 232. 用栈实现队列
namespace n232
{
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//
//你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
class MyQueue {
public:
  MyQueue() {
  }

  void push(int x) {
    st1.push(x);
  }

  int pop() {
    while (st1.size() > 1)
    {
      st2.push(st1.top());
      st1.pop();
    }
    int res = st1.top();
    st1.pop();
    while (st2.size() > 0)
    {
      st1.push(st2.top());
      st2.pop();
    }
    return res;
  }

  int peek() {
    while (st1.size() > 1)
    {
      st2.push(st1.top());
      st1.pop();
    }
    int res = st1.top();
    st1.pop();
    st2.push(res);
    while (st2.size() > 0)
    {
      st1.push(st2.top());
      st2.pop();
    }
    return res;
  }

  bool empty() {
    return st1.empty();
  }
private:
  stack<int> st1;
  stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
}

// 316. 去除重复字母 (中等)
namespace n316
{
//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // 记录每个字符最后出现的位置
    vector<int> lastIdx(26, -1);
    for (int i = 0; i < s.size(); ++i)
    {
      lastIdx[s[i] - 'a'] = i;
    }
    stack<char> st;
    vector<bool> visited(26, false);
    for (int i = 0; i < s.size(); ++i)
    {
      if (visited[s[i] - 'a'])
      {
        continue;
      }
      while (!st.empty() && st.top() > s[i] && lastIdx[st.top() - 'a'] > i)
      {
        visited[st.top() - 'a'] = false;
        st.pop();
      }
      st.push(s[i]);
      visited[s[i] - 'a'] = true;
    }
    string res;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
}

// 321. 拼接最大数 (困难)
namespace n321
{
//给定长度分别为 m 和 n 的两个数组，其元素由 0 - 9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k(k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
//
//求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
//
//说明 : 请尽可能地优化你算法的时间和空间复杂度。
// 超时
class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    function<void(int, int, vector<int>&)> dfs = [&](int index1, int index2, vector<int>& nums) {
      if (!nums.empty() && !res.empty() && lexicographical_compare(nums.begin(), nums.end(), res.begin(), res.begin() + nums.size()))
      {
        return;
      }
      if (nums.size() == k)
      {
        if (res.empty() || res < nums)
        {
          res = nums;
        }
        return;
      }
      for (int i = index1; i < nums1.size(); ++i)
      {
        nums.push_back(nums1[i]);
        dfs(i + 1, index2, nums);
        nums.pop_back();
      }
      for (int i = index2; i < nums2.size(); ++i)
      {
        nums.push_back(nums2[i]);
        dfs(index1, i + 1, nums);
        nums.pop_back();
      }
      };
    vector<int> nums;
    dfs(0, 0, nums);
    return res;
  }
};
// todo
class Solution2 {
public:
  vector<int> maxNumber([[maybe_unused]] vector<int>& nums1, [[maybe_unused]] vector<int>& nums2, [[maybe_unused]] int k) {
  }
};
}

// 402. 移掉 K 位数字 (中等)
namespace n402
{
// 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    for (int i = 0; i < num.size(); ++i)
    {
      while (k > 0 && !st.empty() && st.top() > num[i])
      {
        st.pop();
        --k;
      }
      st.push(num[i]);
    }
    while (k > 0)
    {
      st.pop();
      --k;
    }
    string res;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    // 去掉前导0
    int index = 0;
    while (index < res.size() && res[index] == '0')
    {
      ++index;
    }
    if (index == res.size())
    {
      return "0";
    }
    return res.substr(index);
  }
};
}

// 503. 下一个更大元素 II (中等)
namespace n503
{
//给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
//
//数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 - 1 。
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // 单调递减栈
    stack<size_t> st;
    vector<int> res(nums.size(), -1);
    // 正向遍历
    for (size_t i = 0; i < nums.size() * 2; ++i)
    {
      while (!st.empty() && nums[st.top()] < nums[i % nums.size()])
      {
        res[st.top()] = nums[i % nums.size()];
        st.pop();
      }
      if (i < nums.size())
      {
        st.push(i);
      }
    }
    return res;
  }
};
class Solution2 {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // 单调递减栈
    stack<int> st;
    vector<int> res(nums.size(), -1);
    // 反向遍历
    for (long long i = nums.size() * 2 - 1; i >= 0; --i)
    {
      while (!st.empty() && st.top() <= nums[i % nums.size()])
      {
        st.pop();
      }
      if (!st.empty())
      {
        res[i % nums.size()] = st.top();
      }
      st.push(nums[i % nums.size()]);
    }
    return res;
  }
};
}

// 581. 最短无序连续子数组 (中等)
namespace n581
{
//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
//请你找出符合题意的 最短 子数组，并输出它的长度。
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    stack<int> st;
    int left = static_cast<int>(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
      while (!st.empty() && nums[st.top()] > nums[i])
      {
        left = min(left, st.top());
        st.pop();
      }
      st.push(i);
    }
    st = stack<int>();
    int right = 0;
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i)
    {
      while (!st.empty() && nums[st.top()] < nums[i])
      {
        right = max(right, st.top());
        st.pop();
      }
      st.push(i);
    }
    return right > left ? right - left + 1 : 0;
  }
};
}

// 2865. 美丽塔 I (困难)
namespace n2865
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
    // 单调递增栈
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