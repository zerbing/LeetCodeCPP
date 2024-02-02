#pragma once

// 2865. ������ I (����)
namespace N2865
{
//����һ������Ϊ n �±�� 0 ��ʼ���������� maxHeights ��
//
//������������������Ͻ� n �������� i �������±�Ϊ i ���߶�Ϊ heights[i] ��
//
//��������������㣬���ǳ���Щ���� ���� �ģ�
//
//1 <= heights[i] <= maxHeights[i]
//heights ��һ�� ɽ�� ���顣
//��������±� i ����������������ô���ǳ����� heights ��һ�� ɽ�� ���飺
//
//�������� 0 < j <= i ������ heights[j - 1] <= heights[j]
//  �������� i <= k < n - 1 ������ heights[k + 1] <= heights[k]
//  ���㷵������ ������ Ҫ��ķ����У��߶Ⱥ͵����ֵ ��
class Solution {
public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    vector<long long> leftHeights(maxHeights.size(), 0);
    vector<long long> rightHeights(maxHeights.size(), 0);
    // ������ߵĸ߶�
    stack<int> st;
    int n = static_cast<int>(maxHeights.size());
    for (int i = 0; i < n; ++i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        leftHeights[i] = static_cast<long long>(maxHeights[i]) * (i + 1);
      }
      else
      {
        leftHeights[i] = leftHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (i - st.top());
      }
      st.push(i);
    }
    // �����ұߵĸ߶�
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i)
    {
      while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        rightHeights[i] = static_cast<long long>(maxHeights[i]) * (maxHeights.size() - i);
      }
      else
      {
        rightHeights[i] = rightHeights[st.top()] + static_cast<long long>(maxHeights[i]) * (st.top() - i);
      }
      st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < maxHeights.size(); ++i)
    {
      res = max(res, leftHeights[i] + rightHeights[i] - maxHeights[i]);
    }
    return res;
  }
};
}