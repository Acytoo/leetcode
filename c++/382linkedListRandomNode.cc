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
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    head_ = head;
    ListNode* cur = head;
    int n = 0;
    while (cur) {
      ++n;
      cur = cur->next;
    }
    n_ = n;
  }

  /** Returns a random node's value. */
  int getRandom() {
    int n = rand() % n_;
    ListNode* cur = head_;
    while (n-- > 0)
      cur = cur->next;
    return cur->val;
  }
 private:
  int n_;
  ListNode* head_;
};

int main() {
  Solution s;
  
  return 0;
}
