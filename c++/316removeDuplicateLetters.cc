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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string res = "";
    int dic[26] = {0};
    bool used[26] = {false};
    for (char c: s)
      ++dic[c - 'a'];
    for (char c: s) {
      int cc = c - 'a';
      --dic[cc];
      if (res.empty()) {
        res.push_back(c);
        used[cc] = true;
        continue;
      }
      if (used[cc])
        continue;
      while (!res.empty() && c < res.back() && dic[res.back() - 'a'] > 0) {
        used[res.back() - 'a'] = false;
        res.pop_back();
      }
      res.push_back(c);
      used[cc] = true;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
