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

// The number of nodes in the list is n.
// 1 <= k <= n <= 10^5 ????, the max n might be 9 x 10^5
// 0 <= Node.val <= 100
class Solution1 {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    int nums[100000];
    memset(nums, 0, sizeof nums);
    int i = -1;
    ListNode *res = head;
    while (head) {
      nums[++i] = head->val;
      head = head->next;
    }
    const int last_idx = i;
    swap(nums[k - 1], nums[i + 1 - k]);
    head = res;
    for (int i = 0; i <= last_idx; ++i) {
      head->val = nums[i];
      head = head->next;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
