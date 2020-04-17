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
  int maximumProduct(vector<int>& nums) {
    int neg1 = INT_MAX, neg2 = INT_MAX, pos1 = INT_MIN, pos2 = INT_MIN, pos3 = INT_MIN;
    // neg may be a positive number and pos may be negative
    for (const int &num: nums) {
      if (num < neg2) {
        if (num < neg1) {
          neg2 = neg1;
          neg1 = num;
        } else {
          neg2 = num;
        }
      }
      if (pos3 < num) {
        if (pos1 < num) {
          pos3 = pos2;
          pos2 = pos1;
          pos1 = num;
        } else if (pos2 < num) {
          pos3 = pos2;
          pos2 = num;
        } else {
          pos3 = num;
        }
      }
    }
    int tmp = max(neg1*neg2, pos2*pos3);
    return tmp * pos1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
