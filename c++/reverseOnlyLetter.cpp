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
