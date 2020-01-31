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
  int distributeCandies(vector<int>& candies) {
    bitset<200001> h;
    for (auto const& it : candies)
      h.set(it + 100000);
    return min(candies.size()/2, h.count());
  }
};

class Solution1 {
 public:
  int distributeCandies(vector<int>& candies) {
    int max_can = candies.size() / 2;
    if (max_can == 1)
      return 1;

    unordered_map<int, int> m;
    for (int i: candies) {
      auto it = m.find(i);
      if (it == m.end())
        m[i] = 1;
      else
        ++it->second;
    }
    int types = m.size();
    if (types >= max_can)
      return max_can;
    //
    return types;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,4,5,6};
  cout << s.distributeCandies(a) << endl;
  return 0;
}
