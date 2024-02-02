#pragma once

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

// LCR 004. ֻ����һ�ε����� II
namespace LCR004
{
// ����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�
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