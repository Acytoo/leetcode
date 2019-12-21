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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// fast solution from leetcode
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    int N = 0;
    for (ListNode* start = head;start;start = start->next) N++;  // 1 *
    if (N<2) return true;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = head->next;
    // reverse the front half
    for (int i=1;true;i++) {
      curr->next = prev;
      if (i==N/2) break;
      prev = curr;
      curr = next;
      next = curr->next;
    }
    if (N%2) next = next->next;
    for (;curr;curr = curr->next,next = next->next)
      if (curr->val!=next->val) return false;
    return true;
  }
};

class Solution1 {
 public:
  bool isPalindrome(ListNode* head) {
    vector<int> tmp;
    tmp.reserve(2000);
    long n=0;
    while (head != NULL) {
      ++n;
      tmp.emplace_back(move(head->val));
      head = head->next;
    }

    long mid = n / 2;
    for (long i=0, tail=n-1; i<mid; ++i, --tail) {
      if (tmp[i] != tmp[tail])
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
