#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string reverseString(string s) {
    int front=0, tail=s.size()-1;
    while (front < tail) {
      swap(s[front], s[tail]);
      front++;
      tail--;
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
