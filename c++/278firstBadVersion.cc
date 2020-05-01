#include <iostream>
using namespace std;

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
  return version > 4;
}
class Solution {
 public:
  int firstBadVersion(int n) {
    long l = 1;
    while (l < n) {
      int m = (l + n) >> 1;
      if (!isBadVersion(m))
        l = m + 1;
      else
        n = m;
    }
    return l;
  }
};

class Solution1 {
 public:
  int firstBadVersion(int n) {
    int i=1;
    while (isBadVersion(i++));
    return i;
  }
};


int main() {
  Solution s;
  cout << s.firstBadVersion(10) << endl;
  return 0;
}
