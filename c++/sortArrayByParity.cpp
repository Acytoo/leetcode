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
  vector<int> sortArrayByParity(vector<int>& A) {
    int j = A.size(), i = -1;
    vector<int> res(j);
    for (auto iter = A.begin(); iter != A.end(); ++iter) {
      if (*iter % 2 == 0) res[++i] = *iter;
      else res[--j] = *iter;
    }
    return res;
  }
};
// why Solution1 is faster ?????????
class Solution1 {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> even, odd;
    for (auto iter = A.begin(); iter != A.end(); ++iter) {
      if (*iter % 2 == 0) even.push_back(*iter);
      else odd.push_back(*iter);
    }
    even.insert(even.end(), odd.begin(), odd.end());
    return even;
  }
};

int main() {
  vector<int> a = {1,2,3,4,5,6,7};
  Solution s;
  vector<int>res = s.sortArrayByParity(a);
  for (auto iter = res.cbegin(); iter != res.cend(); ++iter)
    cout << *iter << " ";
  cout << endl;
  return 0;
}
