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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

// For the worst solution ever, check my java version one year ago...Alec @ 2019.11.12
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(-1);
    ListNode* cur = res;
    int carry = 0;
    while (l1 || l2) {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(1);
    return res->next;
  }
};

int main() {
  Solution s;
  ListNode* a = new ListNode(2);
  ListNode* b = new ListNode(4);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(5);
  ListNode* e = new ListNode(6);
  ListNode* f = new ListNode(4);

  a->next = b;
  b->next = c;
  d->next = e;
  e->next = f;
  ListNode* res = s.addTwoNumbers(a, d);
  while (res->next) {
    cout << res->val << "->";
    res = res->next;
  }
  cout << res->val << endl;
  return 0;
}
