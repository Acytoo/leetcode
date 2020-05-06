#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int res = 0, m = 0;
    for (int i = 0, stop = arr.size(); i < stop; ++i)
      if (i == (m = max(m, arr[i]))) ++res;
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {4,3,2,1,0};
  a = {1,0,2,3,4,5};
  a = {5,0,1,2,3,4};
  cout << s.maxChunksToSorted(a) << endl;
  return 0;
}
