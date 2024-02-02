#pragma once

// 94. ��������������� ����)
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

// 96. ��ͬ�Ķ��������� ���е�)
namespace N96
{
// ����һ������ n ����ǡ�� n ���ڵ�����ҽڵ�ֵ�� 1 �� n ������ͬ�� ���������� �ж����֣�������������Ķ�����������������
class Solution {
public:
  int numTrees(int n) {
    unordered_map<int, int> memo;
    function<int(int)> dfs = [&](int n)->int
      {
        if (n == 0 || n == 1)
        {
          memo[n] = 1;
          return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
          int left = memo.count(i - 1) != 0 ? memo[i - 1] : dfs(i - 1);
          int right = memo.count(n - i) != 0 ? memo[n - i] : dfs(n - i);
          res += left * right;
        }
        memo[n] = res;
        return res;
      };
    return dfs(n);
  }
};

class Solution2 {
public:
  int numTrees(int n) {
    vector<int> G(n + 1, 0);
    G[0] = 1;
    G[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        G[i] += G[j - 1] * G[i - j];
      }
    }
    return G[n];
  }
};
}

// 99. �ָ����������� ������)
namespace N99
{
// ��������������ĸ��ڵ� root �������е� ǡ�� �����ڵ��ֵ������ؽ��������ڲ��ı���ṹ������£��ָ������
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  void recoverTree(TreeNode* root) {
    // ����������
    std::vector<int> nums;
    // �����������ڵ�
    std::vector<int> swap;
    function<void(TreeNode*)> traverse = [&](TreeNode* node)
      {
        if (nullptr == node)
        {
          return;
        }
        traverse(node->left);
        nums.push_back(node->val);
        traverse(node->right);
      };

    function<void()> findNodes = [&]()
      {
        int first = -1;
        int second = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
          if (nums[i] > nums[i + 1])
          {
            if (first == -1)
            {
              first = i;
              second = i + 1;
            }
            else
            {
              second = i + 1;
            }
          }
        }
        swap.push_back(nums[first]);
        swap.push_back(nums[second]);
      };

    function<void(TreeNode*)> swapNodes = [&](TreeNode* node)
      {
        if (nullptr == node)
        {
          return;
        }
        swapNodes(node->left);
        if (node->val == swap[0])
        {
          node->val = swap[1];
        }
        else if (node->val == swap[1])
        {
          node->val = swap[0];
        }
        swapNodes(node->right);
      };

    traverse(root);
    findNodes();
    swapNodes(root);
  }
};
}

// 100. ��ͬ���� ����)
namespace N100
{
//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
    {
      return true;
    }
    if (p == nullptr || q == nullptr)
    {
      return false;
    }
    if (p->val != q->val)
    {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
}

// 106. �����������������й�������� ���е�)
namespace N106
{
//���������������� inorder �� postorder ������ inorder �Ƕ���������������� postorder ��ͬһ�����ĺ�����������㹹�첢������� ��������
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty())
    {
      return nullptr;
    }
    int root = *postorder.rbegin();
    int inorderRootIndex = 0;
    for (int i = 0; i < inorder.size(); ++i)
    {
      if (inorder[i] == root)
      {
        inorderRootIndex = i;
        break;
      }
    }
    TreeNode* node = new TreeNode(root);
    vector<int> leftInorder(inorder.begin(), inorder.begin() + inorderRootIndex);
    vector<int> rightInorder(inorder.begin() + inorderRootIndex + 1, inorder.end());
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + inorderRootIndex);
    vector<int> rightPostorder(postorder.begin() + inorderRootIndex, postorder.end() - 1);
    node->left = buildTree(leftInorder, leftPostorder);
    node->right = buildTree(rightInorder, rightPostorder);
    return node;
  }
};
}

// 109. ��������ת������������ ���е�)
namespace N109
{
//����һ���������ͷ�ڵ�  head �����е�Ԫ�� ���������� ������ת��Ϊ�߶�ƽ��Ķ�����������
//
//�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ���� 1��
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr)
    {
      return nullptr;
    }
    // �ҵ�������м�ڵ�
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // �Ͽ�����
    if (pre != nullptr)
    {
      pre->next = nullptr;
    }
    TreeNode* node = new TreeNode(slow->val);
    if (slow == head)
    {
      return node;
    }
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return node;
  }
};
}

// 110. ƽ������� ����)
namespace N110
{
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
// һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  bool isBalanced(TreeNode* root) {
    bool res = true;
    function<int(TreeNode*)> traverse = [&](TreeNode* node)->int
      {
        if (node == nullptr || res == false)
        {
          return 0;
        }
        int nLeft = traverse(node->left);
        int nRight = traverse(node->right);
        if (abs(nLeft - nRight) > 1)
        {
          res = false;
        }
        return max(nLeft, nRight) + 1;
      };
    traverse(root);
    return res;
  }
};
}

// 111. ����������С��� ����)
namespace N111
{
//����һ�����������ҳ�����С��ȡ�
//
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//
//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  int minDepth(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> q;
    if (root != nullptr)
    {
      q.push(root);
      res++;
    }
    while (!q.empty())
    {
      size_t size = q.size();
      for (size_t i = 0; i < size; i++)
      {
        TreeNode* node = q.front();
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
        {
          return res;
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
      res++;
    }
    return res;
  }
};
}

// 112. ·���ܺ� (��)
namespace N112
{
//����������ĸ��ڵ� root ��һ����ʾĿ��͵����� targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ��� targetSum ��������ڣ����� true �����򣬷��� false ��
//
//Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    bool res = false;
    function<void(TreeNode* root, int)> dfs = [&](TreeNode* root, int sum)
      {
        if (nullptr == root || true == res)
        {
          return;
        }
        if (nullptr == root->left && nullptr == root->right && sum + root->val == targetSum)
        {
          res = true;
        }
        dfs(root->left, sum + root->val);
        dfs(root->right, sum + root->val);
      };
    dfs(root, 0);
    return res;
  }
};
}

// 113. ·���ܺ� II (�е�)
namespace N113
{
//����������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����
//
//Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(TreeNode* root, int)> dfs = [&](TreeNode* root, int sum)
      {
        if (nullptr == root)
        {
          return;
        }
        path.emplace_back(root->val);
        if (nullptr == root->left && nullptr == root->right && sum + root->val == targetSum)
        {
          res.emplace_back(path);
        }
        dfs(root->left, sum + root->val);
        dfs(root->right, sum + root->val);
        path.pop_back();
      };
    dfs(root, 0);
    return res;
  }
};
}

// 116. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� (�е�)
namespace N116
{
//����һ�� ���������� ��������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�
//
//struct Node {
//  int val;
//  Node* left;
//  Node* right;
//  Node* next;
//}
//�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
//
//��ʼ״̬�£����� next ָ�붼������Ϊ NULL��

// Definition for a Node.
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
    queue<Node*> q;
    if (root != nullptr)
    {
      q.push(root);
    }
    while (!q.empty())
    {
      size_t size = q.size();
      for (size_t i = 0; i < size; ++i)
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

// 117. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II (�е�)
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

// 124. �������е����·���� (����)
namespace N124
{
//�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣
//
//·���� ��·���и��ڵ�ֵ���ܺ͡�
//
//����һ���������ĸ��ڵ� root �������� ���·���� ��
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    function<int(TreeNode* root)> traverse = [&](TreeNode* root)->int
      {
        if (nullptr == root)
        {
          return 0;
        }
        int left = max(traverse(root->left), 0);
        int right = max(traverse(root->right), 0);
        res = max(res, root->val + left + right);
        return root->val + max(left, right);
      };
    traverse(root);
    return res;
  }
};
}

// 129. �����Ҷ�ӽڵ�����֮�� (�е�)
namespace N129
{
//����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
//ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�
//
//���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
//����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��
//
//Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int res = 0;
    function<void(TreeNode* root, int sum)> traverse = [&](TreeNode* root, int sum)
      {
        if (nullptr == root)
        {
          return;
        }
        sum = sum * 10 + root->val;
        if (nullptr == root->left && nullptr == root->right)
        {
          res += sum;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
      };
    traverse(root, 0);
    return res;
  }
};
}

// 144. ��������ǰ����� (��)
namespace N144
{
// ����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty())
    {
      while (cur != nullptr)
      {
        res.push_back(cur->val);
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      cur = cur->right;
    }
    return res;
  }
};
}

// 145. �������ĺ������ (��)
namespace N145
{
// ����һ�ö������ĸ��ڵ� root ��������ڵ�ֵ�� ������� ��
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
      while (cur != nullptr)
      {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      if (cur->right == nullptr || cur->right == pre)
      {
        res.push_back(cur->val);
        pre = cur;
        cur = nullptr;
      }
      else
      {
        st.push(cur);
        cur = cur->right;
      }
    }
    return res;
  }
};
}

// 173. ���������������� (�е�)
namespace N173
{
//ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������
//BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
//boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
//int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
//ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�
//
//����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    inorder(root);
  }

  int next() {
    if (hasNext())
    {
      return inorder_[index_++];
    }
    return -1;
  }

  bool hasNext() {
    return index_ != inorder_.size();
  }
private:
  void inorder(TreeNode* root)
  {
    if (nullptr == root)
    {
      return;
    }
    inorder(root->left);
    inorder_.push_back(root->val);
    inorder(root->right);
  }
private:
  std::vector<int> inorder_;
  int index_ = 0;
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
}