#pragma once

// 32. ���Ч���� (����)
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

// 45. ��Ծ��Ϸ II (�е�)
namespace N45
{
//����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��
//
//ÿ��Ԫ�� nums[i] ��ʾ������ i ��ǰ��ת����󳤶ȡ����仰˵��������� nums[i] �����������ת������ nums[i + j] ��:
//
//0 <= j <= nums[i]
//i + j < n
//  ���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]��
class Solution {
public:
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
      {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[nums.size() - 1];
  }
};
}

// 55. ��Ծ��Ϸ (�е�)
namespace N55
{
//����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//
//�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false ��
class Solution {
public:
  bool canJump(vector<int>& nums) {
    // dp[i]��ʾ����iλ��ʱʣ��������
    vector<int> dp(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i)
    {
      // Ҫôʹ����һ����ʣ�ಽ����Ҫôʹ�õ�ǰλ�õĲ���
      dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
      if (dp[i] < 0)
      {
        return false;
      }
    }
    return true;
  }
};
}

// 64. ��С·���� (�е�)
namespace N64
{
//����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//
//˵����ÿ��ֻ�����»��������ƶ�һ����
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= grid.size(); ++i)
    {
      for (int j = 1; j <= grid[0].size(); ++j)
      {
        if (i == 1 && j == 1)
        {
          continue;
        }
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return dp[grid.size()][grid[0].size()];
  }
};
}

// 87. �����ַ��� (����) // todo
namespace N87
{
//ʹ�������������㷨���������ַ��� s �õ��ַ��� t ��
//����ַ����ĳ���Ϊ 1 ���㷨ֹͣ
//����ַ����ĳ��� > 1 ��ִ���������裺
//��һ������±괦���ַ����ָ�������ǿյ����ַ��������������֪�ַ��� s ������Խ���ֳ��������ַ��� x �� y �������� s = x + y ��
//��� ������Ҫ�������������ַ���������Ҫ���������������ַ�����˳�򲻱䡹��������ִ����һ����֮��s ������ s = x + y ���� s = y + x ��
//�� x �� y ���������ַ����ϼ����Ӳ��� 1 ��ʼ�ݹ�ִ�д��㷨��
//�������� ������� ���ַ��� s1 �� s2���ж� s2 �Ƿ��� s1 �������ַ���������ǣ����� true �����򣬷��� false ��
class Solution {
public:
  bool isScramble([[maybe_unused]] string s1, [[maybe_unused]] string s2) {

  }
};
}

// 91. ���뷽�� (�е�)
namespace N91
{
//һ��������ĸ A - Z ����Ϣͨ������ӳ������� ���� ��
//
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//Ҫ ���� �ѱ������Ϣ���������ֱ����������ӳ��ķ���������ӳ�����ĸ�������ж��ַ����������磬"11106" ����ӳ��Ϊ��
//
//"AAJF" ������Ϣ����Ϊ(1 1 10 6)
//"KJF" ������Ϣ����Ϊ(11 10 6)
//ע�⣬��Ϣ���ܷ���Ϊ(1 11 06) ����Ϊ "06" ����ӳ��Ϊ "F" ���������� "6" �� "06" ��ӳ���в����ȼۡ�
//
//����һ��ֻ�����ֵ� �ǿ� �ַ��� s ������㲢���� ���� ������ ���� ��
//
//��Ŀ���ݱ�֤�𰸿϶���һ�� 32 λ ��������
class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
    {
      return 0;
    }
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i] == '0')
      {
        if (s[i - 1] != '1' && s[i - 1] != '2')
        {
          return 0;
        }
        dp[i + 1] = dp[i - 1];
      }
      else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
      {
        dp[i + 1] = dp[i] + dp[i - 1];
      }
      else
      {
        dp[i + 1] = dp[i];
      }
    }
    return dp[s.size()];
  }
};
}

// 118. ������� (��)
namespace N118
{
//����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
//
//�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i)
    {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j)
      {
        row[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res.push_back(row);
    }
    return res;
  }
};
}

// 119. ������� II (��)
namespace N119
{
//����һ���Ǹ����� rowIndex�����ء�������ǡ��ĵ� rowIndex �С�
//
//�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex; ++i)
    {
      for (int j = i - 1; j > 0; --j)
      {
        res[j] += res[j - 1];
      }
    }
    return res;
  }
};
}

// 139. ���ʲ�� (�е�)
namespace N139
{
//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣������������ֵ��г��ֵ�һ����������ƴ�ӳ� s �򷵻� true��
//
//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i)
    {
      for (const string& word : wordDict)
      {
        int len = static_cast<int>(word.size());
        if (i >= len && s.substr(i - len, len) == word)
        {
          dp[i] = dp[i - len];
          if (dp[i])
          {
            break;
          }
        }
      }
    }
    return dp[s.size()];
  }
};
}

// 140. ���ʲ�� II (����)
namespace N140
{
//����һ���ַ��� s ��һ���ַ����ֵ� wordDict �����ַ��� s �����ӿո�������һ�����ӣ�ʹ�þ��������еĵ��ʶ��ڴʵ��С�������˳�� ����������Щ���ܵľ��ӡ�
//
//ע�⣺�ʵ��е�ͬһ�����ʿ����ڷֶ��б��ظ�ʹ�ö�Ρ�
class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> res;
    function<void(vector<int>&)> dfs = [&](vector<int>& seprators) {
        if (seprators.back() == s.size())
        {
          string sentence;
          for (int i = 1; i < seprators.size(); ++i)
          {
            sentence += s.substr(seprators[i - 1], seprators[i] - seprators[i - 1]) + " ";
          }
          sentence.pop_back();
          res.push_back(sentence);
          return;
        }
        else
        {
          for (const string& word : wordDict)
          {
            int len = static_cast<int>(word.size());
            if (s.substr(seprators.back(), len) == word)
            {
              seprators.push_back(seprators.back() + len);
              dfs(seprators);
              seprators.pop_back();
            }
          }
        }
      };
    vector<int> seprators = {0};
    dfs(seprators);
    return res;
  }
};
}

// 2645. ������Ч�ַ��������ٲ����� (�е�)
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