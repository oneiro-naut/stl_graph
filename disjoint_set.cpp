#include<iostream>

#include "disjoint_set.hpp"

// x is essentially the same as forest_[x].value
// recursive parent search
int disjoint_set::find_set(int x) {
  if (forest_.find(x) != forest_.end()) {
    if (forest_[x].parent == forest_[x].value)
      return x;
    else
      return find_set(forest_[x].parent);
  } else
    return -1;
}

bool disjoint_set::set_union(int val1, int val2) {
  int parent1 = find_set(val1);
  int parent2 = find_set(val2);
  if (parent1 == parent2)
    return true;    //already in the same set (can be thought of as condition for cycle in graph)
  if (forest_[parent1].rank > forest_[parent2].rank) 
    forest_[parent2].parent = parent1;
  else if (forest_[parent1].rank < forest_[parent2].rank)
    forest_[parent1].parent = parent2;
  else {
    forest_[parent2].parent = parent1;
    forest_[parent1].rank += 1;
  }
  return false;
}

void disjoint_set::initialize_set(std::unordered_set<int> &ele_set) {
  for (auto i : ele_set) {
    auto p = std::make_pair(i, Element(i));
    forest_.insert(p);
  }
  count_ = forest_.size();
}

// int main(int argc, char **argv) {
//   std::unordered_set<int> test_set{0, 1, 2, 3, 4};
//   disjoint_set D = disjoint_set(test_set);
//   std::cout << D.set_union(0, 2) << "\n"; // 0
//   std::cout << D.set_union(4, 2) << "\n"; // 0
//   std::cout << D.set_union(0, 4) << "\n"; // 1
//   std::cout << D.set_union(1, 3) << "\n"; // 0
//   return 0;
// }