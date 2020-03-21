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
#include <mutex>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head)
      return nullptr;
    unordered_map<Node*, Node*> m;  // old_node, new_node
    m.reserve(1000);
    Node* cur = new Node (head->val);
    m[head] = cur;
    Node* res = cur;
    while (head) {
      if (head->random) {
        auto it = m.find(head->random);
        if (it == m.end())
          // emplace: constructed in place, return pair of it and true;
          it = m.emplace(head->random, new Node (head->random->val)).first;
        cur->random = it->second;
      }

      if (head->next) {
        auto it = m.find(head->next);
        if (it == m.end())
          it = m.emplace(head->next, new Node (head->next->val)).first;
        cur->next = it->second;
      }

      head = head->next;
      cur = cur->next;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
