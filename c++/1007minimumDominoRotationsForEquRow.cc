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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> cards (7);
    for (int i=0; i<n; ++i)
      if (A[i] != B[i]) {
        ++cards[A[i]];
        ++cards[B[i]];
      } else {
        ++cards[A[i]];
      }
    auto it = max_element(cards.begin(), cards.end());
    if (*it < n) return -1;
    int card = it - cards.begin(), a = 0, b = 0;
    for (int i=0; i<n; ++i) {
      if (A[i] != card) ++a;
      if (B[i] != card) ++b;
    }
    return min(a, b);
  }
};

int main() {
  Solution s;
  
  return 0;
}
