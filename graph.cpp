#include <iostream>
#include <iterator>
#include <deque>

#include "graph.hpp"
#include "disjoint_set.hpp"
//directed graph


/**
0 5 -> 4 -> 3 -> null
1 null
2 6 -> 7 -> null
3
.
.
.
V_-1

**/

void Graph::add_vertex(int key) {
  if (!find_vertex(key))
    vertices_.insert(key); 
  else {
    std::cout << "Vertex "<< key <<" already present " << "\n" ;
    return;
  }
  ++V_;
  ++size_;
  std::cout << "Added vertex with value = " << key << "\n";
}

void Graph::add_edge_di(int from, int to, int weight) {
  add_vertex(from);
  add_vertex(to);
  if (!find_edge(from, to, weight)) {
    edges_[from].push_back(std::make_pair(to, weight));
    E_++;
    std::cout << "Added edge\n";
  }
  else
    std::cout << "Edge already present\n";
}

void Graph::add_edge(int from, int to, int weight) {
  add_vertex(from);
  add_vertex(to);
  if (!find_edge(from, to, weight)) {
    edges_[from].push_back(std::make_pair(to, weight));
    std::cout << "Added edge\n";
  }
  if (!find_edge(to, from, weight)) {
    edges_[to].push_back(std::make_pair(from, weight));
    E_++;
    std::cout << "Added edge\n";
  }
  else
    std::cout << "Edge already present\n";
}

bool Graph::find_vertex(int key) const {
  return vertices_.find(key) != vertices_.end();
}

bool Graph::find_edge(int from, int to, int weight) const {
  if (edges_.find(from) == edges_.end()) {
    std::cout << "Edge not found!\n";
    return false;
  }
  for (auto j : edges_.at(from))
    if (j.first == to && j.second == weight)
      return true;
  return false;
}

void Graph::delete_edge_di(int from, int to, int weight) {
  if (!find_edge(from, to, weight))
    std::cout << "Edge already absent!\n";
  for (auto it = edges_[from].begin(); it != edges_[from].end();) {
    if ((*it).first == to && (*it).second == weight) {
      it = edges_[from].erase(it);
      --E_;
    } 
    else
      ++it;
  }
}

void Graph::delete_edge(int from, int to, int weight) {
  if (!find_edge(from, to, weight) && !find_edge(from, to, weight))
    std::cout << "Edge already absent!\n";
  for (auto it = edges_[from].begin(); it != edges_[from].end();) {
    if ((*it).first == to && (*it).second == weight) {
      it = edges_[from].erase(it);
      --E_;
    } 
    else
      ++it;
  }
  for (auto it = edges_[to].begin(); it != edges_[to].end();) {
    if ((*it).first == from && (*it).second == weight) {
      it = edges_[to].erase(it);
    } 
    else
      ++it;
  }
}

void Graph::delete_vertex(int key) {
  if (!find_vertex(key)) {
    std::cout << "Vertex already absent!\n";
    return;
  }
  --V_;
  vertices_.erase(key);
  edges_.erase(key);
  for (auto& i : edges_) {
    for (auto j = i.second.begin(); j != i.second.end();) {
      if ((*j).first == key) {
        j = i.second.erase(j);
        std::cout << "Deleted an Edge!\n";
        --E_;
      }
      else
          ++j;
    }
  } 
  std::cout << "Deleted vertex = " << key << "\n";
}

void Graph::print_edges() const {
  for (auto i : edges_) 
    for (auto j : i.second) 
      std::cout << i.first << " ----> " << j.first << " w = " << j.second << "\n";
}

void Graph::print_size() const {
  std::cout << "Size of Graph is V = " << V_ << " E = " << E_<< " and Size = " <<size_ << "\n";
}

//depth first search(its a traversal not search)
//dfs isnt unique
void Graph::dfs(int key) {
  std::unordered_set<int> visited;
  std::cout << "DFS: \n";
  dfs_util_recur(key, visited);
}

void Graph::complete_dfs() const {
  std::unordered_set<int> visited;
  std::cout << "DFS complete: \n";
  for (auto i = vertices_.begin(); i != vertices_.end(); i++)
    if (visited.find(*i) == visited.end())
      dfs_util_stack_based(*i, visited);
}

void Graph::dfs_util_recur(int key, std::unordered_set<int>& visited) const {
  visited.insert(key);
  std::cout << key << "\n";
  for (auto i = edges_.at(key).begin(); i != edges_.at(key).end(); ++i)
    if (visited.find((*i).first) == visited.end())
      dfs_util_recur((*i).first, visited);
}

void Graph::dfs_util_stack_based(int key, std::unordered_set<int>& visited) const {
  std::deque<int> S;
  S.push_back(key);
  while (S.size() > 0) {
    const auto& u = S.back();
    S.pop_back();
    const bool unvisited = visited.find(u) == visited.end();
    if (unvisited) {
      visited.insert(u); 
      std::cout << u << " ";
      if (edges_.find(u) != edges_.end()) {
        const auto& adjacent_edges = edges_.at(u); //using at function causes out of range exception
        for (auto i = adjacent_edges.begin(); i != adjacent_edges.end(); ++i)
          S.push_back((*i).first);
        
      }
    }
  }
  std::cout << "\n";
}

void Graph::bfs() const {
  std::unordered_set<int> visited;
  std::cout << "BFS: \n";
  for (auto i = vertices_.begin(); i != vertices_.end(); i++) 
    if (visited.find(*i) == visited.end())
      bfs_util((*i), visited);
}

// void traverse(function<void(int, std::std::unordered_set<int>&)> traversal_util)
// {
//     std::unordered_set<int> visited;
//     std::cout << "Traversal: \n";
//     for(auto i = vertices.begin(); i != vertices.end(); i++)
//     {
//         if(visited.find(*i) == visited.end())
//             traversal_util((*i), visited);
//     }      
// }

void Graph::bfs_util(int key, std::unordered_set<int>& visited) const {
  std::deque<int> S;
  S.push_back(key);
  while (S.size() > 0) {
    const auto& u = S.front();
    S.pop_front();
    const bool unvisited = visited.find(u) == visited.end();
    if (unvisited) {
      visited.insert(u);
      std::cout << u << " ";
      if (edges_.find(u) != edges_.end()) {
        const auto& adjacent_edges = edges_.at(u); //but it doesnt coz any exception here:resolved
        for (auto i = adjacent_edges.begin(); i != adjacent_edges.end(); ++i)
          S.push_back((*i).first);
      }
    }
  }
  std::cout << "\n";
}

//can be faster if priority_queue of edges is maintained in the Graph class itself
std::vector<k_edge> Graph::MST_Kruskal() {
  disjoint_set st_forest(vertices_);  
  std::priority_queue<k_edge, std::vector<k_edge>, std::greater<k_edge>> sorted_edges;
  std::vector<k_edge> MST;
  for (auto i : edges_) 
    for (auto j : i.second) 
      sorted_edges.push(std::make_pair(j.second, std::make_pair(i.first, j.first)));
  std::cout << "MST(using Kruskal's algorithm)\n";
  while (sorted_edges.size() > 0) {
    auto min_cost_edge = sorted_edges.top();
    sorted_edges.pop();
    if (!st_forest.set_union(min_cost_edge.second.first, min_cost_edge.second.second)) {
      MST.push_back(min_cost_edge);
      std::cout << min_cost_edge.second.first << " <--> " << min_cost_edge.second.second << "\n";
      std::cout << min_cost_edge.first << "\n";
    }
    
  }
  
  return MST;
}




int main(int argc, char **argv) {
  Graph G = Graph();
  G.print_size();
  G.add_edge(0, 1, 4);
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
  return 0;
}