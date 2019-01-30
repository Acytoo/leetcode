#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
  //https://leetcode.com/problems/minimum-increment-to-make-array-unique/solution/
public:
  int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());
    int ans = 0, taken = 0, length = A.size();
    if (length <= 1)
      return 0;
    for (int i = 1; i != length; ++i) {
      if (A[i-1] == A[i]) {
        taken++;
        ans -= A[i];
      }
      else {
        int give = min(taken, A[i] - A[i-1] - 1);
        ans += give * (give + 1) / 2 + give * A[i-1];
        taken -= give;
      }
    }
    if (length  > 0)
      ans += taken * (taken + 1) / 2 + taken * A[length - 1];

    return ans;
  }
};

class Solution0 {
public:
  int minIncrementForUnique(vector<int>& A) {
    int stop = A.size();
    if (stop <= 1)
      return 0;
    int res=0, cnt[40004], cur=-1;
    memset(cnt,0,sizeof(cnt));

    for (int i=0; i != stop); ++i)
      cnt[A[i]]++;

    for (int i=0; i<40004; i++) {
      if (cnt[i]==0) continue;
      int big;
      res += (cnt[i]-1) * (cnt[i])/2;
      big = i+cnt[i]-1;
      if (i <= cur) {
        res += (cur+1-i) * cnt[i];
        big += cur - i + 1;
        }
      cur=big;
      }
    return res;
  }
};

// Time limitation
class Solution1 {
public:
  int minIncrementForUnique(vector<int>& A) {
    set<int> mySet;
    pair<set<int>::iterator, bool> ret;
    int res = 0, num = 0;
    for (auto iter = A.cbegin(); iter != A.cend(); iter++) {
      num = *iter;
      ret = mySet.insert(num);
      while (ret.second == false) {
	ret = mySet.insert(++num);
	res++;
      }
    }
    return res;
  }
};

int main() {
  vector<int> a = {0};
  Solution1 s;
  cout << s.minIncrementForUnique(a) << endl;
  return 0;
}
