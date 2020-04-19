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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    const int n = s.size();
    vector<string> res;
    if (n < 11) return res;

    unordered_map<string, bool> m;
    for (int i=0, stop=s.size()-9; i<stop; ++i) {
      string tmp = s.substr(i, 10);
      auto it = m.find(tmp);
      if (it == m.end()) {
        m[tmp] = false;
      } else if (!m[tmp]){
        m[tmp] = true;
        res.emplace_back(move(tmp));
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  for (const string str: s.findRepeatedDnaSequences("AAAAAAAAAAAAAAAAAAAAAAAAAAA"))
    cout << str << endl;
  return 0;
}
