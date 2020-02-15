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

using namespace std;
// DFS O(n) = 2 ^ l (l is the number of letters in the given string)
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 'a' - 'A' = 32 = 2^5
class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    dfs(S, 0, res);
    return res;
  }
 private:
  void dfs(string& S, int idx, vector<string>& res) {
    if (idx == S.size()) {
      res.emplace_back(S);
      return;
    }
    dfs(S, idx+1, res);
    if (!isalpha(S[idx]))
      return;
    S[idx] ^= 32;
    dfs(S, idx+1, res);
    S[idx] ^= 32;
  }
};

int main() {
  Solution s;
  
  return 0;
}
