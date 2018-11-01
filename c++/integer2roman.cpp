#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string res;
    while (num >= 1000) {
      res += "M";
      num -= 1000;
    }
    if (num > 899) {
      res += "CM";
      num -= 900;
    }
    if (num > 499) {
      res += "D";
      num -= 500;
    }
    if (num > 399) {
      res += "CD";
      num -= 400;
    }
    while (num > 99) {
      res += "C";
      num -= 100;
    }
    if (num > 89) {
      res += "XC";
      num -= 90;
    }
    if (num > 49) {
      res += "L";
      num -= 50;
    }
    if (num > 39) {
      res += "XL";
      num -= 40;
    }
    while (num > 9) {
      res += "X";
      num -= 10;
    }
    if (num > 8) {
      res += "IX";
      num -= 9;
    }
    if (num > 4) {
      res += "V";
      num -= 5;
    }
    if (num > 3) {
      res += "IV";
      num -= 4;
    }
    while (num > 0) {
      res += "I";
      num -= 1;
    }
    return res;
  }
};


int main() {
  int a = 900;
  Solution s;
  cout << s.intToRoman(a) << endl;
  return 0;
}
