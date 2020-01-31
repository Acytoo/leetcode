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
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> res;
    if (!root)
      return res;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      Node* cur = s.top();
      s.pop();
      res.push_back(cur->val);
      for (int i=cur->children.size()-1; 0<=i; --i)
        s.push(cur->children[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
