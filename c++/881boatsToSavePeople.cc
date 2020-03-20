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
// Greedy
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int res = 0;
    sort(people.rbegin(), people.rend());
    int i=0; j=people.size()-1;
    while (i <= j) {
      ++res;
      if (i == j)
        break;
      if (people[i] + people[j] <= limit)
        --j;
      ++i;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
