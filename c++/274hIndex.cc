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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return min(1, citations[0]);
    sort(citations.begin(), citations.end(), std::greater<int>());
    int res = 0;
    for (int i=0; i<n; )
      if (citations[i] >= ++i)
        ++res;
      else
        break;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
