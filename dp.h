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
    return false;
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

// 152. �˻���������� (�е�)
namespace N152
{
//����һ���������� nums �������ҳ������г˻����ķǿ����������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
//
//���������Ĵ���һ�� 32 - λ ������
//
//������ ����������������С�
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    // dp[i].first��ʾ��nums[i]��β�����˻���dp[i].second��ʾ��nums[i]��β����С�˻�
    vector<pair<int, int>> dp(nums.size(), {INT_MIN, INT_MAX});
    dp[0] = {nums[0], nums[0]};
    int maxProduct = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      dp[i].first = max({dp[i - 1].first * nums[i], dp[i - 1].second * nums[i], nums[i]});
      dp[i].second = min({dp[i - 1].first * nums[i], dp[i - 1].second * nums[i], nums[i]});
      maxProduct = max(maxProduct, dp[i].first);
    }
    return maxProduct;
  }
};
}

// 174. ���³���Ϸ (����)
namespace N174
{
//��ħ��ץס�˹��������������˵��³� dungeon �� ���½� �����³����� m x n ��������ɵĶ�ά��������Ӣ�µ���ʿ����������� ���Ͻ� �ķ���������봩�����³ǲ�ͨ���Կ���ħ�����ȹ�����
//
//��ʿ�ĳ�ʼ��������Ϊһ����������������Ľ���������ĳһʱ�̽��� 0 �����£���������������
//
//��Щ�����ɶ�ħ�����������ʿ�ڽ�����Щ����ʱ��ʧȥ�������������������ֵΪ�����������ʾ��ʿ����ʧ��������������������Ҫô�ǿյģ��������ֵΪ 0����Ҫô����������ʿ����������ħ�������������ֵΪ�����������ʾ��ʿ�����ӽ�����������
//
//Ϊ�˾����ȹ�������ʿ����ÿ��ֻ ���� �� ���� �ƶ�һ����
//
//����ȷ����ʿ�ܹ����ȵ������������ͳ�ʼ����������
//
//ע�⣺�κη��䶼���ܶ���ʿ�Ľ������������в��Ҳ����������ʿ�Ľ���������������ʿ��������ϽǷ����Լ���������������½Ƿ��䡣
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    // dp[i][j]��ʾ����dungeon[i][j]ʱ����С��ʼ��������
    vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
    // ������ʿ����ʱ�̵Ľ�������������С��1��������Ҫ����dp
    dp[dungeon.size()][dungeon[0].size() - 1] = 1;
    dp[dungeon.size() - 1][dungeon[0].size()] = 1;
    for (size_t i = dungeon.size() - 1; i >= 0; --i)
    {
      for (size_t j = dungeon[0].size() - 1; j >= 0; --j)
      {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};
}

// 198. ��ҽ��� (�е�)
namespace N198
{
//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
class Solution {
public:
  int rob(vector<int>& nums) {
    // dp[i].first��ʾ͵�Ե���i������ʱ������dp[i].second��ʾ��͵�Ե�i������ʱ�������
    vector<pair<int, int>> dp(nums.size() + 1, {0, 0});
    for (int i = 1; i <= nums.size(); ++i)
    {
      dp[i].first = dp[i - 1].second + nums[i - 1];
      dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    return max(dp[nums.size()].first, dp[nums.size()].second);
  }
};
}

// 213. ��ҽ��� II (�е�)
namespace N213
{
//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1)
    {
      return nums[0];
    }
    int res = 0;
    // dp[i].first��ʾ͵�Ե���i������ʱ������dp[i].second��ʾ��͵�Ե�i������ʱ�������
    vector<pair<int, int>> dp(nums.size(), { 0, 0 });
    // ��͵�Ե�һ������
    for (int i = 1; i < nums.size(); ++i)
    {
      if (1 == i)
      {
        dp[i].first = nums[i];
        dp[i].second = 0;
      }
      else
      {
        dp[i].first = dp[i - 1].second + nums[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
      }
    }
    res = max(dp[nums.size() - 1].first, dp[nums.size() - 1].second);
    // ͵�Ե�һ������
    vector<pair<int, int>> dp2(nums.size(), { 0, 0 });
    for (int i = 0; i < nums.size() - 1; ++i)
    {
      if (0 == i)
      {
        dp2[i].first = nums[i];
        dp2[i].second = 0;
      }
      else
      {
        dp2[i].first = dp2[i - 1].second + nums[i];
        dp2[i].second = max(dp2[i - 1].first, dp2[i - 1].second);
      }
    }
    res = max(res, max(dp2[nums.size() - 2].first, dp2[nums.size() - 2].second));
    return res;
  }
};
}

// 221. ��������� (�е�)
namespace N221
{
//��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxSide = 0;
    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (matrix[i - 1][j - 1] == '1')
        {
          dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }
    return maxSide * maxSide;
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