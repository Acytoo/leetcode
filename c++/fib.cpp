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

class Solution {
public:
  int fib(int N) {
    if (N <= 1)
      return N;
    int t1=0,t2=1,t3=0,i=2;
    while (i <= N) {
      t3 = t1 + t2;
      t1 = t2;
      t2 = t3;
      ++i;
    }
    return t3;
  }
};

int main() {
  Solution s;
  int a;
  while (cin >> a)
    cout << s.fib(a) << endl;
  return 0;
}
