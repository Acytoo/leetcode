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

class Solution {
public:
  int longestSubsequence(vector<int>& arr, int d) {
    unordered_map<int, int> dp;
    int res = 0;
    for (int x: arr)
      res = max(res, dp[x] = dp[x-d] + 1);
    return res;
  }
};
int main() {
  Solution s;
  vector<int> a = {1,2,3,4,5,6,6};
  cout << s.longestSubsequence(a, 1) << endl;
  return 0;
}
