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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// One-pass
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy (-1);
    dummy.next = head;
    ListNode *pre = &dummy;
    for(int i=1; i<m; ++i) pre = pre->next;

    ListNode *bk = pre, *cur = pre->next, *tail = cur;
    for (int i=m; i<=n; ++i) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    bk->next = pre;
    tail->next = cur;
    return dummy.next;
  }
};

int main() {
  Solution s;
  
  return 0;
}
