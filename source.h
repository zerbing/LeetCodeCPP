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

// 18. ����֮��
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

// 19. ɾ������ĵ����� N �����
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
    // ɾ��������n���ڵ�
    slow->next = slow->next->next;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// 20. ��Ч������
namespace N20
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

// 21. �ϲ�������������
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

// 39. ����ܺ�
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
          // ����ѡ��
          path.push_back(candidates[i]);
          backtrace(path, target - candidates[i], i);
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace(path, target, 0);
    return res;
  }
};
}

// 40. ����ܺ� II
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
          // �ų��ظ���ѡ��
          if (i > cur && candidates[i] == candidates[i - 1])
          {
            continue;
          }
          // ����ѡ��
          path.push_back(candidates[i]);
          backtrace(target - candidates[i], i + 1);
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace(target, 0);
    return res;
  }
};
}

// 47. ȫ���� II
namespace N47
{
class Solution {
  // ����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ����
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
          // �ų��ظ���ѡ��
          if (count(path.begin(), path.end(), i))
          {
            continue;
          }
          if (i > 0 && nums[i] == nums[i - 1] && !count(path.begin(), path.end(), i - 1))
          {
            continue;
          }
          // ����ѡ��
          path.push_back(i);
          backtrace();
          // ����ѡ��
          path.pop_back();
        }
      };
    backtrace();
    return res;
  }
};
}

// 52. N �ʺ� II
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

// 94. ���������������
namespace N94
{
//����һ���������ĸ��ڵ� root ���������� ���� ������
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// ջ�ⷨ���Ƽ�
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
// �ݹ�ⷨ
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

// 117. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
namespace N117
{
//����һ����������

//struct Node {
//  int val;
//  Node* left;
//  Node* right;
//  Node* next;
//}
//�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL ��

//��ʼ״̬�£����� next ָ�붼������Ϊ NULL ��
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

// 383. �����
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

// 410. �ָ���������ֵ
namespace N410
{
//����һ���Ǹ��������� nums ��һ������ k ������Ҫ���������ֳ� k ���ǿյ����������顣
//
//���һ���㷨ʹ���� k ����������Ժ͵����ֵ��С��
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
          // ͨ��ǰ׺�ͼ�����������Ĵ�С
          int sum = preSum[j] - preSum[a];
          tmp = min(tmp, max(sum, dp[i - 1][a]));
          // ����sum��i�ݼ���dp[i-1][a]��i���������������󼴿��˳�ѭ��
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

// 447. �����ڵ�����
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

// 466. ͳ���ظ����� // todo
namespace N466
{
//���� str = [s, n] ��ʾ str �� n ���ַ��� s ���ӹ��ɡ�
//
//���磬str == ["abc", 3] == "abcabcabc" ��
//������Դ� s2 ��ɾ��ĳЩ�ַ�ʹ���Ϊ s1������ַ��� s1 ���Դ��ַ��� s2 ��á�
//
//���磬���ݶ��壬s1 = "abc" ���Դ� s2 = "abdbec" ��ã�����Ҫɾ���Ӵ�����б���ʶ���ַ���
//���ڸ��������ַ��� s1 �� s2 ���������� n1 �� n2 ���ɴ˹���õ������ַ��������� str1 = [s1, n1]��str2 = [s2, n2] ��
//
//�����ҳ�һ��������� m �������� str = [str2, m] ���Դ� str1 ���
class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
  }
};
}

// 670. ��󽻻�
namespace N670
{
// ����һ���Ǹ���������������Խ���һ�������е�������λ���������ܵõ������ֵ��
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

// 2085. ͳ�Ƴ��ֹ�һ�εĹ����ַ���
namespace N2085
{
// ���������ַ������� words1 �� words2 �����㷵���������ַ��������� ��ǡ�ó���һ�� ���ַ�������Ŀ��
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

// 2171. �ó�������Ŀ��ħ����
namespace N2171
{
//����һ�� ������ ���� beans ������ÿ��������ʾһ��������װ��ħ��������Ŀ��
//
//�����ÿ�������� �ó� һЩ���ӣ�Ҳ���� ���ó�����ʹ��ʣ�µ� �ǿ� �����У��� ���ٻ���һ�� ħ�����Ĵ��ӣ�ħ��������Ŀ ��ȡ�һ����ħ�����Ӵ�����ȡ�����㲻���ٽ����ŵ��κδ����С�
//
//�뷵������Ҫ�ó�ħ������ ������Ŀ��
class Solution {
public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    // ǰ׺��
    vector<long long> preSum(beans.size() + 1, 0);
    for (int i = 1; i <= beans.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + beans[i - 1];
    }
    long long res = INT64_MAX;
    for (int i = 0; i < beans.size(); ++i)
    {
      // ǰi-1�������е�ħ������Ŀ
      long long sum = preSum[i];
      // ��n-i-1�������е�ħ������Ŀ
      sum += preSum[beans.size()] - preSum[i] - beans[i] * (beans.size() - i);
      res = min(res, sum);
    }
    return res;
  }
};
}

// 2645. ������Ч�ַ��������ٲ�����
namespace N2645
{
//����һ���ַ��� word ��������������κ�λ�ò��� "a"��"b" �� "c" ����Σ�����ʹ word ��Ч ��Ҫ�����������ĸ����
//
//����ַ��������� "abc" ������εõ�������Ϊ���ַ��� ��Ч ��
//word ������ĸ "a"��"b" �� "c" ���
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

// 2678. ���˵���Ŀ
namespace N2678
{
//����һ���±�� 0 ��ʼ���ַ��� details ��details ��ÿ��Ԫ�ض���һλ�˿͵���Ϣ����Ϣ�ó���Ϊ 15 ���ַ�����ʾ����ʾ��ʽ���£�
//
//ǰʮ���ַ��ǳ˿͵��ֻ����롣
//��������һ���ַ��ǳ˿͵��Ա�
//�����������ַ��ǳ˿͵����䡣
//��������ַ��ǳ˿͵���λ�š�
//���㷵�س˿������� �ϸ���� 60 �� ��������
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

// 2696. ɾ���Ӵ�����ַ�����С����
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

// 2670. �ҳ���ͬԪ����Ŀ������
namespace N2670
{
//����һ���±�� 0 ��ʼ������ nums �����鳤��Ϊ n ��
//
//nums �� ��ͬԪ����Ŀ�� ���������һ������Ϊ n ������ diff ��ʾ������ diff[i] ����ǰ׺ nums[0, ..., i] �в�ͬԪ�ص���Ŀ ��ȥ ��׺ nums[i + 1, ..., n - 1] �в�ͬԪ�ص���Ŀ��
//
//���� nums �� ��ͬԪ����Ŀ�� ���顣
//
//ע�� nums[i, ..., j] ��ʾ nums ��һ�����±� i ��ʼ���±� j �����������飨�����±� i �� j ��ӦԪ�أ����ر���Ҫ˵�����ǣ���� i > j ���� nums[i, ..., j] ��ʾһ���������顣
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

// 2707. �ַ����еĶ����ַ�
namespace N2707
{
//����һ���±�� 0 ��ʼ���ַ��� s ��һ�������ֵ� dictionary ������Ҫ�� s �ָ�����ɸ� �����ص� �����ַ�����ÿ�����ַ������� dictionary �г��ֹ���s �п��ܻ���һЩ ������ַ� �����κ����ַ����С�
//�����ȡ���Ų��Էָ� s ��ʹʣ�µ��ַ� ���� ��
class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<string, int> m;
    // ͳ���ֵ���ÿ�����ʳ��ֵĴ���
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

// 2719. ͳ��������Ŀ // todo
namespace N2719
{
//�������������ַ��� num1 �� num2 ���Լ��������� max_sum �� min_sum �����һ������ x �����������������ǳ�����һ����������
//
//num1 <= x <= num2
//min_sum <= digit_sum(x) <= max_sum.
//���㷵�غ���������Ŀ���𰸿��ܴܺ��뷵�ش𰸶� 109 + 7 ȡ���Ľ����
//
//ע�⣬digit_sum(x) ��ʾ x ��λ����֮�͡�
class Solution {
public:
  int count(string num1, string num2, int min_sum, int max_sum) {
  }
};
}

// 2744. ����ַ��������Ŀ
namespace N2744
{
//����һ���±�� 0 ��ʼ������ words �������а��� ������ͬ ���ַ�����
//
//����ַ��� words[i] ���ַ��� words[j] �����������������ǳ����ǿ���ƥ�䣺
//
//�ַ��� words[i] ���� words[j] �ķ�ת�ַ�����
//0 <= i < j < words.length
//���㷵������ words �е� ��� ƥ����Ŀ��
//
//ע�⣬ÿ���ַ������ƥ��һ�Ρ�
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

// 2765. �����������
namespace N2765
{
//����һ���±�� 0 ��ʼ���������� nums ����� nums �г���Ϊ m �������� s �����������������ǳ�����һ�� ���������� ��
//
//m ���� 1 ��
//s1 = s0 + 1 ��
//�±�� 0 ��ʼ�������� s ������[s0, s1, s0, s1, ..., s(m - 1) % 2] һ����Ҳ����˵��s1 - s0 = 1 ��s2 - s1 = -1 ��s3 - s2 = 1 ��s4 - s3 = -1 ���Դ����ƣ�ֱ�� s[m - 1] - s[m - 2] = (-1)m ��
//���㷵�� nums ������ ���� �������У���ĳ��ȣ���������ڽ��������飬���㷵�� - 1 ��
//
//��������һ��������һ������ �ǿ� ��Ԫ�����С�
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

// 2788. ���ָ�������ַ���
namespace N2788
{
//����һ���ַ������� words ��һ���ַ� separator �����㰴 separator ��� words �е�ÿ���ַ�����
//
//����һ���ɲ�ֺ�����ַ�����ɵ��ַ������飬���������ַ��� ��
//
//ע��
//
//separator ���ھ�����ַ�����λ�ã������������ڽ���ַ����С�
//��ֿ����γ��������ϵ��ַ�����
//����ַ������뱣�ֳ�ʼ��ͬ���Ⱥ�˳��
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

// 2809. ʹ�����С�ڵ��� x ������ʱ�� // todo
namespace N2809
{
//����������������±�� 0 ��ʼ���������� nums1 �� nums2 ��ÿһ�룬���������±� 0 <= i < nums1.length ��nums1[i] ��ֵ������ nums2[i] ������ ��ɺ� ������Խ������²�����
//
//  ѡ����һ���� 0 <= i < nums1.length ���±� i ����ʹ nums1[i] = 0 ��
//  ͬʱ����һ������ x ��
//
//  ���㷵��ʹ nums1 ������Ԫ��֮�� С�ڵ��� x ����Ҫ�� ���� ʱ�䣬����޷�ʵ�֣���ô���� - 1 ��
class Solution {
public:
  int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
  }
};
}

// 2810. ���ϼ���
namespace N2810
{
//��ıʼǱ����̴��ڹ��ϣ�ÿ���������������ַ� 'i' ʱ�����ᷴת����д���ַ����������������ַ����������������
//
//����һ���±�� 0 ��ʼ���ַ��� s �������ù��ϼ�����������ÿ���ַ���
//
//�������ձʼǱ���Ļ��������ַ�����
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

// 2846. ��Ȩ�ؾ��Ȳ�ѯ // todo
namespace N2846
{
//����һ���� n ���ڵ���ɵ����������ڵ㰴�� 0 �� n - 1 ��š�����һ������ n ��һ������Ϊ n - 1 �Ķ�ά�������� edges ������ edges[i] = [ui, vi, wi] ��ʾ���д���һ��λ�ڽڵ� ui �ͽڵ� vi ֮�䡢Ȩ��Ϊ wi �ıߡ�
//
//�����һ������Ϊ m �Ķ�ά�������� queries ������ queries[i] = [ai, bi] ������ÿ����ѯ�������ҳ�ʹ�� ai �� bi ·����ÿ���ߵ�Ȩ���������� ��С�������� ����һ�β����У������ѡ�����ϵ�����һ���ߣ�������Ȩ�ظ���Ϊ����ֵ��
//
//ע�⣺
//
//��ѯ֮�� �໥���� �ģ�����ζ��ÿ���µĲ�ѯʱ��������ص� ��ʼ״̬ ��
//�� ai �� bi��·����һ���� ��ͬ �ڵ���ɵ����У��ӽڵ� ai ��ʼ�����ڵ� bi �����������������ڵ������ڵ������й���һ���ߡ�
//����һ������Ϊ m ������ answer ������ answer[i] �ǵ� i ����ѯ�Ĵ𰸡�

class Solution {
public:
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
  }
};
}

// 2865. ������ I
namespace N2865
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

// LCR 004. ֻ����һ�ε����� II
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

// LCR 077. ��������
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