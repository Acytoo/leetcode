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


// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    Node dummy (-1);
    Node *cur = &dummy, *res = root;
    while (root) {
      if (root->left) {
        cur->next = root->left;
        cur = cur->next;
      }
      if (root->right) {
        cur->next = root->right;
        cur = cur->next;
      }
      root = root->next;
      if (!root) {
        cur = &dummy;
        root = dummy.next;
        dummy.next = nullptr;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
