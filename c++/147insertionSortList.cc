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
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy (INT_MIN);
    ListNode *tail = &dummy;
    while (head) {
      if (head->val >= tail->val) {
        tail->next = head;
        head = head->next;
        tail = tail->next;
        tail->next = nullptr;
        continue;
      }
      ListNode *cur = dummy.next, *pre = &dummy, *bk = head;
      head = head->next;
      while (cur->val < bk->val) {
        pre = cur;
        cur = cur->next;
      }
      pre->next = bk;
      bk->next = cur;
    }
    return dummy.next;
  }
};

int main() {
  Solution s;
  
  return 0;
}
