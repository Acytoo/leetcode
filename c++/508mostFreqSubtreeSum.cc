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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root)
      return {};
    map<int, int> sums;
    vector<int> res;
    int max_freq = 0;
    getSums(root, sums, res, max_freq);
    return res;
  }
 private:
  int getSums(TreeNode* cur, map<int, int>& sums, vector<int>& res, int& max_freq) {
    if (!cur)
      return 0;
    int sum = cur->val + getSums(cur->left, sums, res, max_freq)
           + getSums(cur->right, sums, res, max_freq);
    int freq = ++sums[sum];
    if (max_freq < freq) {
      max_freq = freq;
      res.clear();
      res.push_back(sum);
    } else if (max_freq == freq) {
      res.push_back(sum);
    }
    return sum;
  }
};

int main() {
  Solution s;
  
  return 0;
}
