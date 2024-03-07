#pragma once

// 23. �ϲ� K ����������
namespace n23
{
//����һ���������飬ÿ�������Ѿ����������С�
//
//���㽫��������ϲ���һ�����������У����غϲ��������
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
    // ע�⣺����ʹ���˴��ڷ��ţ���ΪC++�����ȶ�����һ������
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

// LCP 30. ħ����Ϸ (�е�)
namespace lcp30
{
//С�۵�ǰλ��ħ����Ϸ��һ�㣬���� N �����䣬���Ϊ 0 ~N - 1��ÿ������Ĳ�Ѫ���� / �������Ѫ��Ӱ��������� nums������������ʾ���߲�Ѫ��ֵ����Ѫ�����Ӷ�Ӧ��ֵ��������ʾ��������˺�ֵ����Ѫ�����ٶ�Ӧ��ֵ��0 ��ʾ�����Ѫ����Ӱ�졣
//
//С�۳�ʼѪ��Ϊ 1���������ޡ��ٶ�С��ԭ�ƻ�������������������з��䲹Ѫ / ��֣�Ϊ��֤Ѫ��ʼ��Ϊ��ֵ��С����Է������˳����е�����ÿ�ν��ܽ�һ�����﷿�䣨�����ķ��䣩����������˳��ĩβ���뷵��С��������Ҫ�������Σ�����˳���������з��䡣������˳��Ҳ�޷�������ȫ�����䣬�뷵�� - 1��
// �����ڴ�����
class Solution {
public:
  int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 1) < 0)
    {
      return -1;
    }
    size_t n = nums.size();
    // dp[i][j] ��ʾǰ i �����䣬�����Ĵ���Ϊ j ʱ��ʣ���Ѫ��
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
    if (accumulate(nums.begin(), nums.end(), 1LL) < 0) // ע�������1LL������ʾ�����ͳ���1
    {
      return -1;
    }
    size_t n = nums.size();
    int res = 0;
    long long sum = 1; // ��sum�����͸�Ϊlong long
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

// 225. �ö���ʵ��ջ (��)
namespace n225
{
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
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