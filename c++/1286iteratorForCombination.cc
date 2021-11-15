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
class CombinationIterator {
 public:
  CombinationIterator(string characters, int combinationLength):
      chars_ (characters.rbegin(), characters.rend()) {
    n_ = combinationLength;
    mask_ = (1 << characters.size()) - 1;
  }

  string next() {
    hasNext();
    string res;
    for (int i = chars_.size() - 1; i >= 0; --i)
      if ((mask_ >> i) & 1)
        res.push_back(chars_[i]);
    --mask_;
    return res;
  }

  bool hasNext() {
    while (mask_ >= 0 && __builtin_popcount(mask_) != n_) --mask_;
    return mask_ > 0;
  }
 private:
  int mask_, n_;
  string chars_;
};

class CombinationIterator1 {
 public:
  CombinationIterator(string characters, int combinationLength) {
    const int n = characters.size();
    function<void(int, string)> helper = [&] (const int idx, string cur) {
      if (cur.size() == combinationLength) {
        dq_.push_back(cur);
        return;
      }
      for (int i = idx; i < n; ++i)
        helper(i + 1, cur + characters[i]);
    };
    helper(0, "");
  }

  // It's guaranteed that all calls of the function next are valid.
  string next() {
    string res = dq_.front();
    dq_.pop_front();
    return res;
  }

  bool hasNext() {
    return !dq_.empty();
  }
  deque<string> dq_;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
  Solution s;
  
  return 0;
}
