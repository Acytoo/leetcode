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
  vector<int> sortedSquares(vector<int>& A) {
    for (int &a: A) a = a * a;
    sort(A.begin(), A.end());
    return A;
  }
};

class Solution1 {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    for (auto iter = A.begin(), stop = A.end(); iter != stop; ++iter)
      *iter = (*iter) * (*iter);
    sort(A.begin(), A.end());
    return A;
  }
};

int main() {
  Solution s;
  vector<int> a = {-4, -2, 0, 1, 4, 8};
  s.sortedSquares(a);
  for (auto iter = a.begin(), stop = a.end(); iter != stop; ++iter)
    cout << *iter << " ";
  cout << endl;
  return 0;
}
