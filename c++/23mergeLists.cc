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
// From: Huahua
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size()-1);
  }
 private:
  ListNode* merge(vector<ListNode*>& lists, int l, int r) {
    if (r < l)
      return nullptr;
    if (l == r)
      return lists[l];
    if (l+1 == r)
      return mergeTwoLists(lists[l], lists[r]);
    int m = (l+r) >> 1;
    ListNode* ll = merge(lists, l, m);
    ListNode* lr = merge(lists, m+1, r);
    return mergeTwoLists(ll, lr);
  }
  ListNode* mergeTwoLists(ListNode* l, ListNode* r) {
    ListNode dummy(-1);
    ListNode* tail = &dummy;
    while (l && r) {
      if (l->val < r->val)
        swap(l, r);
      tail->next = r;
      r = r->next;
      tail  = tail->next;
    }
    if (l)
      tail->next = l;
    if (r)
      tail->next = r;
    return dummy.next;
  }
};

int main() {
  Solution s;
  
  return 0;
}
