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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy (-1);
    dummy.next = head;
    int len = 0;
    while (head) {
      ++len;
      head = head->next;
    }
    ListNode *pre = &dummy;
    for (int l = 0, stop = len - k; l <= stop; l += k) {
      ListNode *cur = pre->next;
      ListNode *nxt = cur->next;
      for (int i = 1; i < k; ++i) {
        cur->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;
        nxt = cur->next;
      }
      pre = cur;
    }
    return dummy.next;
  }
};

class Solution___ {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    vector<ListNode*> vNodes;
    ListNode *cur = head;
    while (cur) {
      vNodes.push_back(cur);
      cur = cur->next;
    }
    const int n = vNodes.size();
    int turns = n / k;
    ListNode dummy (-1);
    if (turns == 1)
      cur = &dummy;
    else
      // ... shit code...

    while (turns > 0) {
      --turns;
      for (int r = turns * k, l = r - k; r > l; --r) {
        vNodes[r]->next = vNodes[r - 1];
      }
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
