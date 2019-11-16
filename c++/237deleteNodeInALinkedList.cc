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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  void deleteNode(ListNode* node) {
    // while (node->next->next) {
    //     node->val = node->next->val;
    //     node = node->next;
    // }
    // node->val = node->next->val;
    // node->next = nullptr;
    node->val = node->next->val;
    ListNode* del_me = node->next;
    node->next = node->next->next;
    delete del_me;
  }
};

int main() {
  Solution s;
  
  return 0;
}
