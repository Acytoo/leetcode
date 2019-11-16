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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<int> nums(n, 1);
    int count{1};
    for(int i = 3; i < n; i=i+2) {
      if(nums[i]) {
        ++count;
        for(int j = 2; i * j < n; ++j) {
          nums[i * j] = 0;
        }
      }
    }
    return count;
  }
};



int main() {
  Solution s;
  
  return 0;
}
