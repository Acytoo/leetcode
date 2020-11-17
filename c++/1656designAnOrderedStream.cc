#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class OrderedStream {
 public:
  OrderedStream(int n): ptr_(1) {
    data_ = vector<string> (++n);
    ids_ = vector<bool> (n);
  }

  vector<string> insert(int id, string value) {
    ids_[id] = true;
    data_[id] = value;
    if (!ids_[ptr_]) return {};
    vector<string> res;
    for (int i = ptr_, n = ids_.size(); i < n; ++i)
      if (ids_[i]) {
        // res.emplace_back(move(data_[i]));
        res.push_back(data_[i]);
        ptr_ = i + 1;
      } else {
        break;
      }
    return res;
  }
 private:
  vector<string> data_;
  vector<bool> ids_;
  int ptr_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

int main() {
  Solution s;
  
  return 0;
}
