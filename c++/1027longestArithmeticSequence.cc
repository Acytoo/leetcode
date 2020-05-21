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
  int longestArithSeqLength(vector<int>& A) {
    const int n = A.size() - 1;
    unordered_set<int> s;
    for (const int a: A) s.insert(a);
    int res = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        int diff = A[j] - A[i], target = A[j] + diff, cur = 2;
        if (s.count(target) == 0) continue;
        for (int k = j + 1; k <= n; ++k) {
          if (A[k] == target) {
            ++cur;
            target += diff;
          }
        }
        res = max(res, cur);
      }
    return res;
  }
};

class Solution2 {  // slower than rest
 public:
  int longestArithSeqLength(vector<int>& A) {
    const int n = A.size() - 1;
    unordered_set<int> s;
    for (const int a: A) s.insert(a);
    int res = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        int diff = A[j] - A[i], target = A[j] + diff, cur = 2;
        if (s.count(target) == 0) continue;
        for (int k = j + 1; k <= n; ++k) {
          if (s.count(target) == 0) break;
          if (A[k] == target) {
            ++cur;
            target += diff;
          }
        }
        res = max(res, cur);
      }
    return res;
  }
};

class Solution1 {
 public:
  int longestArithSeqLength(vector<int>& A) {
    constexpr int kMaxA = 10000;
    bitset<kMaxA + 1> s;
    for (const int a: A) s[a] = 1;
    const int n = A.size() - 1;
    int res = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        const int diff = A[j] - A[i];
        int target = A[j] + diff, cur = 2;
        if (kMaxA < target || target < 0 || s[target] == 0) continue;
        for (int k = j + 1; k <= n; ++k) {
          if (target < 0 || kMaxA < target) break;
          if (A[k] == target) {
            ++cur;
            target += diff;
          }
        }
        res = max(res, cur);
      }
    return res;
  }
};

class Solution11 {
 public:
  int longestArithSeqLength(vector<int>& A) {
    constexpr int kMaxA = 10000;
    bitset<kMaxA + 1> s;
    for (const int a: A) s[a] = 1;
    const int n = A.size() - 1;
    int res = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        const int diff = A[j] - A[i];
        int target = A[j] + diff, cur = 2;
        if (kMaxA < target || target < 0 || s[target] == 0) continue;
        for (int k = j + 1; k <= n; ++k) {
          if (kMaxA < target || target < 0 || s[target] == 0) break;
          if (A[k] == target) {
            ++cur;
            target += diff;
          }
        }
        res = max(res, cur);
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
