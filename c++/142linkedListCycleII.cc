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
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;
    ListNode *slow = head, *fast = head, *res = nullptr;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        res = head;
        while (slow != res) {
          slow = slow->next;
          res = res->next;
        }
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
