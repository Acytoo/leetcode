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
  vector<int> pancakeSort(vector<int>& A) {
    vector<int> res;
    for (int i = 0, n = A.size(), stop = n - 1; i < stop; ++i) {
      int len = max_element(A.begin(), A.end() - i) - A.begin() + 1;
      res.emplace_back(len);
      reverse(A.begin(), A.begin() + len);
      res.emplace_back(n - i);
      reverse(A.begin(), A.begin() + n - i);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
