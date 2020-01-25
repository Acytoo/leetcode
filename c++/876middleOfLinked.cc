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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast->next != NULL)
      return slow->next;
    return slow;
  }
};

int main() {
  Solution s;
  
  return 0;
}
