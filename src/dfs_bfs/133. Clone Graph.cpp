/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if (!node) return node;
      stack<UndirectedGraphNode *> stk;
      dfs(stk, node);
      UndirectedGraphNode *start;
      while (!stk.empty()) {
        UndirectedGraphNode *oldNode = stk.top();
        stk.pop();
        UndirectedGraphNode *newNode = mapping.find(oldNode->label)->second;
        for (UndirectedGraphNode *n : oldNode->neighbors) {
          newNode->neighbors.push_back(mapping.find(n->label)->second);
        }
        start = newNode;
      }
      return start;
    }
private:
    void dfs(stack<UndirectedGraphNode *> &stk, UndirectedGraphNode *node) {
      if (mapping.find(node->label) != mapping.end()) {
        return;
      }
      mapping.insert({node->label, new UndirectedGraphNode(node->label)});
      stk.push(node);
      for (UndirectedGraphNode *n : node->neighbors) {
        dfs(stk, n);
      }
    }
    unordered_map<int, UndirectedGraphNode*> mapping;
};