  #pragma once

// 466. ͳ���ظ����� (����)
namespace n466
{
//���� str = [s, n] ��ʾ str �� n ���ַ��� s ���ӹ��ɡ�
//
//���磬str == ["abc", 3] == "abcabcabc" ��
//������Դ� s2 ��ɾ��ĳЩ�ַ�ʹ���Ϊ s1������ַ��� s1 ���Դ��ַ��� s2 ��á�
//
//���磬���ݶ��壬s1 = "abc" ���Դ� s2 = "abdbec" ��ã�����Ҫɾ���Ӵ�����б���ʶ���ַ���
//���ڸ��������ַ��� s1 �� s2 ���������� n1 �� n2 ���ɴ˹���õ������ַ��������� str1 = [s1, n1]��str2 = [s2, n2] ��
//
//�����ҳ�һ��������� m �������� str = [str2, m] ���Դ� str1 ���
class Solution {
public:
  int getMaxRepetitions([[maybe_unused]] string s1, [[maybe_unused]] int n1, [[maybe_unused]] string s2, [[maybe_unused]] int n2) {
  }
};
}

// 2719. ͳ��������Ŀ (����)
namespace n2719
{
//�������������ַ��� num1 �� num2 ���Լ��������� max_sum �� min_sum �����һ������ x �����������������ǳ�����һ����������
//
//num1 <= x <= num2
//min_sum <= digit_sum(x) <= max_sum.
//���㷵�غ���������Ŀ���𰸿��ܴܺ��뷵�ش𰸶� 109 + 7 ȡ���Ľ����
//
//ע�⣬digit_sum(x) ��ʾ x ��λ����֮�͡�
class Solution {
public:
  int count([[maybe_unused]] string num1, [[maybe_unused]] string num2, [[maybe_unused]] int min_sum, [[maybe_unused]] int max_sum) {
  }
};
}

// 2809. ʹ�����С�ڵ��� x ������ʱ�� (����)
namespace n2809
{
//����������������±�� 0 ��ʼ���������� nums1 �� nums2 ��ÿһ�룬���������±� 0 <= i < nums1.length ��nums1[i] ��ֵ������ nums2[i] ������ ��ɺ� ������Խ������²�����
//
//  ѡ����һ���� 0 <= i < nums1.length ���±� i ����ʹ nums1[i] = 0 ��
//  ͬʱ����һ������ x ��
//
//  ���㷵��ʹ nums1 ������Ԫ��֮�� С�ڵ��� x ����Ҫ�� ���� ʱ�䣬����޷�ʵ�֣���ô���� - 1 ��
class Solution {
public:
  int minimumTime([[maybe_unused]] vector<int>& nums1, [[maybe_unused]] vector<int>& nums2, [[maybe_unused]] int x) {
  }
};
}

// 2846. ��Ȩ�ؾ��Ȳ�ѯ (����)
namespace n2846
{
//����һ���� n ���ڵ���ɵ����������ڵ㰴�� 0 �� n - 1 ��š�����һ������ n ��һ������Ϊ n - 1 �Ķ�ά�������� edges ������ edges[i] = [ui, vi, wi] ��ʾ���д���һ��λ�ڽڵ� ui �ͽڵ� vi ֮�䡢Ȩ��Ϊ wi �ıߡ�
//
//�����һ������Ϊ m �Ķ�ά�������� queries ������ queries[i] = [ai, bi] ������ÿ����ѯ�������ҳ�ʹ�� ai �� bi ·����ÿ���ߵ�Ȩ���������� ��С�������� ����һ�β����У������ѡ�����ϵ�����һ���ߣ�������Ȩ�ظ���Ϊ����ֵ��
//
//ע�⣺
//
//��ѯ֮�� �໥���� �ģ�����ζ��ÿ���µĲ�ѯʱ��������ص� ��ʼ״̬ ��
//�� ai �� bi��·����һ���� ��ͬ �ڵ���ɵ����У��ӽڵ� ai ��ʼ�����ڵ� bi �����������������ڵ������ڵ������й���һ���ߡ�
//����һ������Ϊ m ������ answer ������ answer[i] �ǵ� i ����ѯ�Ĵ𰸡�

class Solution {
public:
  vector<int> minOperationsQueries([[maybe_unused]] int n, [[maybe_unused]] vector<vector<int>>& edges, [[maybe_unused]] vector<vector<int>>& queries) {

  }
};
}