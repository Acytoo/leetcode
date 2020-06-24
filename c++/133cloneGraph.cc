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

/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> neighbors;

Node() {
val = 0;
neighbors = vector<Node*>();
}

Node(int _val) {
val = _val;
neighbors = vector<Node*>();
}

Node(int _val, vector<Node*> _neighbors) {
val = _val;
neighbors = _neighbors;
}
};
*/

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> m;
    function<Node*(Node*)> helper =
        [&] (Node* cur) {
          if (!cur) return (Node*)nullptr;
          if (m.count(cur)) return m[cur];
          Node *res = new Node (cur->val);
          m[cur] = res;
          for (Node *neighbor: cur->neighbors)
            res->neighbors.push_back(helper(neighbor));
          return res;
        };
    return helper(node);
  }
};

int main() {
  Solution s;
  
  return 0;
}
