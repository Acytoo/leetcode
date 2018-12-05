#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  bool validMountainArray(vector<int>& A) {
    int n = A.size();
    if (n <= 2)
      return false;
    if (A[1] < A[0])
      return false;
    auto iter = A.begin();
    while (*iter < *++iter);
    if (iter == A.end())
      return false;
    while (*iter > *++iter);
    if (iter != A.end())
      return false;
    return true;
  }
};

int main() {
  vector<int> a = {3,6,5};
  Solution s;
  cout << s.validMountainArray(a) << endl;
  return 0;
}
