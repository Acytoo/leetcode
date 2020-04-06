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
  vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> res(A.size());
    int odd = 1, even = 0;
    for (auto iter = A.begin(), stop = A.end(); iter != stop; ++iter) {
      if (*iter % 2 == 0) {
        res[even] = *iter;
        even += 2;
      }
      else {
        res[odd] = *iter;
        odd += 2;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,4,6,2,3,7};
  vector<int> b = s.sortArrayByParityII(a);
  for (auto iter = b.begin(), stop = b.end(); iter != stop; ++iter)
    cout << *iter << " ";
  cout << endl;
  return 0;
}
