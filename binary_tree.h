#pragma once

// 94. 二叉树的中序遍历 （简单)
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

// 96. 不同的二叉搜索树 （中等)
namespace N96
{
// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
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

// 99. 恢复二叉搜索树 （困难)
namespace N99
{
// 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树
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
    // 中序遍历结果
    std::vector<int> nums;
    // 交换的两个节点
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

// 100. 相同的树 （简单)
namespace N100
{
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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

// 106. 从中序与后序遍历序列构造二叉树 （中等)
namespace N106
{
//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树。
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

// 109. 有序链表转换二叉搜索树 （中等)
namespace N109
{
//给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
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
    // 找到链表的中间节点
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // 断开链表
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

// 110. 平衡二叉树 （简单)
namespace N110
{
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
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

// 111. 二叉树的最小深度 （简单)
namespace N111
{
//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明：叶子节点是指没有子节点的节点。
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

// 112. 路径总和 (简单)
namespace N112
{
//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
//
//叶子节点 是指没有子节点的节点。
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

// 113. 路径总和 II (中等)
namespace N113
{
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
//叶子节点 是指没有子节点的节点。
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

// 116. 填充每个节点的下一个右侧节点指针 (中等)
namespace N116
{
//给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
//
//struct Node {
//  int val;
//  Node* left;
//  Node* right;
//  Node* next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
//初始状态下，所有 next 指针都被设置为 NULL。

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

// 117. 填充每个节点的下一个右侧节点指针 II (中等)
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

// 124. 二叉树中的最大路径和 (困难)
namespace N124
{
//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
//
//路径和 是路径中各节点值的总和。
//
//给你一个二叉树的根节点 root ，返回其 最大路径和 。
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

// 129. 求根到叶子节点数字之和 (中等)
namespace N129
{
//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//每条从根节点到叶节点的路径都代表一个数字：
//
//例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//计算从根节点到叶节点生成的 所有数字之和 。
//
//叶节点 是指没有子节点的节点。

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

// 144. 二叉树的前序遍历 (简单)
namespace N144
{
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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

// 145. 二叉树的后序遍历 (简单)
namespace N145
{
// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
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

// 173. 二叉搜索树迭代器 (中等)
namespace N173
{
//实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
//BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
//boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
//int next()将指针向右移动，然后返回指针处的数字。
//注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
//
//你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
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