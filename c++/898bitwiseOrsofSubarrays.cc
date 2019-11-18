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
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> res;
    unordered_set<int> cur;
    unordered_set<int> nxt;
    for (auto a : A) {
      nxt.clear();
      nxt.insert({a});
      for (auto b : cur) {
        nxt.insert(a | b);
      }
      cur.swap(nxt);
      res.insert(cur.begin(), cur.end());
    }
    return res.size();
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3};
  cout << s.subarrayBitwiseORs(a) << endl;
  return 0;
}
