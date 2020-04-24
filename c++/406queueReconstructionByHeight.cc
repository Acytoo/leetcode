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
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
                                         return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
                                       });
    vector<vector<int>> res;
    for (const auto &p : people)
      res.emplace(res.begin()+p[1], move(p));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
