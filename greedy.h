#pragma once

// 292. Nim ��Ϸ (��)
namespace n292
{
//���������ѣ�������һ���� Nim ��Ϸ��
//
//��������һ��ʯͷ��
//�������������Լ��Ļغϣ� ����Ϊ���� ��
//ÿһ�غϣ��ֵ������õ� 1 - 3 ��ʯͷ��
//�õ����һ��ʯͷ���˾��ǻ�ʤ�ߡ�
//��������ÿһ���������Ž⡣���дһ�����������ж����Ƿ�����ڸ���ʯͷ����Ϊ n �������Ӯ����Ϸ���������Ӯ������ true�����򣬷��� false ��
class Solution {
public:
  bool canWinNim(int n) {
    return n % 4 != 0;
  }
};
}

// 670. ��󽻻� (�е�)
namespace n670
{
// ����һ���Ǹ���������������Խ���һ�������е�������λ���������ܵõ������ֵ��
class Solution {
public:
  int maximumSwap(int num) {
    vector<int> nums;
    while (num)
    {
      nums.push_back(num % 10);
      num /= 10;
    }
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
      int maxIndex = i;
      for (int j = i + 1; j < nums.size(); ++j)
      {
        if (nums[j] >= nums[maxIndex])
        {
          maxIndex = j;
        }
      }
      if (maxIndex != i && nums[maxIndex] != nums[i])
      {
        swap(nums[maxIndex], nums[i]);
        break;
      }
    }
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      res = res * 10 + nums[i];
    }
    return res;
  }
};
}

// 1686. ʯ����Ϸ VI (�е�)
namespace n1686
{
//Alice �� Bob ������һ����Ϸ��Alice ���֡�

//һ��ʯ�����ܹ��� n ��ʯ�ӣ��ֵ�ĳ�����ʱ�������� �Ƴ� һ��ʯ�Ӳ��õ����ʯ�ӵļ�ֵ��Alice �� Bob ��ʯ�Ӽ�ֵ�� ��һ���ĵ����б�׼ ��˫����֪���Է������б�׼��
//
//������������Ϊ n ���������� aliceValues �� bobValues ��aliceValues[i] �� bobValues[i] �ֱ��ʾ Alice �� Bob ��Ϊ�� i ��ʯ�ӵļ�ֵ��
//
//����ʯ�Ӷ���ȡ��󣬵÷ֽϸߵ���Ϊʤ�ߡ����������ҵ÷���ͬ����ôΪƽ�֡���λ��Ҷ������ ���Ų��� ������Ϸ��
//
//�����ƶ���Ϸ�Ľ���������µķ�ʽ��ʾ��
//
//��� Alice Ӯ������ 1 ��
//��� Bob Ӯ������ - 1 ��
//�����Ϸƽ�֣����� 0 ��
class Solution {
public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    size_t n = aliceValues.size();
    pair<long long, long long> score;
    multimap<long long, long long> value;
    for (size_t i = 0; i < n; ++i) {
      value.insert({ aliceValues[i] + bobValues[i], i });
    }
    bool aliceTurn = true;
    for (auto it = value.rbegin(); it != value.rend(); ++it) {
      if (aliceTurn) {
        score.first += aliceValues[it->second];
      }
      else {
        score.second += bobValues[it->second];
      }
      aliceTurn = !aliceTurn;
    }
    if (score.first > score.second) {
      return 1;
    }
    else if (score.first < score.second) {
      return -1;
    }
    else {
      return 0;
    }
  }
};
}

// 1402. ����˳�� (����)
namespace n1402
{
//һ����ʦ�ռ����� n ���˵�����̶� satisfaction �������ʦ����ÿ���˵�ʱ�䶼�� 1 ��λʱ�䡣
//
//һ���˵� �� like - time ϵ�� ������Ϊ�������˽�����ʱ�䣨����֮ǰÿ���������ѵ�ʱ�䣩��������˵�����̶ȣ�Ҳ���� time[i] * satisfaction[i] ��
//
//���س�ʦ��׼����һ�������Ĳ��Ⱥ���Ի�õ���� like - time ϵ�� �ܺ͡�
//
//����԰� ���� ˳�������˵�˳����Ҳ����ѡ�������ĳЩ������ø�����ܺ͡�
class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int sum = accumulate(satisfaction.begin(), satisfaction.end(), 0);
    int res = 0;
    // ���ֵ͵Ĳ�Խ����Խ��
    for (int i = 0; i < satisfaction.size(); ++i)
    {
      res += satisfaction[i] * (i + 1);
    }
    int tmp = res;
    // �𲽷���������͵Ĳ�
    for (int i = 1; i <= satisfaction.size(); ++i)
    {
      tmp -= sum;
      res = max(res, tmp);
      sum -= satisfaction[i - 1];
    }
    return res;
  }
};
}

// LCP 30. ħ����Ϸ (�е�)
namespace lcp30
{
//С�۵�ǰλ��ħ����Ϸ��һ�㣬���� N �����䣬���Ϊ 0 ~N - 1��ÿ������Ĳ�Ѫ���� / �������Ѫ��Ӱ��������� nums������������ʾ���߲�Ѫ��ֵ����Ѫ�����Ӷ�Ӧ��ֵ��������ʾ��������˺�ֵ����Ѫ�����ٶ�Ӧ��ֵ��0 ��ʾ�����Ѫ����Ӱ�졣
//
//С�۳�ʼѪ��Ϊ 1���������ޡ��ٶ�С��ԭ�ƻ�������������������з��䲹Ѫ / ��֣�Ϊ��֤Ѫ��ʼ��Ϊ��ֵ��С����Է������˳����е�����ÿ�ν��ܽ�һ�����﷿�䣨�����ķ��䣩����������˳��ĩβ���뷵��С��������Ҫ�������Σ�����˳���������з��䡣������˳��Ҳ�޷�������ȫ�����䣬�뷵�� - 1��
// �����ڴ�����
class Solution {
public:
  int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 1) < 0)
    {
      return -1;
    }
    size_t n = nums.size();
    // dp[i][j] ��ʾǰ i �����䣬�����Ĵ���Ϊ j ʱ��ʣ���Ѫ��
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));
    dp[0][0] = 1;
    for (size_t i = 1; i <= n; ++i)
    {
      dp[i][0] = dp[i - 1][0] + nums[i - 1];
      if (dp[i][0] <= 0)
      {
        break;
      }
    }
    if (dp[n][0] > 0)
    {
      return 0;
    }
    for (size_t i = 1; i <= n; ++i)
    {
      for (size_t j = 1; j <= i; ++j)
      {
        int num = nums[i - 1];
        if (num > 0 && dp[i - 1][j] > 0)
        {
          dp[i][j] = dp[i - 1][j] + num;
        }
        else
        {
          if (dp[i - 1][j] > 0)
          {
            dp[i][j] = max(0, dp[i - 1][j] + num);
          }
          if (dp[i - 1][j - 1] > 0)
          {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
          }
        }
        if (i == n && dp[i][j] > 0)
        {
          return static_cast<int>(j);
        }
      }
    }
    return -1;
  }
};

class Solution2 {
public:
  int magicTower(vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 1LL) < 0) // ע�������1LL������ʾ�����ͳ���1
    {
      return -1;
    }
    size_t n = nums.size();
    int res = 0;
    long long sum = 1; // ��sum�����͸�Ϊlong long
    priority_queue<int, vector<int>, greater<int>> q;
    for (size_t i = 0; i < n; ++i)
    {
      sum += nums[i];
      if (nums[i] < 0)
      {
        q.push(nums[i]);
      }
      if (sum <= 0)
      {
        sum -= q.top();
        q.pop();
        ++res;
      }
    }
    return res;
  }
};
}