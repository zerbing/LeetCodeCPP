#pragma once

// 23. 合并 K 个升序链表
namespace n23
{
//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct CompareNode {
  bool operator()(ListNode* const& p1, ListNode* const& p2) {
    // 注意：这里使用了大于符号，因为C++的优先队列是一个最大堆
    return p1->val > p2->val;
  }
};
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> pq;
    for (auto list : lists)
    {
      if (list != nullptr)
      {
        pq.push(list);
      }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (!pq.empty())
    {
      ListNode* node = pq.top();
      pq.pop();
      cur->next = node;
      cur = cur->next;
      if (node->next != nullptr)
      {
        pq.push(node->next);
      }
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// LCP 30. 魔塔游戏 (中等)
namespace lcp30
{
//小扣当前位于魔塔游戏第一层，共有 N 个房间，编号为 0 ~N - 1。每个房间的补血道具 / 怪物对于血量影响记于数组 nums，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；0 表示房间对血量无影响。
//
//小扣初始血量为 1，且无上限。假定小扣原计划按房间编号升序访问所有房间补血 / 打怪，为保证血量始终为正值，小扣需对房间访问顺序进行调整，每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回 - 1。
// 超出内存限制
class Solution {
public:
  int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 1) < 0)
    {
      return -1;
    }
    size_t n = nums.size();
    // dp[i][j] 表示前 i 个房间，调整的次数为 j 时，剩余的血量
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));
    dp[0][0] = 1;
    for (size_t i = 1; i <= n; ++i)
    {
      dp[i][0] = dp[i - 1][0] + nums[i - 1];
      if (dp[i][0] <= 0)
      {
        break;
      }
    }
    if (dp[n][0] > 0)
    {
      return 0;
    }
    for (size_t i = 1; i <= n; ++i)
    {
      for (size_t j = 1; j <= i; ++j)
      {
        int num = nums[i - 1];
        if (num > 0 && dp[i - 1][j] > 0)
        {
          dp[i][j] = dp[i - 1][j] + num;
        }
        else
        {
          if (dp[i - 1][j] > 0)
          {
            dp[i][j] = max(0, dp[i - 1][j] + num);
          }
          if (dp[i - 1][j - 1] > 0)
          {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
          }
        }
        if (i == n && dp[i][j] > 0)
        {
          return static_cast<int>(j);
        }
      }
    }
    return -1;
  }
};

class Solution2 {
public:
  int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 1LL) < 0) // 注意这里的1LL，它表示长整型常量1
    {
      return -1;
    }
    size_t n = nums.size();
    int res = 0;
    long long sum = 1; // 将sum的类型改为long long
    priority_queue<int, vector<int>, greater<int>> q;
    for (size_t i = 0; i < n; ++i)
    {
      sum += nums[i];
      if (nums[i] < 0)
      {
        q.push(nums[i]);
      }
      if (sum <= 0)
      {
        sum -= q.top();
        q.pop();
        ++res;
      }
    }
    return res;
  }
};
}

// 225. 用队列实现栈 (简单)
namespace n225
{
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {
  }

  /** Push element x onto stack. */
  void push(int x) {
    q1.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    while (q1.size() > 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    int res = q1.front();
    q1.pop();
    swap(q1, q2);
    return res;
  }

  /** Get the top element. */
  int top() {
    while (q1.size() > 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    int res = q1.front();
    q2.push(res);
    q1.pop();
    swap(q1, q2);
    return res;
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return q1.empty();
  }
private:
  queue<int> q1;
  queue<int> q2;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
}