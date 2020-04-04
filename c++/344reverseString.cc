#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = -1, r = s.size();
    while (++l < --r) {
      s[l] ^= s[r];
      s[r] ^= s[l];
      s[l] ^= s[r];
    }
  }
};


// Back in 2018 this question's parameter is string, and we need to return a string
// Now it's parameter is a vector of char, and no return value
class Solution_OLD {
 public:
  string reverseString(string s) {
    int front=0, tail=s.size()-1;
    while (front < tail) {
      swap(s[front], s[tail]);
      ++front;
      --tail;
    }
    return s;
  }
};

int main() {
  string a = "12345";
  Solution s;
  cout << s.reverseString(a) << endl;

  return 0;
}
