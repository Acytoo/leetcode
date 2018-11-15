#include <iostream>
#include <string>
using namespace std;

int main() {

  string a = "  a a a a  ",
  b = "||";
  cout << b << a << b;
  cout << endl << b << a.trip() << b << endl;
  return 0;
}
