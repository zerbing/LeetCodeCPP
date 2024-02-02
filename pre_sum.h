#pragma once

// 410. �ָ���������ֵ (����)
namespace N410
{
//����һ���Ǹ��������� nums ��һ������ k ������Ҫ���������ֳ� k ���ǿյ����������顣
//
//���һ���㷨ʹ���� k ����������Ժ͵����ֵ��С��
class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    vector<int> preSum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    vector<vector<int>> dp(k, vector<int>(nums.size() + 1, 0));
    dp[0] = preSum;
    for (int i = 1; i < k; ++i)
    {
      for (int j = i; j <= nums.size(); j++)
      {
        int tmp = INT_MAX;
        for (int a = j - 1; a >= i - 1; --a)
        {
          // ͨ��ǰ׺�ͼ�����������Ĵ�С
          int sum = preSum[j] - preSum[a];
          tmp = min(tmp, max(sum, dp[i - 1][a]));
          // ����sum��i�ݼ���dp[i-1][a]��i���������������󼴿��˳�ѭ��
          if (sum >= dp[i - 1][a])
          {
            break;
          }
        }
        dp[i][j] = tmp;
      }
    }
    return dp[k - 1][nums.size()];
  }
};
}

// 2171. �ó�������Ŀ��ħ���� (����)
namespace N2171
{
//����һ�� ������ ���� beans ������ÿ��������ʾһ��������װ��ħ��������Ŀ��
//
//�����ÿ�������� �ó� һЩ���ӣ�Ҳ���� ���ó�����ʹ��ʣ�µ� �ǿ� �����У��� ���ٻ���һ�� ħ�����Ĵ��ӣ�ħ��������Ŀ ��ȡ�һ����ħ�����Ӵ�����ȡ�����㲻���ٽ����ŵ��κδ����С�
//
//�뷵������Ҫ�ó�ħ������ ������Ŀ��
class Solution {
public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    // ǰ׺��
    vector<long long> preSum(beans.size() + 1, 0);
    for (int i = 1; i <= beans.size(); ++i)
    {
      preSum[i] = preSum[i - 1] + beans[i - 1];
    }
    long long res = INT64_MAX;
    for (int i = 0; i < beans.size(); ++i)
    {
      // ǰi-1�������е�ħ������Ŀ
      long long sum = preSum[i];
      // ��n-i-1�������е�ħ������Ŀ
      sum += preSum[beans.size()] - preSum[i] - beans[i] * (beans.size() - i);
      res = min(res, sum);
    }
    return res;
  }
};
}