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

// 797. ���п��ܵ�·�� (�е�)
namespace n797
{
//����һ���� n ���ڵ�� �����޻�ͼ��DAG���������ҳ����дӽڵ� 0 ���ڵ� n - 1 ��·�����������Ҫ���ض�˳��
//
//graph[i] ��һ���ӽڵ� i ���Է��ʵ����нڵ���б����ӽڵ� i ���ڵ� graph[i][j]����һ������ߣ���
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(int)> dfs = [&](int n)
      {
        path.push_back(n);
        if (n == graph.size() - 1)
        {
          result.push_back(path);
        }
        else
        {
          for (auto& i : graph[n])
          {
            dfs(i);
          }
        }
        path.pop_back();
      };
    dfs(0);
    return result;
  }
};
}

// 1976. ����Ŀ�ĵصķ����� (�е�)
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