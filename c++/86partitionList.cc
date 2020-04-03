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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode less (-1), grea (-1);
    ListNode *les = &less, *gre = &grea;

    while (head) {
      if (head->val < x) {
        les->next = head;
        les = les->next;
      } else {
        gre->next = head;
        gre = gre->next;
      }
      head = head->next;
    }
    les->next = grea.next;
    gre->next = nullptr;
    return less.next;
  }
};

int main() {
  Solution s;
  
  return 0;
}
