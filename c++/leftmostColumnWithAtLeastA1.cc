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

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
// 1 <= mat.length, mat[i].length <= 100
// mat[i][j] is either 0 or 1.
// mat[i] is sorted in a non-decreasing way.
// max 10000 cells, max 1000 calls
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> tmp = binaryMatrix.dimensions();
    const int m = tmp[0], n = tmp[1];
    tmp.clear();
    vector<int> rows;
    for (int i=0; i<m; ++i) rows.push_back(i);

    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      for (const int row: rows)
        if (binaryMatrix.get(row, mid))
          tmp.push_back(row);
      if (tmp.empty()) {
        l = mid + 1;
      } else {
        rows = tmp;
        tmp.clear();
        r = mid;
      }
    }
    return l==m? -1: l;
  }
};


int main() {
  Solution s;
  
  return 0;
}
