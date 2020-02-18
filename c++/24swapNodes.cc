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
  ListNode* swapPairs(ListNode* head) {
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* pre = new_head;
    while (head && head->next) {
      pre->next = head->next;
      head->next = pre->next->next;
      pre->next->next = head;

      pre = head;
      head = head->next;
    }
    return new_head->next;
  }
};

int main() {
  Solution s;
  
  return 0;
}
