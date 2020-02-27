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
  bool hasCycle(ListNode *head) {
    // double pointers
    ListNode *slow = head, *fast = head;
    while (fast) {
      if (!fast->next)
        return false;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
        return true;  // 只要有环，两个指针必有相遇的时候
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
