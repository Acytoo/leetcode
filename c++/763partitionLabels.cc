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
  vector<int> partitionLabels(string S) {
    int dict['z'+1] = {0};  // last index
    vector<int> res;
    int l = 0, r = 0;
    for (int i = 0, stop = S.size(); i < stop; ++i) dict[S[i]] = i;
    for (int i = 0, stop = S.size(); i < stop; ++i) {
      r = max(r, dict[S[i]]);
      if (i == r) {
        res.push_back(r - l + 1);
        l = r + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
