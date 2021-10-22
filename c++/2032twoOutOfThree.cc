#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // 30ms +
 public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    bitset<128> n1, n2, n3;
    auto helper = [&] (vector<int> &A, bitset<128> &n) { for (const int a : A) n[a] = true; };
    helper(nums1, n1);
    helper(nums2, n2);
    helper(nums3, n3);
    vector<int> res;
    for (int i = 0; i < 101; ++i)
      if (n1[i] + n2[i] + n3[i] >= 2)
        res.emplace_back(i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
