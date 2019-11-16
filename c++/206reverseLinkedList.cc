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


 // * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    stack<int> s;
    while (head) {
      s.push(head->val);
      head = head->next;
    }
    ListNode* par = new ListNode(-1);
    ListNode* res = par;
    while (!s.empty()) {
      ListNode* cur = new ListNode(s.top());
      s.pop();
      par->next = cur;
      par = par->next;
    }
    return res->next;
  }
};


class Solution1 {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* root = new ListNode(-1);
    while (head) {
      ListNode* tmp = new ListNode(head->val);
      tmp->next = root->next;
      root->next = tmp;
      head = head->next;
    }
    return root->next;
  }
};

int main() {
  Solution s;
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  ListNode* e = new ListNode(5);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  a = s.reverseList(a);
  while(a) {
    cout << a->val << "->";
    a = a->next;
  }
  cout << endl;
  delete a;
  delete b;
  delete c;
  delete d;
  delete e;

  return 0;
}
