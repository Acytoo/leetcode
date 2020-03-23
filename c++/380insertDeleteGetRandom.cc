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
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    k_v_.clear();
    v_k_.clear();
    idx_ = -1;
  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    auto it = v_k_.find(val);
    if (it != v_k_.end())
      return false;
    v_k_[val] = ++idx_;
    k_v_[idx_] = val;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = v_k_.find(val);
    if (it == v_k_.end())
      return false;
    int k = v_k_[val];
    int v = k_v_[idx_];
    v_k_[v] = k;
    k_v_[k] = v;
    k_v_.erase(idx_);
    v_k_.erase(val);
    --idx_;
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int k = static_cast<int> (rand()/static_cast<double>(RAND_MAX)*(idx_+1));
    return k_v_[k];
  }
 private:
  unordered_map<int, int> k_v_, v_k_;
  int idx_;
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
  Solution s;
  
  return 0;
}
