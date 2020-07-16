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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  Node* flatten(Node* head) {
    Node *cur = head;
    while (cur) {
      if (cur->child) {
        Node *next = cur->next;
        Node *last = cur->child;
        while (last->next) last = last->next;
        cur->next = cur->child;
        cur->next->prev = cur;
        cur->child = nullptr;
        last->next = next;
        if (next) next->prev = last;
      }
      cur = cur->next;
    }
    return head;
  }
};


int main() {
  Solution s;
  
  return 0;
}
