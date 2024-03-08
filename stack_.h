#pragma once

// 20. ��Ч������ (��)
namespace n20
{
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

//  ��Ч�ַ��������㣺

//  �����ű�������ͬ���͵������űպϡ�
//  �����ű�������ȷ��˳��պϡ�
//  ÿ�������Ŷ���һ����Ӧ����ͬ���͵�������
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

// 232. ��ջʵ�ֶ���
namespace n232
{
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//˵����
//
//�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
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

// 316. ȥ���ظ���ĸ (�е�)
namespace n316
{
//����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // ��¼ÿ���ַ������ֵ�λ��
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

// 321. ƴ������� (����)
namespace n321
{
//�������ȷֱ�Ϊ m �� n ���������飬��Ԫ���� 0 - 9 ���ɣ���ʾ������Ȼ����λ�ϵ����֡����ڴ�������������ѡ�� k(k <= m + n) ������ƴ�ӳ�һ���µ�����Ҫ���ͬһ��������ȡ�������ֱ�������ԭ�����е����˳��
//
//���������������������������һ����ʾ��������ĳ���Ϊ k �����顣
//
//˵�� : �뾡���ܵ��Ż����㷨��ʱ��Ϳռ临�Ӷȡ�
// ��ʱ
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

// 402. �Ƶ� K λ���� (�е�)
namespace n402
{
// ����һ�����ַ�����ʾ�ķǸ����� num ��һ������ k ���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С���������ַ�����ʽ���������С�����֡�
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
    // ȥ��ǰ��0
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

// 503. ��һ������Ԫ�� II (�е�)
namespace n503
{
//����һ��ѭ������ nums �� nums[nums.length - 1] ����һ��Ԫ���� nums[0] �������� nums ��ÿ��Ԫ�ص� ��һ������Ԫ�� ��
//
//���� x �� ��һ�������Ԫ�� �ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ - 1 ��
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // �����ݼ�ջ
    stack<size_t> st;
    vector<int> res(nums.size(), -1);
    // �������
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
    // �����ݼ�ջ
    stack<int> st;
    vector<int> res(nums.size(), -1);
    // �������
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

// 581. ����������������� (�е�)
namespace n581
{
//����һ���������� nums ������Ҫ�ҳ�һ�� ���������� �����������������������������ô�������鶼���Ϊ��������
//
//�����ҳ���������� ��� �����飬��������ĳ��ȡ�
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

// 2865. ������ I (����)
namespace n2865
{
//����һ������Ϊ n �±�� 0 ��ʼ���������� maxHeights ��
//
//������������������Ͻ� n �������� i �������±�Ϊ i ���߶�Ϊ heights[i] ��
//
//��������������㣬���ǳ���Щ���� ���� �ģ�
//
//1 <= heights[i] <= maxHeights[i]
//heights ��һ�� ɽ�� ���顣
//��������±� i ����������������ô���ǳ����� heights ��һ�� ɽ�� ���飺
//
//�������� 0 < j <= i ������ heights[j - 1] <= heights[j]
//  �������� i <= k < n - 1 ������ heights[k + 1] <= heights[k]
//  ���㷵������ ������ Ҫ��ķ����У��߶Ⱥ͵����ֵ ��
class Solution {
public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    vector<long long> leftHeights(maxHeights.size(), 0);
    vector<long long> rightHeights(maxHeights.size(), 0);
    // ������ߵĸ߶�
    // ��������ջ
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
    // �����ұߵĸ߶�
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