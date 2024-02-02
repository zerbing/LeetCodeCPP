#pragma once

// 97. �����ַ��� (�е�)
namespace N97
{
//���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ���� ��ɵġ�
//
//�����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ� ���ַ�����
//
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//| n - m| <= 1
//���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
//ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
    {
      return false;
    }
    map<pair<int, int>, bool> memo;
    function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
      if (memo.count({ i, j }))
      {
        return memo[{i, j}];
      }
      if (k == s3.size())
      {
        return true;
      }
      if (i < s1.size() && s1[i] == s3[k] && dfs(i + 1, j, k + 1))
      {
        return true;
      }
      if (j < s2.size() && s2[j] == s3[k] && dfs(i, j + 1, k + 1))
      {
        return true;
      }
      memo[{i, j}] = false;
      return false;
      };
    return dfs(0, 0, 0);
  }
};
}