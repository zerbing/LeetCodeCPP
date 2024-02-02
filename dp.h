#pragma once

// 32. ���Ч����
namespace N32
{
// ����һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
class Solution {
public:
  int longestValidParentheses(string s) {
    int n = static_cast<int>(s.size());
    // dp[i] ��ʾ�� s[i] **��β**�����Ч���ŵĳ���
    // ע��dp[n-1]���������ս����dp[i]�����ֵ�������ս��
    vector<int> dp(n, 0);
    int maxLen = 0;
    for (int i = 1; i < n; ++i)
    {
      if (s[i] == ')')
      {
        if (s[i - 1] == '(')
        {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        }
        else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
        {
          dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxLen = max(maxLen, dp[i]);
      }
    }
    return maxLen;
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