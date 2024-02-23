#pragma once

// 19. ɾ������ĵ����� N ����� (�е�)
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
    // ɾ��������n���ڵ�
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

// 21. �ϲ������������� (��)
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

// 24. �������������еĽڵ� (�е�)
namespace n24
{
// ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
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

// 25. K ��һ�鷭ת���� (����)
namespace n25
{
//���������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������
//
//k ��һ��������������ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
//
//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
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

// 61. ��ת����
namespace n61
{
// ����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0)
    {
      return head;
    }
    int n = 1;
    ListNode* cur = head;
    while (cur->next != nullptr)
    {
      cur = cur->next;
      n++;
    }
    k = k % n;
    if (k == 0)
    {
      return head;
    }
    cur->next = head;
    cur = head;
    for (int i = 0; i < n - k - 1; i++)
    {
      cur = cur->next;
    }
    ListNode* newHead = cur->next;
    cur->next = nullptr;
    return newHead;
  }
};
}

// 86. �ָ����� (�е�)
namespace n86
{
//����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
//
//��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* large = new ListNode(0);
    ListNode* smallCur = small;
    ListNode* largeCur = large;
    while (head != nullptr)
    {
      if (head->val < x)
      {
        smallCur->next = head;
        smallCur = smallCur->next;
      }
      else
      {
        largeCur->next = head;
        largeCur = largeCur->next;
      }
      head = head->next;
    }
    largeCur->next = nullptr;
    smallCur->next = large->next;
    ListNode* res = small->next;
    delete small;
    delete large;
    return res;
  }
};
}

// LCR 077. �������� (�е�)
namespace lcr077
{
// ���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��
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