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
  bool isTriangle(int a, int b, int c) {
    //a >= b >= c
    return (b+c > a) && (a-b < c);
  }

  int largestPerimeter(vector<int>& A) {
    int n = A.size();
    if (n < 3)
      return 0;
    sort(A.begin(), A.end());
    while (n-3 >= 0) {
      int a=A[n-1], b=A[n-2], c=A[n-3];
      if (isTriangle(a,b,c))
        return a+b+c;
      else
        --n;
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> a = {3,6,2,3};
  cout << s.largestPerimeter(a) << endl;
  return 0;
}
