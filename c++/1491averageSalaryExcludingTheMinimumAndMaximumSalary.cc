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

// unique integers salary
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  double average(vector<int>& salary) {
    auto min_max = minmax_element(salary.begin(), salary.end());
    return (accumulate(salary.begin(), salary.end(), 0) - *min_max.first - *min_max.second) /
        (salary.size() - 2.0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
