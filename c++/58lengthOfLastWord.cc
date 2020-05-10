#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int num = 0, tail = s.size() - 1;
    while (s[tail] == ' ') --tail;

    if (tail == -1) return 0;
    for (; s[tail] != ' '; --tail) {
      ++num;
      if (tail == 0) return num;
    }
    return num;
  }
};

int main() {
  Solution s;
  string a = "a  afd  ";
  cout << s.lengthOfLastWord(a) << endl;
  return 0;
}
