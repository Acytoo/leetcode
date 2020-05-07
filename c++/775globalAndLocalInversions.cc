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
// From grandyang
class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = 0, stop = A.size(); i < stop; ++i)
      if (!(A[i] == i || A[i] == i + 1 || A[i] + 1 == i))
        return false;
    return true;
  }
};

// From grandyang
class Solution2 {
 public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = 0, stop = A.size(); i < stop; ++i)
      if (abs(A[i] - i) > 1) return false;
    return true;
  }
};

class Solution1 {
 public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = A.size() - 1, m = A.back(); i >= 2; --i) {
      if (A[i] < m) m = A[i];
      if (m < A[i - 2]) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
