#pragma once

// 133. ��¡ͼ (�е�)
namespace n133
{
//�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����
//
//ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]����
//
//class Node {
//  public int val;
//  public List<Node> neighbors;
//}
//
//
//����������ʽ��
//
//�������ÿ���ڵ��ֵ��������������ͬ�����磬��һ���ڵ�ֵΪ 1��val = 1�����ڶ����ڵ�ֵΪ 2��val = 2�����Դ����ơ���ͼ�ڲ���������ʹ���ڽ��б��ʾ��
//
//�ڽ��б� �����ڱ�ʾ����ͼ�������б�ļ��ϡ�ÿ���б�������ͼ�нڵ���ھӼ���
//
//�����ڵ㽫ʼ����ͼ�еĵ�һ���ڵ㣨ֵΪ 1��������뽫 �����ڵ�Ŀ��� ��Ϊ�Կ�¡ͼ�����÷��ء�

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node* cloneGraph([[maybe_unused]] Node* node) {
  }
};
}

// 1976. ����Ŀ�ĵصķ�����
namespace n1976
{
//����һ������������� n ��·����ɣ�·�ڱ��Ϊ 0 �� n - 1 ��ĳЩ·��֮���� ˫�� ��·�����뱣֤����Դ�����·�ڳ���������������·�ڣ�����������·��֮�������һ��·��
//
//����һ������ n �Ͷ�ά�������� roads ������ roads[i] = [ui, vi, timei] ��ʾ��·�� ui �� vi ֮����һ����Ҫ���� timei ʱ�����ͨ���ĵ�·������֪������ ����ʱ�� ��·�� 0 ��������·�� n - 1 �ķ�������
//
//�뷵�ػ��� ����ʱ�� ����Ŀ�ĵص� ·����Ŀ �����ڴ𰸿��ܴܺ󣬽������ 109 + 7 ȡ�� �󷵻ء�

class Solution {
public:
  int countPaths([[maybe_unused]] int n, [[maybe_unused]] vector<vector<int>>& roads) {
  }
};
}