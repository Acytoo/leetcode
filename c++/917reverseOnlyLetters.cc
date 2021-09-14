#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (!isalpha(s[l])) {
        ++l;
      } else if (!isalpha(s[r])) {
        --r;
      } else {
        swap(s[l], s[r]);
        ++l; --r;
      }
    }
    return s;
  }
};

class Solution_Slow {
 public:
  string reverseOnlyLetters(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalpha(s[l])) ++l;
      while (l < r && !isalpha(s[r])) --r;
      if (l >= r) break;
      swap(s[l], s[r]);
      ++l; --r;
    }
    return s;
  }
};

class Solution_OLD_AND_WRONG {
  // passed in 2019 and wa now
 public:
  bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  string reverseOnlyLetters(string S) {
    int i=0, j=S.size()-1;

    while (i < j) {
      while (!isLetter(S[i])) ++i;
      while (!isLetter(S[j])) --j;
      if (i > j)
        break;
      //cout << S[i] << " " << S[j] << endl << i << " " << j << endl;
      swap(S[j], S[i]);
      ++i;
      --j;
    }
    return S;
  }
};

int main() {
  Solution s;
  string a = "?6C40E";
  cout << s.reverseOnlyLetters(a) << endl;
  return 0;
}
