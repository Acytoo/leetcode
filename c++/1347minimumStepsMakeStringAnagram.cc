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
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minSteps(string s, string t) {
    int dic1['z'+1] = {0}, dic2['z'+1] = {0};
    for (const char c: s)
      ++dic1[c];
    for (const char c: t)
      ++dic2[c];
    int diff = 0;
    for (int i='a'; i<='z'; ++i)
      diff += abs(dic1[i]-dic2[i]);
    //cout << diff << endl;
    return (diff&1)? (diff>>1)+1: (diff>>1);
  }
};
;

int main() {
  Solution s;
  
  return 0;
}
