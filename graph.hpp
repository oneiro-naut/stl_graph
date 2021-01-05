#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

typedef std::pair<int,int> ipair;
typedef std::pair<int, std::pair<int, int>> k_edge; //Kruskal Edge

class Graph {
 private:
  unsigned V_;
  unsigned E_;
  unsigned size_;
  std::unordered_set<int> vertices_;
  std::unordered_map<int, std::list<ipair>> edges_;

  void bfs_util(int key, std::unordered_set<int>& visited) const;
  void dfs_util_recur(int key, std::unordered_set<int>& visited) const;
  void dfs_util_stack_based(int key, std::unordered_set<int>& visited) const;

 public:
  Graph() : V_(0), E_(0), size_(0) {}
  void add_vertex(int key);
  void add_edge(int from, int to, int weight);
  void add_edge_di(int from, int to, int weight);
  bool find_vertex(int key) const;
  bool find_edge(int from, int to, int weight) const;
  void delete_edge(int from, int to, int weight);
  void delete_edge_di(int from, int to, int weight);
  void delete_vertex(int key);
  void print_edges() const;
  void print_size() const;
  void dfs(int key);
  void complete_dfs() const;
  void bfs() const;
  std::vector<k_edge> MST_Kruskal();
  std::vector<k_edge> MST_Prim();
  std::vector<k_edge> SPT_Dijkstra(int src);
};
#endif