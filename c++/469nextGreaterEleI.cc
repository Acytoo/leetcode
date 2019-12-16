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
#include <set>
#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// O(n) solution from leetcode
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    for (int n: nums2) {
      while (!s.empty() && s.top() < n) {  //
        m[s.top()] = n;
        s.pop();
      }
      s.push(n);
    }

    vector<int> res;
    for (int n : nums1)
      res.push_back(m.count(n) ? m[n] : -1);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,5,9}, b = {2,1,3,4,5,6};
  vector<int> res = s.nextGreaterElement(a, b);
  for (auto i: res)
    cout << i << " ";
  cout << endl;
  return 0;
}
