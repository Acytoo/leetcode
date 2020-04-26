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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> sums;
    for (const int a: A)
      for (const int b: B)
        ++sums[a+b];
    int res = 0;
    for (const int c: C)
      for (const int d: D) {
        auto it = sums.find(-c - d);
        if (it != sums.end()) res += it->second;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
