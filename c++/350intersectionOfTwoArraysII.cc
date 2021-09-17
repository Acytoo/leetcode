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
class Solution {  // Follow up 2
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
    // Now nums1's size is no bigger than nums2
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    // Now array is sorted
    const int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;
    vector<int> res;
    res.reserve(min(m, n));
    for (i = 0; i < m && j < n; ++i) {
      if (nums1[i] < nums2[j]) continue;
      while (j < n && nums1[i] > nums2[j]) ++j;  // get next nums2 from disk if nums2 is two large for RAM
      if (nums1[i] == nums2[j]) {
        res.emplace_back(nums1[i]);
        ++j;
      }
    }
    return res;
  }
};

class Solution1 {  // Follow up 1
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
    // Now nums1's size is no bigger than nums2
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    // Now array is sorted
    const int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;
    vector<int> res;
    res.reserve(min(m, n));
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        ++i;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {
        res.emplace_back(nums1[i]);
        ++i;
        ++j;
      }
    }
    return res;
  }
};

class Solution_SAME_OLD {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // nums1's size is always smaller or equal than nums2' size
    // if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
    int occ1[1001];
    memset(occ1, 0, sizeof occ1);
    for (const int a : nums1) ++occ1[a];
    vector<int> res;
    for (const int a : nums2)
      if (--occ1[a] >= 0)
        res.emplace_back(a);
    return res;
  }
};

class Solution_OLD {
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
