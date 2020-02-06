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
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> q = f(queries), w = f(words);
    int n = queries.size();
    vector<int> res (n, 0);
    for (int i=0; i<n; ++i)
      for (int ww: w)
        if (q[i] < ww)
          ++res[i];
    return res;
  }
 private:
  vector<int> f(const vector<string>& strs) {
    int n = strs.size();
    vector<int> res (n);
    for (int i=0; i<n; ++i) {
      int letters[26] = {0};
      for (char c: strs[i])
        ++letters[c-'a'];
      for (int j=0; j<26; ++j)
        if (letters[j]) {
          res[i] = letters[j];
          break;
        }
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
