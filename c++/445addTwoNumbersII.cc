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


// Definition for singly-linked list.
// We can traversing the list first, it's simple but tiring
// Using stack to store the two linked list, and when we pop them, they are at the right order
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }

    ListNode* res = new ListNode(-1);
    int carry = 0;
    while (!s1.empty() || !s2.empty()) {

      int n1 = s1.empty() ? 0 : s1.top();
      int n2 = s2.empty() ? 0 : s2.top();

      int sum = n1 + n2 + carry;
      carry = sum / 10;

      ListNode* tmp = new ListNode(sum % 10);
      tmp->next = res->next;
      res->next = tmp;
      if (!s1.empty()) s1.pop();
      if (!s2.empty()) s2.pop();
    }
    if (carry) {
      ListNode* tmp = new ListNode(1);
      tmp->next = res->next;
      res->next = tmp;
    }
    return res->next;
  }
};

int main() {
  Solution s;
  ListNode* o = new ListNode(7);
  ListNode* a = new ListNode(2);
  ListNode* b = new ListNode(4);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(5);
  ListNode* e = new ListNode(6);
  ListNode* f = new ListNode(4);
  o->next = a;
  a->next = b;
  b->next = c;
  d->next = e;
  e->next = f;
  ListNode* res = s.addTwoNumbers(o, d);
  while (res->next) {
    cout << res->val << "->";
    res = res->next;
  }
  cout << res->val << endl;
  return 0;
}
