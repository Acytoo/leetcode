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
class Solution {  // 204 ms
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int res = 0, last = -1;
    deque<int> odd_idx;
    for (int i = 0, stop = nums.size(); i < stop; ++i) {
      if (nums[i] & 1) odd_idx.push_back(i);
      if (odd_idx.size() > k) {  // odd_num = k + 1
        last = odd_idx.front();
        odd_idx.pop_front();
      }
      if (odd_idx.size() == k) res += odd_idx.front() - last;
    }
    return res;
  }
};

class Solution_same {  // 188 ms
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int res = 0, last = -1;
    deque<int> odd_idx;
    for (int i = 0, stop = nums.size(); i < stop; ++i) {
      if (nums[i] & 1) odd_idx.push_back(i);
      const int odd_num = odd_idx.size();
      if (odd_num > k) {  // odd_num = k + 1
        last = odd_idx.front();
        odd_idx.pop_front();
        res += odd_idx.front() - last;
      } else if (odd_num == k) {
        res += odd_idx.front() - last;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
