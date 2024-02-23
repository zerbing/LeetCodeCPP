#pragma once

// 31. 下一个排列 (中等)
namespace n31
{
//整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
//
//例如，arr = [1, 2, 3] ，以下这些都可以视作 arr 的排列：[1, 2, 3]、[1, 3, 2]、[3, 1, 2]、[2, 3, 1] 。
//整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
//
//例如，arr = [1, 2, 3] 的下一个排列是[1, 3, 2] 。
//类似地，arr = [2, 3, 1] 的下一个排列是[3, 1, 2] 。
//而 arr = [3, 2, 1] 的下一个排列是[1, 2, 3] ，因为[3, 2, 1] 不存在一个字典序更大的排列。
//给你一个整数数组 nums ，找出 nums 的下一个排列。
//
//必须 原地 修改，只允许使用额外常数空间。
// 我的解法稍复杂，o(n^2)
class Solution1 {
public:
  void nextPermutation(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
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
// 更优，o(n)
class Solution2 {
public:
  void nextPermutation(vector<int>& nums) {
    int i = static_cast<int>(nums.size()) - 2;
    // 从后往前找到第一个递增的数
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }
    if (i >= 0) {
      int j = static_cast<int>(nums.size()) - 1;
      while (j >= 0 && nums[i] >= nums[j]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
}

// 33. 搜索旋转排序数组 (中等)
namespace n33
{
//整数数组 nums 按升序排列，数组中的值 互不相同 。
//
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。例如，[0, 1, 2, 4, 5, 6, 7] 在下标 3 处经旋转后可能变为[4, 5, 6, 7, 0, 1, 2] 。
//
//  给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 - 1 。
//
//  你必须设计一个时间复杂度为 O(log n) 的算法解决此问题
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());
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

// 34. 在排序数组中查找元素的第一个和最后一个位置 (中等)
namespace n34
{
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
class Solution1 {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target)
    {
      return res;
    }
    res[0] = static_cast<int>(it - nums.begin());
    it = upper_bound(nums.begin(), nums.end(), target);
    res[1] = static_cast<int>(it - nums.begin() - 1);
    return res;
  }
};

class Solution2 {
public:
  int leftBound(vector<int>& nums, int target) {
    int left = 0, right = static_cast<int>(nums.size());
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
    int left = 0, right = static_cast<int>(nums.size());
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

// 35. 搜索插入位置 (简单)
namespace n35
{
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = static_cast<int>(nums.size());
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

// 36. 有效的数独 (中等)
namespace n36
{
//请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//
//
//注意：
//
//一个有效的数独（部分已被填充）不一定是可解的。
//只需要根据以上规则，验证已经填入的数字是否有效即可。
//空白格用 '.' 表示。
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> row(9, vector<int>(9, 0));
    vector<vector<int>> col(9, vector<int>(9, 0));
    vector<vector<int>> box(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] != '.')
        {
          int num = board[i][j] - '0' - 1;
          int boxIndex = (i / 3) * 3 + j / 3;
          if (row[i][num] || col[j][num] || box[boxIndex][num])
          {
            return false;
          }
          row[i][num] = 1;
          col[j][num] = 1;
          box[boxIndex][num] = 1;
        }
      }
    }
    return true;
  }
};
}

// 54. 螺旋矩阵 (中等)
namespace n54
{
// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;
    while (left <= right && top <= bottom)
    {
      for (int i = left; i <= right; ++i)
      {
        res.push_back(matrix[top][i]);
      }
      for (int i = top + 1; i <= bottom; ++i)
      {
        res.push_back(matrix[i][right]);
      }
      if (left < right && top < bottom)
      {
        for (int i = right - 1; i >= left; --i)
        {
          res.push_back(matrix[bottom][i]);
        }
        for (int i = bottom - 1; i > top; --i)
        {
          res.push_back(matrix[i][left]);
        }
      }
      left++;
      right--;
      top++;
      bottom--;
    }
    return res;
  }
};
}

// 56. 合并区间 (中等)
namespace n56
{
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int right = intervals[0][1];
    int left = intervals[0][0];
    for (int i = 1; i < intervals.size(); ++i)
    {
      if (intervals[i][0] <= right)
      {
        right = max(right, intervals[i][1]);
      }
      else
      {
        res.push_back({ left, right });
        left = intervals[i][0];
        right = intervals[i][1];
      }
    }
    res.push_back({ left, right });
    return res;
  }
};
}

// 57. 插入区间 (中等)
namespace n57
{
//给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
//
//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int n = static_cast<int>(intervals.size());
    bool insert = false;
    for (int i = 0; i < n; ++i)
    {
      if (intervals[i][1] < newInterval[0])
      {
        res.push_back(intervals[i]);
      }
      else if (intervals[i][0] > newInterval[1])
      {
        if (!insert)
        {
          res.push_back(newInterval);
          insert = true;
        }
        res.push_back(intervals[i]);
      }
      else
      {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
      }
    }
    if (!insert)
    {
      res.push_back(newInterval);
    }
    return res;
  }
};
}

// 283. 移动零 (简单)
namespace n283
{
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
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

// 447. 回旋镖的数量 (中等)
namespace n447
{
//给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点(i, j, k) 表示的元组 ，其中 i 和 j 之间的欧式距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。
//
//返回平面上所有回旋镖的数量
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

// 2706. 购买两块巧克力 (简单)
namespace n2706
{
//给你一个整数数组 prices ，它表示一个商店里若干巧克力的价格。同时给你一个整数 money ，表示你一开始拥有的钱数。
//
//你必须购买 恰好 两块巧克力，而且剩余的钱数必须是 非负数 。同时你想最小化购买两块巧克力的总花费。
//
//请你返回在购买两块巧克力后，最多能剩下多少钱。如果购买任意两块巧克力都超过了你拥有的钱，请你返回 money 。注意剩余钱数必须是非负数。
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

// 2562. 找出数组的串联值 (简单）
namespace n2562
{
//给你一个下标从 0 开始的整数数组 nums 。
//
//现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。
//
//例如，15 和 49 的串联是 1549 。
//nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空：
//
//如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 中删除第一个和最后一个元素。
//如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。
//返回执行完所有操作后 nums 的串联值。
class Solution {
public:
  long long findTheArrayConcVal(vector<int>& nums) {
    int i = 0;
    int j = static_cast<int>(nums.size()) - 1;
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

// 2765. 最长交替子数组 (中等)
namespace n2765
{
//给你一个下标从 0 开始的整数数组 nums 。如果 nums 中长度为 m 的子数组 s 满足以下条件，我们称它是一个 交替子数组 ：
//
//m 大于 1 。
//s1 = s0 + 1 。
//下标从 0 开始的子数组 s 与数组[s0, s1, s0, s1, ..., s(m - 1) % 2] 一样。也就是说，s1 - s0 = 1 ，s2 - s1 = -1 ，s3 - s2 = 1 ，s4 - s3 = -1 ，以此类推，直到 s[m - 1] - s[m - 2] = (-1)m 。
//请你返回 nums 中所有 交替 子数组中，最长的长度，如果不存在交替子数组，请你返回 - 1 。
//
//子数组是一个数组中一段连续 非空 的元素序列。
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