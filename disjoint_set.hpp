#ifndef DSA_DISJOINT_SET
#define DSA_DISJOINT_SET
#include <unordered_map>
#include <unordered_set>

class Element {
 public:  
  int value;
  int parent;
  int rank;

  Element() : value(-1), parent(-1), rank(0){}
  Element(int val) : value(val), parent(val), rank(0) {}
  Element(const Element &e) : value(e.value), parent(e.parent), rank(e.rank) {}
};

class disjoint_set {
 private:
  std::unordered_map<int, Element> forest_;
  int count_;

  void initialize_set(std::unordered_set<int> &ele_set);

 public:
  disjoint_set(std::unordered_set<int> &ele_set) : count_(0) {
    initialize_set(ele_set);
  }
  bool set_union(int val1, int val2);
  int find_set(int x);
};
#endif