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
//1 <= pieces.length <= arr.length <= 100
//sum(pieces[i].length) == arr.length
//1 <= pieces[i].length <= arr.length
//1 <= arr[i], pieces[i][j] <= 100

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    const int n = arr.size(), nn = pieces.size();
    int i = 0;
    while (i < n) {
      int ii = 0;
      while (ii < nn) {
        auto &piece = pieces[ii];
        if (piece[0] == arr[i]) {
          for (int j = 1, stopj = piece.size(); j < stopj; ++j)
            if (piece[j] != arr[++i]) return false;
          break;
        }
        ++ii;
      }
      if (ii == nn) return false;
      ++i;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
