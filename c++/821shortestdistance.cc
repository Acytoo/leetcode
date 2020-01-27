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
  vector<int> shortestToChar(string S, char C) {
    vector<int> res (S.size());
    int dis = 10001;
    for (int i=0, stop=S.size(); i<stop; ++i)
      if (S[i] == C) {
        res[i] = 0;
        dis = 0;
      } else {
        res[i] = ++dis;
      }
    for (int i=S.size()-1; 0<=i; --i)
      if (S[i] == C) {
        res[i] = 0;
        dis = 0;
      } else {
        res[i] = min(res[i], ++dis);
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
