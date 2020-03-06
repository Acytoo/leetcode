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
// a, b < c
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX, b = INT_MAX;
    for (const int c: nums) {
      if (c > b)
        return true;
      else if (c < a)
        a = c;
      else if (c > a && c < b)
        b = c;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}

//
