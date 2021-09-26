#include "graph.hpp"
#include "disjoint_set.hpp"

int main(int argc, char **argv) {
  Graph G = Graph();
  G.print_size();
  G.add_edge(0, 1, 4); // from, to, weight
  G.add_edge(1, 2, 8);
  G.add_edge(2, 3, 7);
  G.add_edge(5, 6, 2);
  G.add_edge(0, 7, 8);
  G.add_edge(1, 7, 11);
  G.add_edge(7, 6, 1);
  G.add_edge(7, 8, 7);
  G.add_edge(2, 8, 2);
  G.add_edge(2, 5, 4);
  G.add_edge(3, 5, 14);
  G.add_edge(4, 5, 10);
  G.add_edge(3, 4, 9);
  G.add_edge(3, 4, 7);
  G.add_edge(8, 6, 6);
  G.print_size();
  G.print_edges();
  //   G.dfs(1);
  G.complete_dfs();
  //G.traverse([this](int key, std::unordered_set<int>& visited) { return bfs_util(key, visited); });
  G.bfs();
  G.MST_Kruskal();
  G.MST_Prim();
  G.SPT_Dijkstra(8);
  return 0;

}
