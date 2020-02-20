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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


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
// O(n log n), divide and conquer
// constant space
// merge sort, top down

class Solution{
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    int n = 1;
    ListNode* cur = head;
    while (cur = cur->next)
      ++n;
    ListNode dummy (-1);
    dummy.next = head;
    ListNode* l;
    ListNode* r;
    ListNode* tail;
    for (int i=1; i<n; i<<=1) {
      cur = dummy.next;
      tail = &dummy;
      while (cur) {
        l = cur;
        r = split(l, i);
        cur = split(r, i);
        auto merged = merge(l, r);
        tail->next = merged.first;
        tail = merged.second;
      }
    }
    return dummy.next;
  }
 private:
  ListNode* split(ListNode* head, int n) {
    while (--n && head)
      head = head->next;
    ListNode* rest = head? head->next: nullptr;
    if (head)
      head->next = nullptr;
    return rest;
  }
  pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
    ListNode dummy (-1);  // not new, so we don't need to delete it
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l2->val < l1->val)
        swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1? l1: l2;
    while (tail->next)
      tail = tail->next;
    return {dummy.next, tail};
  }
};

// STACK OVERFLOW ??? -> O(1) space
class Solution1 {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
  }
 private:
  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy (-1);  // not new, so we don't need to delete it
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l2->val < l1->val)
        swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;
    return dummy.next;
  }
};


int main() {
  Solution s;
  
  return 0;
}
