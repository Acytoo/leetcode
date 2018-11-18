#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
  int a = 12145343;
  int b = -456;
  int res = INT_MIN ^ INT_MIN;
  //  bool res = aa^b > 0 ? true : false;
  cout << res << endl;
  cout << INT_MIN << endl;
  return 0;
}
