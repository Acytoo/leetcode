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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From Huahua
class Solution {
 public:
  string pushDominoes(string dominoes) {
    const int n = dominoes.size();
    vector<int> L(n, INT_MAX), R(L);
    for (int i = 0; i < n; ++i)
      if (dominoes[i] == 'L') {
        L[i] = 0;
        for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j)
          L[j] = L[j + 1] + 1;
      } else if (dominoes[i] == 'R') {
        R[i] = 0;
        for (int j = i + 1; j < n && dominoes[j] == '.'; ++j)
          R[j]  = R[j - 1] + 1;
      }
    for (int i = 0; i < n; ++i)
      if (L[i] < R[i])
        dominoes[i] = 'L';
      else if (R[i] < L[i])
        dominoes[i] = 'R';
    return dominoes;
  }
};

int main() {
  Solution s;
  
  return 0;
}
