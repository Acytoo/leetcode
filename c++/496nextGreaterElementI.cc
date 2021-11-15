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
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums2.size();
    unordered_map<int, int> m;
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && s.top() < nums2[i]) {
        m[s.top()] = nums2[i];
        s.pop();
      }
      s.push(nums2[i]);
    }
    vector<int> res;
    res.reserve(nums1.size());
    for (auto a : nums1)
      if (m.find(a) != m.end())
        res.emplace_back(m[a]);
      else
        res.emplace_back(-1);
    return res;
  }
};

class Solution_ORIGINAL {
  // adapted from leetcode 739 daily temperatures
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums2.size();
    unordered_map<int, int> m;
    vector<int> nxt(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      m[nums2[i]] = i;
      while (!s.empty() && nums2[s.top()] < nums2[i]) {
        nxt[s.top()] = nums2[i];
        s.pop();
      }
      s.push(i);
    }
    vector<int> res;
    res.reserve(nums1.size());
    for (const int a : nums1) res.emplace_back(nxt[m[a]]);
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
