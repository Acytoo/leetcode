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

class Solution{
public:
  int maxLength(vector<string>& arr) {
    vector<int> a;
    for (const string& x: arr) {
      int mask = 0;
      for (char c: x) mask |= 1 << (c-'a'); // Binary 'a':1, 'b':10, 'c':100
      if (__builtin_popcount(mask) != x.length()) continue; // __builtin_:function from gcc
      a.push_back(mask);
    }
    int res = 0;
    function<void(int, int)> dfs = [&](int s, int mask) {
                                     res = max(res, __builtin_popcount(mask));
                                     for (int i=s, stop=a.size(); i<stop; ++i)
                                       if ((mask & a[i]) == 0)
                                         dfs(i+1, mask | a[i]);
                                   };
    dfs(0, 0);
    return res;
  }
};
int main() {
  Solution s;
  vector<string> a = {"un", "in", "qe", "i"};
  cout << s.maxLength(a) << endl;
  return 0;
}
