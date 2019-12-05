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

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> res(searchWord.size());
    if (products.empty()) return res;
    sort(products.begin(), products.end());
    string key;
    int i=0;
    for (char c: searchWord) {
      key += c;
      auto l = lower_bound(products.begin(), products.end(), key);
      auto r = upper_bound(products.begin(), products.end(), key+='~');
      if (l == r) break;
      key.pop_back();
      res[i++] = {l, min(l+3, r)};
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a = {"mobile","mouse","moneypot","monitor","mousepad"};
  for (auto i : s.suggestedProducts(a, "mouse")) {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}
