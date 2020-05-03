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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int calPoints(vector<string>& ops) {
    vector<int> scores (ops.size());
    int idx = 0;
    for (const string &op: ops) {
      if (op == "+") {
        scores[idx] = scores[idx - 2] + scores[idx - 1];
        ++idx;
      } else if (op == "D") {
        scores[idx] = scores[idx - 1] * 2;
        ++idx;
      } else if (op == "C") {
        --idx;
      } else {
        scores[idx] = stoi(op);
        ++idx;
      }
    }
    return accumulate(scores.begin(), scores.begin() + idx, 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
