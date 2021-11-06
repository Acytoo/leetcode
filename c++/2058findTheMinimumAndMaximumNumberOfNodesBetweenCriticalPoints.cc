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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {  // o(n)
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> nums;
    for (ListNode *cur = head; cur; cur = cur->next)
      nums.emplace_back(cur->val);
    if (nums.size() < 3) return {-1, -1};
    vector<int> idxes;
    for (int i = 1, n = nums.size() - 1; i < n; ++i) {
      if (nums[i - 1] < nums[i]) {
        if (nums[i] > nums[i + 1]) idxes.emplace_back(i);
      } else if (nums[i - 1] > nums[i]) {
        if (nums[i] < nums[i + 1]) idxes.emplace_back(i);
      }
    }
    if (idxes.size() < 2) return {-1, -1};
    int minimum = INT_MAX;
    for (int i = idxes.size() - 1; i > 0; ) minimum = min(minimum, idxes[i] - idxes[--i]);
    return {minimum, idxes.back() - idxes.front()};
  }
};

int main() {
  Solution s;
  
  return 0;
}
