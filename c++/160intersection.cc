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
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
      p = p != nullptr ? p->next: headB;
      q = q != nullptr ? q->next: headA;
    }
    return p;
  }
};

int main() {
  Solution s;
  
  return 0;
}
