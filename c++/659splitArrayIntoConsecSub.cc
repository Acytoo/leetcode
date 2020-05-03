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

// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Greedy
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> supplies, need;
    for (const int num: nums) ++supplies[num];
    for (const int num: nums) {
      if (supplies[num] == 0) continue;

      --supplies[num];
      if (need[num]) {
        --need[num];
        ++need[num + 1];
      } else if (supplies[num + 1] && supplies[num + 2]) {
        --supplies[num + 1];
        --supplies[num + 2];
        ++need[num + 3];
      } else {
        return false;
      }
    }
    return true;
  }
};

class Solution1 {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> supplies, tail;
    for (const int num: nums) ++supplies[num];
    for (const int num: nums) {
      if (supplies[num] == 0) continue;

      --supplies[num];
      if (tail[num - 1]) {
        ++tail[num];
        --tail[num - 1];
      } else if (supplies[num + 1] && supplies[num + 2]) {
        --supplies[num + 1];
        --supplies[num + 2];
        ++tail[num + 2];
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3};
  cout << s.isPossible(a) << endl;
  return 0;
}
