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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    vector<int> res;
    int i = arr1.size(), j = arr2.size(), carry = 0;
    while (i || j || carry) {
      int sum = (i? arr1[--i]: 0) + (j? arr2[--j]: 0) + carry;
      res.push_back(sum & 1);
      carry = - (sum >> 1);
    }
    while (res.back() == 0 && res.size() > 1) res.pop_back();
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
