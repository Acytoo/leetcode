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
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return ;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    stack<ListNode*> s;
    while (slow) {
      s.push(slow);
      slow= slow->next;
    }
    ListNode* new_head = head;
    while (!s.empty()) {
      ListNode* cur = s.top(); s.pop();
      cur->next = new_head->next;
      new_head->next = cur;
      new_head = new_head->next->next;
    }
    new_head->next = nullptr;
  }
};

int main() {
  Solution s;
  
  return 0;
}
