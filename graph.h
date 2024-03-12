#pragma once

// 133. 克隆图 (中等)
namespace n133
{
//给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
//
//图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
//
//class Node {
//  public int val;
//  public List<Node> neighbors;
//}
//
//
//测试用例格式：
//
//简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。
//
//邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
//
//给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

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

// 797. 所有可能的路径 (中等)
namespace n797
{
//给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n - 1 的路径并输出（不要求按特定顺序）
//
//graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
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

// 1976. 到达目的地的方案数 (中等)
namespace n1976
{
//你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。
//
//给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。
//
//请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 109 + 7 取余 后返回。

class Solution {
public:
  int countPaths([[maybe_unused]] int n, [[maybe_unused]] vector<vector<int>>& roads) {
  }
};
}