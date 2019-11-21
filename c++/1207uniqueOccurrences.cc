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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= arr.length <= 1000, -1000 <= arr[i] <= 1000 : use vector instead of map
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    vector<int> arr_map(2000, 0);
    for (auto i : arr) {
      ++arr_map[i+1000];
    }
    vector<bool> occur_set(1001, true);
    for (auto i : arr_map) {
      if (i != 0) {
        if (occur_set[i])
          occur_set[i] = false;
        else
          return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,1,2,3,4,6,4,4,4,7,9,9,9};
  cout << s.uniqueOccurrences(a) << endl;
  return 0;
}
