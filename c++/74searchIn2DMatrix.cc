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
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0)
      return false;
    int n = matrix[0].size();
    if (n == 0)
      return false;
    if (target < matrix[0][0] || target > matrix[m-1][n-1])
      return false;
    // binary search in row first
    int l = 0, r = m-1, mid = 0;
    if (target < matrix[m-1][0]) {
      while (l <= r) {
        mid = (l+r) >> 1;
        if (target >= matrix[mid][0] && target < matrix[mid+1][0])
          break;
        if (target < matrix[mid][0])
          r = mid - 1;
        else
          l = mid + 1;
      }
    } else {
      mid = m-1;
    }
    // col
    int row = mid;
    // cout << row << endl;
    l = 0, r = n-1;
    while (l <= r) {
      mid = (l+r) >> 1;
      if (matrix[row][mid] == target)
        return true;
      if (matrix[row][mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
