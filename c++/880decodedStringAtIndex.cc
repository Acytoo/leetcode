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
class Solution {
 public:
  string decodeAtIndex(string S, int K) {
    long i = 0, n = 0;
    for (; n < K; ++i)
      n = S[i] <= '9'? n * (S[i] - '0'): (n + 1);

    while (i--)
      if (S[i] <= '9') {
        n /= (S[i] - '0');
        K %= n;
      } else {
        if (K % n == 0) return string(1, S[i]);
        --n;
      }
    return "";
  }
};

class Solution_TLEMLE {
 public:
  string decodeAtIndex(string S, int K) {
    string de = "";
    int idx = -1;
    const int n = S.size();

    while (++idx < n) {
      if (de.size() >= K)
        return de.substr(K - 1, 1);

      if (S[idx] <= '9') {
        int tmp = S[idx] - '0';
        string bk (de);
        while (--tmp && de.size() < K) de += bk;
        if (de.size() >= K)
          return de.substr(K - 1, 1);
      } else {
        de += S[idx];
      }
    }
    if (de.size() >= K)
      return de.substr(K - 1, 1);
    return "";
  }
};

int main() {
  Solution s;
  
  return 0;
}
