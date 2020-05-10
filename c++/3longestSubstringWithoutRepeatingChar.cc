#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max = 0, start = 1, temp = 0,  pos[128] = {0};
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      if (pos[s[i]] < start) {
        pos[s[i]] = i + 1;
        temp = i + 2 - start;
        max = max > temp ? max : temp;
      } else {
        start = pos[s[i]] + 1;
        pos[s[i]] = i + 1;
      }
    }
    return max;
  }
};

int main() {
  string a = " ";
  Solution s;
  cout << s.lengthOfLongestSubstring(a) << endl;
  return 0;
}
