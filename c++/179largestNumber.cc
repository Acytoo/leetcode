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
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    if (nums.size() == 0)
      return "";
    vector<string> ns;
    ns.reserve(nums.size());
    for (int i: nums)
      ns.emplace_back(to_string(i));
    sort(ns.begin(), ns.end(), [&](const string& a, const string& b) {
                                     int na = a.size(), nb = b.size(), i = 0, n = na + nb;
                                     char ca = a[0], cb = b[0];
                                     while (i < n && ca == cb) {
                                       ++i;
                                       ca = i<na? a[i]: b[i-na];
                                       cb = i<nb? b[i]: a[i-nb];
                                     }
                                     return ca > cb;
                                   });
    string res = "";
    for (string s: ns)
      res += s;
    return res[0] == '0'? "0": res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1, 12, 34, 45, 571, 55, 56};
  s.largestNumber(a);
  return 0;
}
