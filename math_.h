#pragma once

// 2591. ��Ǯ�ָ����Ķ�ͯ (�򵥣�
namespace n2591
{
//����һ������ money ����ʾ���ܹ��е�Ǯ������λΪ��Ԫ������һ������ children ����ʾ��Ҫ��Ǯ��������ٸ���ͯ��
//
//����Ҫ�������¹�����䣺
//
//���е�Ǯ�����뱻���䡣
//ÿ����ͯ���ٻ�� 1 ��Ԫ��
//û���˻�� 4 ��Ԫ��
//���㰴��������������Ǯ�������� ��� �ж��ٸ���ͯ��� ǡ�� 8 ��Ԫ�����û���κη��䷽�������� - 1 ��
class Solution {
public:
  int distMoney(int money, int children) {
    money -= children;
    if (money < 0) return -1;
    int res = money / 7;
    int left = money % 7;
    if (res > children || res == children && left > 0)
    {
      return children - 1;
    }
    else if (res == children - 1 && left == 3)
    {
      return children - 2;
    }
    return res;
  }
};
}