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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string customSortString(string S, string T) {
    vector<int> order('z'+1, 26);
    for (int i=0, stop=S.size(); i<stop; ++i)
      order[S[i]] = i;
    sort(T.begin(), T.end(), [&](const char a, const char b) {
                               return order[a] < order[b];
                             });
    return T;
  }
};

int main() {
  Solution s;
  
  return 0;
}
