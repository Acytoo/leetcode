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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 2 <= arr.length <= 10^5
// -10^6 <= arr[i] <= 10^6
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = INT_MAX, stop = arr.size()-1;
    for (int i: arr)
      cout << i << " ";
    cout << endl;
    vector<int> diffs(stop, 0);
    for (int i=0; i<stop; ++i) {
      diffs[i] = arr[i+1] - arr[i];
      diff = min(diff, diffs[i]);
    }
    vector<vector<int>> res;
    for (int i=0; i<stop; ++i) {
      if (diff == diffs[i]) {
        res.push_back({arr[i], arr[i]+diff});
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,22,-3,-4,5,6,23};
  vector<vector<int>> res = s.minimumAbsDifference(a);
  for (auto i: res) {
    for (auto j: i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
