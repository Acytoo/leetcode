#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class LRUCache {
public:
  LRUCache(int capacity):capacity_(capacity) {
  }

  int get(int key) {
    const auto it = map_.find(key);
    if (it == map_.cend()) return -1;
    list_.splice(list_.begin(), list_, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    const auto it = map_.find(key);
    if (it != map_.cend()) {
      it->second->second = value;
      list_.splice(list_.begin(), list_, it->second);
      return;
    }
    if (list_.size() == capacity_) {
      map_.erase(list_.back().first);
      list_.pop_back();
    }
    list_.emplace_front(key, value);
    map_[key] = list_.begin();
  }
private:
  unordered_map<int, list<pair<int, int>>::iterator> map_;
  list<pair<int, int>> list_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache s(2);
  
  return 0;
}
