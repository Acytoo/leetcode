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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    if (n == 0)
      return {};
    if (n == 1)
      return {1};
    vector<pair<int, int>> ranks;  // value, index
    ranks.reserve(n);
    for (int i=0; i<n; ++i)
      ranks.emplace_back(arr[i], i);

    sort(ranks.begin(), ranks.end());
    vector<int> res (n);
    int i=1;
    int last_num = ranks[0].first;
    for (auto it: ranks) {
      if (last_num != it.first)
        ++i;
      res[it.second] = i;
      last_num = it.first;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {0,0, 23,1,6,6,32};
  vector<int> res = s.arrayRankTransform(a);
  for (int i: res)
    cout << i << " " ;
  cout << endl;
  return 0;
}
