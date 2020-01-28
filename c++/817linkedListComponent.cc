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
  int numComponents(ListNode* head, vector<int>& G) {
    int res = 0;
    bool has[10000] {false};
    for (int i: G)
      has[i] = true;

    while (head) {
      if (has[head->val]) {
        ++res;
        while(head && has[head->val]) head = head->next;
      } else {
        head = head->next;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
