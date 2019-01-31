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
//  many solutions
class Solution {
public:
  string toLowerCase(string str) {
    int x = 'a' - 'A';
    for (auto i = str.begin(), stop = str.end(); i != stop; ++i)
      if ('A' <= *i && 'Z' >= *i)
        *i = *i + x;
    return str;
  }
};
int main() {
  Solution s;
  string a = "asdAdfgBdfgCD";

  cout << s.toLowerCase(a) << endl;
  return 0;
}
