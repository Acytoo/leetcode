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
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    res.reserve(min(nums1.size(), nums2.size()));
    unordered_map<int, int> m1;
    for (auto i: nums1) {
      auto it = m1.find(i);
      if (it == m1.end())        // not found
        m1[i] = 1;
      else
        ++(it->second);
    }
    for (auto i: nums2) {
      auto it = m1.find(i);
      if (it != m1.end()) {        // found
        res.push_back(i);
        if (it->second == 1) {m1.erase(it); continue;}
        --it->second;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1, 2, 2, 1}, b = {2, 2};
  vector<int> res = s.intersect(a, b);
  for (auto i: res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
