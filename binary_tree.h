#pragma once

// 94. 二叉树的中序遍历 (简单)
namespace n94
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

// 96. 不同的二叉搜索树 (中等)
namespace n96
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

// 99. 恢复二叉搜索树 (困难)
namespace n99
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

// 100. 相同的树 (简单)
namespace n100
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

// 105. 从前序与中序遍历序列构造二叉树 (中等)
namespace n105
{
//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
// preorder 和 inorder 均 无重复 元素
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty())
    {
      return nullptr;
    }
    int root = *preorder.begin();
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
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + inorderRootIndex);
    vector<int> rightPreorder(preorder.begin() + inorderRootIndex + 1, preorder.end());
    node->left = buildTree(leftPreorder, leftInorder);
    node->right = buildTree(rightPreorder, rightInorder);
    return node;
  }
};
}

// 106. 从中序与后序遍历序列构造二叉树 (中等)
namespace n106
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

// 109. 有序链表转换二叉搜索树 (中等)
namespace n109
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

// 110. 平衡二叉树 (简单)
namespace n110
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

// 111. 二叉树的最小深度 (简单)
namespace n111
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
namespace n112
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
namespace n113
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
namespace n116
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
namespace n117
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
namespace n124
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
namespace n129
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
namespace n144
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
namespace n145
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
namespace n173
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

// 236. 二叉树的最近公共祖先 (中等)
namespace n236
{
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (nullptr == root || root == p || root == q)
    {
      return root;
    }
    TreeNode* res = nullptr;
    function<bool(TreeNode* root, TreeNode* p, TreeNode* q)> dfs = [&](TreeNode* root, TreeNode* p, TreeNode* q)->bool
      {
        if (nullptr == root)
        {
          return false;
        }
        if (root == p || root == q)
        {
          if (dfs(root->left, p, q) || dfs(root->right, p, q))
          {
            res = root;
          }
          return true;
        }
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if (left && right)
        {
          res = root;
        }
        return left || right;
      };
    dfs(root, p, q);
    return res;
  }
};
}

// 2583. 二叉树中的第 K 大层和 (中等)
namespace n2583
{
//给你一棵二叉树的根节点 root 和一个正整数 k 。
//
//树中的 层和 是指 同一层 上节点值的总和。
//
//返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 - 1 。
//
//注意，如果两个节点与根节点的距离相同，则认为它们在同一层。
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
  long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<long long> laySum;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
      int n = static_cast<int>(q.size());
      long long sum = 0;
      for (int i = 0; i < n; i++)
      {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left != nullptr)
        {
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
      laySum.push_back(sum);
    }
    if (laySum.size() >= k)
    {
      sort(laySum.begin(), laySum.end(), greater<long long>());
      return laySum[k - 1];
    }
    return -1;
  }
};
}

// 337. 打家劫舍 III (中等)
namespace n337
{
//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
//
//除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
//
//给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
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
  int rob(TreeNode* root) {
    function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* root)->pair<int, int>
      {
        if (nullptr == root)
        {
          return { 0, 0 };
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int rob = root->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        return { rob, notRob };
      };
    pair<int, int> p = dfs(root);
    return max(p.first, p.second);
  }
};
}

// 889. 根据前序和后序遍历构造二叉树 (中等)
namespace n889
{
//给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。
//
//如果存在多个答案，您可以返回其中 任何 一个。
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
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    if (preorder.empty() || postorder.empty())
    {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
    {
      return root;
    }
    int leftRoot = preorder[1];
    int leftRootIndex = 0;
    for (int i = 0; i < postorder.size(); ++i)
    {
      if (postorder[i] == leftRoot)
      {
        leftRootIndex = i;
        break;
      }
    }
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftRootIndex + 1);
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftRootIndex + 1);
    vector<int> rightPreorder(preorder.begin() + 1 + leftRootIndex + 1, preorder.end());
    vector<int> rightPostorder(postorder.begin() + leftRootIndex + 1, postorder.end() - 1);
    root->left = constructFromPrePost(leftPreorder, leftPostorder);
    root->right = constructFromPrePost(rightPreorder, rightPostorder);
    return root;
  }
};
}

// 938. 二叉搜索树的范围和 (简单)
namespace n938
{
//给定二叉搜索树的根结点 root，返回值位于范围[low, high] 之间的所有结点的值的和。
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
  int rangeSumBST(TreeNode* root, int low, int high) {
    int res = 0;
    function<void(TreeNode* root, int low, int high)> dfs = [&](TreeNode* root, int low, int high)
      {
        if (nullptr == root)
        {
          return;
        }
        if (root->val <= high && root->val >= low)
        {
          res += root->val;
        }
        if (root->val > low)
        {
          dfs(root->left, low, high);
        }
        if (root->val < high)
        {
          dfs(root->right, low, high);
        }
      };
    dfs(root, low, high);
    return res;
  }
};
}

// 993. 二叉树的堂兄弟节点 (简单)
namespace n993
{
//在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k + 1 处。
//
//如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
//
//我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
//
//只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
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
  bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
      size_t size = q.size();
      bool xExist = false;
      bool yExist = false;
      for (size_t i = 0; i < size; ++i)
      {
        TreeNode* node = q.front();
        q.pop();
        if (node->val == x)
        {
          xExist = true;
        }
        if (node->val == y)
        {
          yExist = true;
        }
        if (node->left != nullptr && node->right != nullptr)
        {
          if ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))
          {
            return false;
          }
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
      if (xExist && yExist)
      {
        return true;
      }
      if (xExist || yExist)
      {
        return false;
      }
    }
    return false;
  }
};
}

// 1261. 在受污染的二叉树中查找元素 (中等)
namespace n1261
{
//给出一个满足下述规则的二叉树：
//
//root.val == 0
//如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
//如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
//现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 - 1。
//
//请你先还原二叉树，然后实现 FindElements 类：
//
//FindElements(TreeNode * root) 用受污染的二叉树初始化对象，你需要先把它还原。
//bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class FindElements {
public:
  FindElements(TreeNode* root) {
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int val)
      {
        if (nullptr == node)
        {
          return;
        }
        node->val = val;
        s.insert(val);
        dfs(node->left, 2 * val + 1);
        dfs(node->right, 2 * val + 2);
      };
    dfs(root, 0);
  }

  bool find(int target) {
    return s.find(target) != s.end();
  }
  unordered_set<int> s;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
}

// 2581. 统计可能的树根数目 (困难)
namespace n2581
{
//Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。
//
//Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：
//
//选择两个 不相等 的整数 u 和 v ，且树中必须存在边[u, v] 。
//Bob 猜测树中 u 是 v 的 父节点 。
//Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。
//
//Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。
//
//给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。
class Solution {
public:
  int rootCount([[maybe_unused]] vector<vector<int>>& edges, [[maybe_unused]] vector<vector<int>>& guesses, [[maybe_unused]] int k) {
  }
};
}

// 2641. 二叉树的堂兄弟节点 II (中等)
namespace n2641
{
//给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。
//
//如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。
//
//请你返回修改值之后，树的根 root 。
//
//注意，一个节点的深度指的是从树根节点到这个节点经过的边数。
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
  TreeNode* replaceValueInTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int sum = -root->val;
    while (!q.empty())
    {
      size_t size = q.size();
      int sum_tmp = 0;
      for (size_t i = 0; i < size; ++i)
      {
        TreeNode* node = q.front();
        q.pop();
        node->val += sum;
        int leftVal = 0;
        if (nullptr != node->left)
        {
          sum_tmp += node->left->val;
          leftVal = node->left->val;
          node->left->val = -node->left->val;
          if (nullptr != node->right)
          {
            node->left->val -= node->right->val;
          }
          q.push(node->left);
        }
        if (nullptr != node->right)
        {
          sum_tmp += node->right->val;
          node->right->val = -node->right->val;
          if (nullptr != node->left)
          {
            node->right->val -= leftVal;
          }
          q.push(node->right);
        }
      }
      sum = sum_tmp;
    }
    return root;
  }
};
}

// 2673. 使二叉树所有路径值相等的最小代价 (中等)
namespace n2673
{
//给你一个整数 n 表示一棵 满二叉树 里面节点的数目，节点编号从 1 到 n 。根节点编号为 1 ，树中每个非叶子节点 i 都有两个孩子，分别是左孩子 2 * i 和右孩子 2 * i + 1 。
//
//树中每个节点都有一个值，用下标从 0 开始、长度为 n 的整数数组 cost 表示，其中 cost[i] 是第 i + 1 个节点的值。每次操作，你可以将树中 任意 节点的值 增加 1 。你可以执行操作 任意 次。
//
//你的目标是让根到每一个 叶子结点 的路径值相等。请你返回 最少 需要执行增加操作多少次。
//
//注意：
//
//满二叉树 指的是一棵树，它满足树中除了叶子节点外每个节点都恰好有 2 个子节点，且所有叶子节点距离根节点距离相同。
//路径值 指的是路径上所有节点的值之和。
class Solution {
public:
  //我们首先考虑所有的叶结点。

  //  对于任一叶结点，它的值为 xxx，它的兄弟节点的值为 yyy。可以发现，对于树上的其余节点，它们要么同时是这两个叶节点的祖先，要么同时不是这两个叶节点的祖先。对这些节点进行一次操作，要么同时增加了根到这两个叶节点的路径值 111，要么没有任何效果。因此，要想使得根到这两个叶节点的路径值相等，我们只能增加 xxx 和 yyy 本身。

  //  待考虑完所有叶节点之后，互为兄弟节点的叶节点的值两两相等（并且根到它们的路径值显然也相等）。如果我们还需要操作某个叶节点，那么为了使得路径值相等，它的兄弟节点同样也需要操作。此时就需要两次操作，但不如直接操作它们的双亲节点，可以省去一次操作。

  //  因此，所有的叶节点都无需进行操作。我们就可以将它们全部移除。为了使得路径值保持不变，我们可以将叶节点的值增加至它们的双亲节点。这样一来，所有的双亲节点都变成了新的叶节点，我们重复进行上述操作即可。当只剩一个节点（根节点）时，就可以得到最终的答案。
  int minIncrements(int n, vector<int>& cost) {
    int ans = 0;
    for (int i = n - 2; i > 0; i -= 2)
    {
      ans += abs(cost[i] - cost[i + 1]);
      // 叶节点 i 和 i+1 的双亲节点下标为 i/2（整数除法）
      cost[i / 2] += max(cost[i], cost[i + 1]);
    }
    return ans;
  }
};
}