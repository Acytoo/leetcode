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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int l=0, r = A.size()-1, mid=0;
    while (l < r) {
      mid = (l + r) / 2;
      if (A[mid] < A[mid+1])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};


int main() {
  Solution s;
  
  return 0;
}
