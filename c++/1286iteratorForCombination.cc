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
  CombinationIterator(string characters, int combinationLength) {
    const int n = characters.size();
    function<void(int, string)> helper =
        [&] (int idx, string cur) {
          if (cur.size() == combinationLength) {
            dq_.emplace_back(move(cur));
            return ;
          }
          for (int i = idx; i < n; ++i)
            helper(i + 1, cur + characters[i]);
        };
    helper(0, "");
  }

  string next() {  // It's guaranteed that all calls of the function next are valid.
    string res = dq_.front();
    dq_.pop_front();
    return res;
  }

  bool hasNext() {
    return !dq_.empty();
  }
 private:
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
