#pragma once

// 19. 删除链表的倒数第 N 个结点 (中等)
namespace n19
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
    while (fast != nullptr && fast->next != nullptr && slow != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }
    // 删除倒数第n个节点
    if (slow != nullptr && slow->next != nullptr)
    {
      slow->next = slow->next->next;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// 21. 合并两个有序链表 (简单)
namespace n21
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

// 24. 两两交换链表中的节点 (中等)
namespace n24
{
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    cur->next = head;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
      ListNode* node1 = cur->next;
      ListNode* node2 = cur->next->next;
      cur->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      cur = node1;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
}

// 25. K 个一组翻转链表 (困难)
namespace n25
{
//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* end = dummy;
    while (end->next != nullptr)
    {
      for (int i = 0; i < k && end != nullptr; i++)
      {
        end = end->next;
      }
      if (end == nullptr)
      {
        break;
      }
      ListNode* start = pre->next;
      ListNode* next = end->next;
      end->next = nullptr;
      pre->next = reverse(start);
      start->next = next;
      pre = start;
      end = pre;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
  ListNode* reverse(ListNode* head)
  {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr)
    {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};
}

// LCR 077. 排序链表 (中等)
namespace lcr077
{
// 给定链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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