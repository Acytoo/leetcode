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

using namespace std;

// from huahua
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<Event> events;
    events.reserve(buildings.size()*2);
    int id = 0;
    for (const auto& b: buildings) {
      events.emplace_back(Event{id, b[0], b[2], 1});
      events.emplace_back(Event{id, b[1], b[2], -1});
      ++id;
    }
    sort(events.begin(), events.end());
    MaxHeap heap(buildings.size());
    vector<vector<int>> res;
    for (const auto& event: events) {
      int x = event.x;
      int h = event.h;
      int id = event.id;
      int type = event.type;
      if (type == 1) {
        if (heap.Max() < h)
          res.emplace_back(std::initializer_list<int>{x, h});
        heap.Add(h, id);
      } else {
        heap.Remove(id);
        if (heap.Max() < h)
          res.emplace_back(std::initializer_list<int>{x, heap.Max()});
      }
    }
    return res;
  }
 private:
  struct Event {
    int id;
    int x;
    int h;
    int type; // 1: enter; -1: leave
    bool operator<(const Event& e) const {
      if (x == e.x) {
        return type * h > e.type * e.h;
      }
      return x < e.x;
    }
  };

  class MaxHeap {
   public:
    MaxHeap(int max_items):
        idx_(max_items, -1), vals_(max_items), size_(0) {}

    void Add(int key, int id) {
      idx_[id] = size_;
      vals_[size_] = {key, id};
      ++size_;
      HeapifyUp(idx_[id]);
    }

    void Remove(int id) {
      int idx_to_evict = idx_[id];
      SwapNode(idx_to_evict, size_-1);
      --size_;
      HeapifyDown(idx_to_evict);
      HeapifyDown(idx_to_evict);
    }

    bool Empty() const {
      return size_ == 0;
    }

    int Max() const {
      return Empty()? 0: vals_.front().first;
    }
   private:
    void SwapNode(int i, int j) {
      if (i == j)
        return;
      std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
      std::swap(vals_[i], vals_[j]);
    }

    void HeapifyUp(int i) {
      while (i != 0) {
        int p = (i - 1) / 2;
        if (vals_[i].first <= vals_[p].first)
          return;
        SwapNode(i, p);
        i = p;
      }
    }

    void HeapifyDown(int i) {
      while (true) {
        int c1 = i*2 + 1;
        int c2 = i*2 + 2;
        if (size_ <= c1)
          return ;
        int c = (c2 < size_ &&
                 vals_[c1].first < vals_[c2].first)? c2: c1;
        if (vals_[c].first <= vals_[i].first)
          return ;
        SwapNode(c, i);
        i = c;
      }
    }

    vector<pair<int, int>> vals_;
    vector<int> idx_;
    int size_;
  };
};


int main() {
  Solution s;
  
  return 0;
}
