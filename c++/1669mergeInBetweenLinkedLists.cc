#include <iostream>
#include <sstream>
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
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode dummy(-1);
    ListNode *res = &dummy, *cur = &dummy;
    dummy.next = list1;
    b = b - a;
    while (a > 0) {
      cur = cur-> next;
      --a;
    }

    ListNode *l1 = cur->next;
    cur->next = list2;
    while (cur->next) cur = cur->next;
    while (b > 0) {
      l1 = l1->next;
      --b;
    }
    cur->next = l1->next;
    return dummy.next;
  }
};


int main() {
  Solution s;
  
  return 0;
}
