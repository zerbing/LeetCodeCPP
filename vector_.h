#pragma once

// 31. ��һ������
namespace n31
{
//���������һ�� ����  ���ǽ������г�Ա�����л�����˳�����С�
//
//���磬arr = [1, 2, 3] ��������Щ���������� arr �����У�[1, 2, 3]��[1, 3, 2]��[3, 1, 2]��[2, 3, 1] ��
//��������� ��һ������ ��ָ����������һ���ֵ����������С�����ʽ�أ����������������и������ֵ�˳���С����������һ�������У���ô����� ��һ������ �������������������������������Ǹ����С������������һ����������У���ô��������������Ϊ�ֵ�����С�����У�������Ԫ�ذ��������У���
//
//���磬arr = [1, 2, 3] ����һ��������[1, 3, 2] ��
//���Ƶأ�arr = [2, 3, 1] ����һ��������[3, 1, 2] ��
//�� arr = [3, 2, 1] ����һ��������[1, 2, 3] ����Ϊ[3, 2, 1] ������һ���ֵ����������С�
//����һ���������� nums ���ҳ� nums ����һ�����С�
//
//���� ԭ�� �޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣
// �ҵĽⷨ�Ը��ӣ�o(n^2)
class Solution1 {
public:
  void nextPermutation(vector<int>& nums) {
    size_t n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
      int tmpNum = INT_MAX;
      int tmpIndex = -1;
      for (int j = i + 1; j < n; j++)
      {
        if (nums[j] > nums[i] && nums[j] < tmpNum)
        {
          tmpNum = nums[j];
          tmpIndex = j;
        }
      }
      if (tmpIndex != -1)
      {
        swap(nums[tmpIndex], nums[i]);
        sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    sort(nums.begin(), nums.end());
  }
};
// ���ţ�o(n)
class Solution2 {
public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    // �Ӻ���ǰ�ҵ���һ����������
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }
    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[i] >= nums[j]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
}

// 33. ������ת��������
namespace n33
{
//�������� nums ���������У������е�ֵ ������ͬ ��
//
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ �����������磬[0, 1, 2, 4, 5, 6, 7] ���±� 3 ������ת����ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2] ��
//
//  ���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� - 1 ��
//
//  ��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨���������
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0)
    {
      return -1;
    }
    if (n == 1)
    {
      return nums[0] == target ? 0 : -1;
    }
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[0] <= nums[mid])
      {
        if (nums[l] <= target && target < nums[mid])
        {
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
      else
      {
        if (nums[mid] < target && target <= nums[r])
        {
          l = mid + 1;
        }
        else
        {
          r = mid - 1;
        }
      }
    }
    return -1;
  }
};
}

// 34. �����������в���Ԫ�صĵ�һ�������һ��λ�� (�е�)
namespace n34
{
//����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//
//��������в�����Ŀ��ֵ target������[-1, -1]��
//
//�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
class Solution1 {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target)
    {
      return res;
    }
    res[0] = it - nums.begin();
    it = upper_bound(nums.begin(), nums.end(), target);
    res[1] = it - nums.begin() - 1;
    return res;
  }
};

class Solution2 {
public:
  int leftBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        right = mid;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid;
      }
    }
    if (left < 0 || left >= nums.size())
    {
      return -1;
    }
    return nums[left] == target ? left : -1;
  }
  int rightBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        left = mid + 1;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid;
      }
    }
    if (left - 1 < 0 || left - 1 >= nums.size())
    {
      return -1;
    }
    return nums[left - 1] == target ? left - 1 : -1;
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    res[0] = leftBound(nums, target);
    res[1] = rightBound(nums, target);
    return res;
  }
};
}

// 35. ��������λ�� (��)
namespace n35
{
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        right = mid;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid;
      }
    }
    return left;
  }
};
}

// 283. �ƶ���
namespace n283
{
//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//
//��ע�� �������ڲ���������������ԭ�ض�������в�����
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    while (right < n)
    {
      if (nums[right] != 0)
      {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};
}

// 447. �����ڵ����� (�е�)
namespace n447
{
//����ƽ���� n �� ������ͬ �ĵ� points ������ points[i] = [xi, yi] �������� ���ɵ�(i, j, k) ��ʾ��Ԫ�� ������ i �� j ֮���ŷʽ����� i �� k ֮���ŷʽ������ȣ���Ҫ����Ԫ���˳�򣩡�
//
//����ƽ�������л����ڵ�����
class Solution {
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    vector<vector<int>> dis(points.size(), vector<int>(points.size(), 0));
    for (int i = 0; i < points.size(); ++i)
    {
      for (int j = i + 1; j < points.size(); ++j)
      {
        int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
          (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        dis[i][j] = distance;
        dis[j][i] = distance;
      }
    }

    for (int i = 0; i < points.size(); ++i)
    {
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); ++j)
      {
        if (i != j)
        {
          m[dis[i][j]]++;
        }
      }
      for (auto it = m.begin(); it != m.end(); ++it)
      {
        if (it->second >= 2)
        {
          res += it->second * (it->second - 1);
        }
      }
    }
    return res;
  }
};
}

// 2706. ���������ɿ��� (��)
namespace n2706
{
//����һ���������� prices ������ʾһ���̵��������ɿ����ļ۸�ͬʱ����һ������ money ����ʾ��һ��ʼӵ�е�Ǯ����
//
//����빺�� ǡ�� �����ɿ���������ʣ���Ǯ�������� �Ǹ��� ��ͬʱ������С�����������ɿ������ܻ��ѡ�
//
//���㷵���ڹ��������ɿ����������ʣ�¶���Ǯ������������������ɿ�������������ӵ�е�Ǯ�����㷵�� money ��ע��ʣ��Ǯ�������ǷǸ�����
class Solution {
public:
  int buyChoco(vector<int>& prices, int money) {
    sort(prices.begin(), prices.end());
    if (prices[0] + prices[1] > money) {
      return money;
    }
    return money - prices[0] - prices[1];
  }
};
}

// 2562. �ҳ�����Ĵ���ֵ (�򵥣�
namespace n2562
{
//����һ���±�� 0 ��ʼ���������� nums ��
//
//�ֶ����������ֵ� ���� ������������ֵ���������γɵ������֡�
//
//���磬15 �� 49 �Ĵ����� 1549 ��
//nums �� ����ֵ ������� 0 ��ִ����������ֱ�� nums ��Ϊ�գ�
//
//��� nums �д��ڲ�ֹһ�����֣��ֱ�ѡ�� nums �еĵ�һ��Ԫ�غ����һ��Ԫ�أ������ߴ����õ���ֵ�ӵ� nums �� ����ֵ �ϣ�Ȼ��� nums ��ɾ����һ�������һ��Ԫ�ء�
//���������һ��Ԫ�أ��򽫸�Ԫ�ص�ֵ�ӵ� nums �Ĵ���ֵ�ϣ�Ȼ��ɾ�����Ԫ�ء�
//����ִ�������в����� nums �Ĵ���ֵ��
class Solution {
public:
  long long findTheArrayConcVal(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;
    long long res = 0;
    while (i < j)
    {
      res += stoi(to_string(nums[i]) + to_string(nums[j]));
      i++;
      j--;
    }
    if (i == j)
    {
      res += nums[i];
    }
    return res;
  }
};
}

// 2765. ����������� (�е�)
namespace n2765
{
//����һ���±�� 0 ��ʼ���������� nums ����� nums �г���Ϊ m �������� s �����������������ǳ�����һ�� ���������� ��
//
//m ���� 1 ��
//s1 = s0 + 1 ��
//�±�� 0 ��ʼ�������� s ������[s0, s1, s0, s1, ..., s(m - 1) % 2] һ����Ҳ����˵��s1 - s0 = 1 ��s2 - s1 = -1 ��s3 - s2 = 1 ��s4 - s3 = -1 ���Դ����ƣ�ֱ�� s[m - 1] - s[m - 2] = (-1)m ��
//���㷵�� nums ������ ���� �������У���ĳ��ȣ���������ڽ��������飬���㷵�� - 1 ��
//
//��������һ��������һ������ �ǿ� ��Ԫ�����С�
class Solution {
public:
  int alternatingSubarray(vector<int>& nums) {
    int res = -1;
    int cur = 1;
    int flag = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
      if ((nums[i] - nums[i - 1]) * flag == 1)
      {
        flag *= -1;
        cur += 1;
        res = max(res, cur);
      }
      else if (nums[i] - nums[i - 1] == 1)
      {
        cur = 2;
        flag = -1;
      }
      else
      {
        cur = 1;
        flag = 1;
      }
    }
    return res;
  }
};
}