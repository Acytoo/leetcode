#include <iostream>
#include <string>
using namespace std;
// unfinish yet
static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
class Solution{
public:
  string longestPalindrome(string s) {
    int maxLen = 0, tempLen = 0, n = s.size();
    if ( n < 2)
      return s;
    string res = "";
    for (int i=1; i < s.size(); i++) {
      if (s[i] == s[i-1]) {
	int pos = i, j = 0;
	int left = pos - j, right = pos + j;
	while (left > 0 && right < n && s[pos-j] == s[pos+j]) j++;
	if (j > maxLen) {
	  maxLen = j;
	  res = s.substring();
	}
      }
      else if (s[i-2] == s[i]) {}

    }
    return res;
  }
};

int main() {
  string a = "asdffdsa";
  Solution s;
  cout << s,longestPalindrome(a) << endl;
  return 0;
}
