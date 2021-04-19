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

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // if (!head || !n) return nullptr;  // sz >= 1 && n >= 1
    ListNode *fast = head, *slow = head, *res = head;
    while (n-- > 0) fast = fast->next;  // n <= sz
    if (!fast) return head->next;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
