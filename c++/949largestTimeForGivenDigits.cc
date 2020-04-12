#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // 84ms ...
 public:
  string largestTimeFromDigits(vector<int>& A) {
    vector<int> bk ('9'+1);
    for (const int d: A) ++bk[d+'0'];

    function<bool(char*)> same =
        [&] (char *a) {
          vector<int> digits (bk);
          --digits[a[0]];
          --digits[a[1]];
          --digits[a[3]];
          --digits[a[4]];
          return (digits[a[0]]==0 && digits[a[1]]==0 &&
                  digits[a[3]]==0 && digits[a[4]]==0);
        };
    for (int h = 23; h>=0; --h)
      for (int m = 59; m>=0; --m) {
        char tmp [6] = {0};
        sprintf(tmp, "%02d:%02d", h, m);
        if (same(tmp))
          return string (tmp);
      }
    return "";
  }
};

class Solution1 {  // modified from leetcode sample 0ms answer
 public:
  string largestTimeFromDigits(vector<int>& A) {
    string ans = "";
    sort(A.begin(), A.end());
    do {
      if ((A[0]==2 && A[1]<=3 || A[0]<2) && A[2]<=5) {
        string temp = to_string(A[0]) + to_string(A[1]) + ":"
                      +to_string(A[2]) + to_string(A[3]);
        if (temp > ans) ans = temp;
      }
    } while (next_permutation(A.begin(), A.end()));
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> a = {0,0,0,0};
  cout << s.largestTimeFromDigits(a) << endl;
  return 0;
}
