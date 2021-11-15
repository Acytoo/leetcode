#include <iostream>
#include <string>
using namespace std;

static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
class Solution{
 public:
  string longestPalindrome(string s) {
    const int n = s.size();
    int start = 0, len = 1;
    function<int(int, int)> palinLen = [&] (int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        ++r;
        --l;
      }
      return r - l - 1;
    };
    for (int i = 0; i < n; ++i) {
      int cur = max(palinLen(i, i), palinLen(i, i + 1));
      if (cur > len) {
        len = cur;
        start = i - (len - 1) / 2;
      }
    }
    return s.substr(start, len);
  }
};

int main() {
  string a = "asdffdsa";
  Solution s;
  cout << s,longestPalindrome(a) << endl;
  return 0;
}
