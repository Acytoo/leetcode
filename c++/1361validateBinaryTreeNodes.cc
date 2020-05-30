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

// in-degree and out-degree
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<int> in (n), out (n);
    for (int i = 0; i < n; ++i)
      if (leftChild[i] >= 0) {
        ++in[leftChild[i]];
        ++out[i];
      }
    for (int i = 0; i < n; ++i)
      if (rightChild[i] >= 0) {
        ++in[rightChild[i]];
        ++out[i];
      }
    int root = 0, root_idx = -1;
    for (int i = 0; i < n; ++i)
      if (in[i] > 1) {
        return false;
      } else if (in[i] == 0) {
        ++root;
        root_idx = i;
      }
    return root == 1 && (n == 1 || out[root_idx] > 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
