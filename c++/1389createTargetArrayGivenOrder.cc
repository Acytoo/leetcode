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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();
    vector<int> res;
    res.reserve(n);
    for (int i=0; i<n; ++i)
      res.insert(res.begin()+index[i], nums[i]);
    return res;
  }
};

// memory limit exceeded
class Solution_MLE {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();
    vector<int> res;
    // ListNode dummy (-1);
    ListNode* head = new ListNode(-1);
    for (int i=0; i<n; ++i) {
      insertNode(head, index[i], nums[i]);
    }
    head = head->next;
    while (head) {
      res.push_back(head->val);
    }
    // delete head;
    return res;
  }
 private:
  void insertNode(ListNode* head, const int pos, const int val) {
    for (int i=0; i<pos; ++i)
      head = head->next;
    ListNode* cur = new ListNode(val);
    cur->next = head->next;
    head->next = cur;
  }
};

int main() {
  Solution s;
  
  return 0;
}
