#pragma once

// 292. Nim ��Ϸ (��)
namespace N292
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
namespace N670
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
namespace N1686
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
namespace N1402
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

  }
};
}