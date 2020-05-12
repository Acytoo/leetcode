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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class FirstUnique {
 public:
  FirstUnique(vector<int>& nums) {
    for (const int num: nums) {
      ++m_[num];
      q_.push(num);
    }
  }

  int showFirstUnique() {
    while (!q_.empty() && m_[q_.front()] > 1) q_.pop();
    return q_.empty()? -1: q_.front();
  }

  void add(int value) {
    ++m_[value];
    if (m_[value] == 1) q_.push(value);
  }
 private:
  unordered_map<int, int> m_;  // num --> occurrences
  queue<int> q_;
};

class FirstUnique_TLE1 {
 public:
  FirstUnique(vector<int>& nums) {
    nums_ = nums;
    for (const int num: nums)
      ++m_[num];
  }

  int showFirstUnique() {
    for (const int num: nums_)
      if (m_[num] == 1)
        return num;
    return -1;
  }

  void add(int value) {
    auto it = m_.find(value);
    if (it == m_.end()) {
      m_[value] = 1;
      nums_.push_back(value);
    } else if (it->second == 1) {
      ++it->second;
    }
  }
 private:
  unordered_map<int, int> m_;  // num --> occurrences
  vector<int> nums_;
};

class FirstUnique_TLE {
 public:
  FirstUnique(vector<int>& nums) {
    nums_ = nums;
    for (const int num: nums)
      ++m_[num];
  }

  int showFirstUnique() {
    for (const int num: nums_)
      if (m_[num] == 1)
        return num;
    return -1;
  }

  void add(int value) {
    ++m_[value];
    nums_.push_back(value);
  }
 private:
  unordered_map<int, int> m_;  // num --> occurrences
  vector<int> nums_;
};

int main() {
  // FirstUnique f;
  vector<int> a = {1};
  vector<int> b = a;
  a[0] = 100;
  cout << a[0] << " " << b[0] << endl;
  return 0;
}
