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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy (-1);
    dummy.next = head;
    bool changed = false;
    do {
      int sum = 0;
      ListNode *cur = dummy.next;
      unordered_map<int, ListNode*> m = {{0, &dummy}};
      while (cur) {
        changed = false;
        sum += cur->val;
        if (m.count(sum)) {
          m[sum]->next = cur->next;
          changed = true;
          break;
        } else {
          m[sum] = cur;
        }
        cur = cur->next;
      }
    } while (changed && dummy.next);
    return dummy.next;
  }
};

int main() {
  Solution s;
  // [1,3,2,-3,-2,5,5,-5,1]
  return 0;
}
