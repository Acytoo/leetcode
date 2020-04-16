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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From wzc1995
class SnapshotArray {
 public:
  SnapshotArray(int length): id_(0) {
    data_.resize(length, vector<pair<int, int>>(1));
    for (int i=0; i<length; ++i)
      data_[i][0] = make_pair(0, 0);
  }

  void set(int index, int val) {
    auto &latest = data_[index][data_[index].size()-1];
    if (latest.first == id_)
      latest.second = val;
    else
      data_[index].emplace_back(make_pair(id_, val));
  }

  int snap() {
    return id_++;
  }

  int get(int index, int snap_id) {
    auto &vers = data_[index];
    int l = 0, r = vers.size()-1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (vers[m+1].first <= snap_id)
        l = m + 1;
      else
        r = m;
    }
    return vers[l].second;
  }

 private:
  vector<vector<pair<int, int>>> data_;  // index, (version->value)s
  int id_;
};



class SnapshotArray_MLE {  // MLE or TLE, depend on data_.reserve's size
 public:
  SnapshotArray(int length): id_(0) {
    data_ = vector<vector<int>> (1, vector<int> (length));
    data_.reserve(20000);
  }

  void set(int index, int val) {
    data_.back()[index] = val;
  }

  int snap() {
    data_.emplace_back(data_.back().begin(), data_.back().end());
    return id_++;
  }

  int get(int index, int snap_id) {
    return data_[snap_id][index];
  }
 private:
  vector<vector<int>> data_;
  int id_;
};

int main() {
  SnapshotArray s (3);
  s.set(0, 5);
  cout << s.snap() << endl;
  s.set(0, 6);
  cout << s.get(0, 0) << endl;
  return 0;
}
