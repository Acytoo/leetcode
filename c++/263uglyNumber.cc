#include <iostream>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 15 == 0) num /= 15;
    while (num % 10 == 0) num /= 10;
    while (num % 6 == 0) num /= 6;
    while (num % 5 == 0) num /= 5;
    while (num % 3 == 0) num /= 3;
    while (num % 2 == 0) num /= 2;
    return num == 1;
  }
};

int main() {
  Solution s;
  cout << s.isUgly(9) << endl;
  return 0;
}
