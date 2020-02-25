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
  ListNode* oddEvenList(ListNode* head) {
    if (!head)
      return nullptr;
    ListNode* odd = head;
    ListNode* res = odd;
    ListNode* even = nullptr;
    if (head->next)
      even = head->next;
    else
      return res;
    head = head->next->next;
    ListNode* ress = even;

    while (head) {
      odd->next = head;
      odd = odd->next;
      head = head->next;
      if (head) {
        even->next = head;
        even = even->next;
        head = head->next;
      }
    }
    odd->next = ress;
    even->next = nullptr;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
