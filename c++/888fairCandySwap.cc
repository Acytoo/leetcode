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
#include <numeric>

using namespace std;

// 1 <= A.length <= 10000
//                  1 <= B.length <= 10000
//                                   1 <= A[i] <= 100000
//                                                1 <= B[i] <= 100000

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// The sum of their candies must bve even
// Res is the diff-num of their bars
class Solution {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    // vector<int> res(2, 1);
    int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2; // The two sum must be even
    unordered_set<int> dict(A.begin(), A.end()); // Hashtable
    for (const int& num : B) {
      if (dict.count(num + diff)) return {num + diff, num}; // There is a bar Bob has that is exactly what we want
    }
    return {};

  }
};

int main() {
  Solution s;
  vector<int>  a = {1, 1}, b = {2, 2};
  vector<int> res = s.fairCandySwap(a, b);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
