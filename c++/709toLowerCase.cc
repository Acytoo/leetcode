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
class Solution_ {
 public:
  string toLowerCase(string str) {
    const int diff = 'a' - 'A';
    for (char& c: str)
      if ('A'<=c && c<='Z')
        c += diff;
    return str;
  }
};

int main() {
  Solution s;
  string a = "asdAdfgBdfgCD";
  cout << s.toLowerCase(a) << endl;
  return 0;
}
