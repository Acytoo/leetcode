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
    int start = 1;
    while (start < n) {
      int mid = start + (n-start) / 2;
      if (!isBadVersion(mid))
	start = mid + 1;
      else n = mid;            
    }        
    return start;      
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
