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
  vector<int> findErrorNums(vector<int>& nums) {
    bitset<10001> occs;
    const int n = nums.size();
    vector<int> res;
    for (auto a : nums)
      if (occs[a])
        res.push_back(a);
      else
        occs[a] = 1;
    for (int i = 1; i <= n; ++i)
      if (!occs[i])
        res.push_back(i);
    return res;
  }
};


class Solution_old {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    bool flag[++n] = {0};
    vector<int> res(2);
    for (int i : nums) {
      if (flag[i])
        res[0] = i;
      flag[i] = true;
    }
    for (int i=1; i != n; ++i)
      if (!flag[i]) {
        res[1] = i;
        break;
      }
    return res;
  }
};

class Solution1 {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    set<int> mySet;
    pair<set<int>::iterator, bool> ret;
    int dup = 0, sum = 0, n = nums.size();
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
      ret = mySet.insert(*iter);
      sum += *iter;
      if (!ret.second)
        dup = *iter;
    }
    return {dup, (1+n)*n/2 - sum + dup};
  }
};

int main() {
  Solution s;
  vector<int> a = {1,1};
  vector<int>res = s.findErrorNums(a);
  cout << res[0] << " " << res[1] << endl;;
  return 0;
}
