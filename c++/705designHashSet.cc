#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// All values will be in the range of [0, 1000000]
class MyHashSet1 {
 public:
  /** Initialize your data structure here. */
  MyHashSet() {
    data_ = {false};
  }

  void add(int key) {
    data_[key] = true;
  }

  void remove(int key) {
    data_[key] = false;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    return data_[key];
  }
 private:
  array<bool, 1000001> data_;
};

class MyHashSet {
 public:
  MyHashSet() {
    data_.reset();
  }
  void add(int key) {
    data_[key] = 1;
  }
  void remove(int key) {
    data_[key] = 0;
  }
  bool contains(int key) {
    return data_[key];
  }
 private:
  bitset<1000001> data_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
  Solution s;
  
  return 0;
}
