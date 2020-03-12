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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> res (k, nullptr);
    int n = 0;
    ListNode* cur = root;
    while (cur) {
      ++n;
      cur = cur->next;
    }
    int l = n / k, r = n % k;
    cur = root;
    ListNode* pre = nullptr;
    for (int i=0; i<k; ++i,--r) {
      res[i] = cur;
      for (int j=0, stop=l+(r>0); j<stop; ++j) {
        pre = cur;
        cur = cur->next;
      }
      if (pre)
        pre->next = nullptr;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
