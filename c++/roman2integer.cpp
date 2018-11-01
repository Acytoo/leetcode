#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
  int roman_switch(char a) {
    if (a == 'I')
      return 1;
    if (a == 'V')
      return 5;
    if (a == 'X')
      return 10;
    if (a == 'L')
      return 50;
    if (a == 'C')
      return 100;
    if (a == 'D')
      return 500;
    return 1000;
  }
  int romanToInt(string s) {
    int res = 0, t1=1001, t2;
    for (int i=0; i < s.size(); i++) {
      t2 = roman_switch(s[i]);
      res += t2;
      if (t1 < t2) {
	res -= t1 << 1;
      }
      t1 = t2;
    }
    return res;
  }
};


int main() {
  Solution s;
  int res = s.romanToInt("MCMXCIV");
  cout << res << endl;
  

  return 0;
}
