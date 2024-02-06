#pragma once

// 18. ����֮�� (�е�)
namespace n18
{
//����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����Ԫ��[nums[a], nums[b], nums[c], nums[d]] ����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
//
//0 <= a, b, c, d < n
//  a��b��c �� d ������ͬ
//  nums[a] + nums[b] + nums[c] + nums[d] == target
//  ����԰� ����˳�� ���ش� ��
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4)
    {
      return res;
    }
    sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n - 3; ++i)
    {
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }
      for (int j = i + 1; j < n - 2; ++j)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
        {
          continue;
        }
        int left = j + 1;
        int right = n - 1;
        while (left < right)
        {
          long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
          if (sum == target)
          {
            res.push_back({ nums[i], nums[j], nums[left], nums[right] });
            while (left < right && nums[left] == nums[left + 1])
            {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1])
            {
              right--;
            }
            left++;
            right--;
          }
          else if (sum < target)
          {
            left++;
          }
          else
          {
            right--;
          }
        }
      }
    }
    return res;
  }
};
}