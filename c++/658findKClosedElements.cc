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

using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    if (x < arr.front()) return {arr.begin(), arr.begin() + k};
    if (arr.back() < x) return {arr.end() - k, arr.end()};

    vector<int> res;
    auto it = upper_bound(arr.begin(), arr.end(), x);
    vector<int>::reverse_iterator rit (it);
    while (k--) {
      if (it == arr.end()) {
        res.push_back(*rit);
        ++rit;
        continue;
      }
      if (rit == arr.rend()) {
        res.push_back(*it);
        ++it;
        continue;
      }
      if (x-(*rit) <= (*it)-x) {
        res.push_back(*rit);
        ++rit;
      } else {
        res.push_back(*it);
        ++it;
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
