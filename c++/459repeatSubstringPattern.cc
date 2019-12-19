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
#include <set>
#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    s_ = s;
    length_ = s.size();
    max_len_ = length_ / 2;

    if (length_ == 1) return false;
    char last = s[length_-1];
    for (int i=0; i<max_len_; ++i)
      if (last == s[i])
        if (checkPattern(i))
          return true;
    return false;
  }
 private:
  bool checkPattern(int pos) {
    cout << "pos " << pos << endl;
    if (length_ % ++pos != 0)
      return false;
    int n = length_ / pos;
    const string pattern = s_.substr(0, pos);
    int stop = length_ - pos;
    int base = pos;
    while (base <= stop) {
      string tmp = s_.substr(base, pos);
      cout << "tmp " << tmp << endl;
      if (pattern != tmp)
        return false;
      base += pos;
    }
    return true;
  }

  string s_;
  int length_;
  int max_len_;
};

int main() {
  Solution s;
  string a = "ababba";
  cout << s.repeatedSubstringPattern(a) << endl;
  return 0;
}
