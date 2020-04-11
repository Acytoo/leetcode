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

// num = !num, 8ms
// num ^= 1, 8ms
// user-defined swap(), 12ms
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    const int n = A.size();
    for (auto &row: A) {
      int i = -1, j = n;
      while (++i < --j) {
        swap(row[i], row[j]);
        row[i] ^= 1; row[j] ^= 1;
      }
      if (i == j)
        row[i] ^= 1;
    }
    return A;
  }
 // private:
 //  static inline void swap(int &a, int &b) {
 //    a ^= b;
 //    b ^= a;
 //    a ^= b;
 //  }
};

int main() {
  Solution s;
  
  return 0;
}
