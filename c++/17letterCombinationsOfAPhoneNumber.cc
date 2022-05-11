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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    const int n = digits.size();
    const vector<string> dict = {"", "", "abc", "def", "ghi",
      "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    function<void(string, int)> dfs = [&] (string cur, int i) {
      if (i == n) { res.push_back(cur); return; }
      const int idx = digits[i] - '0';
      for (const char c : dict[idx]) {
        dfs(cur + c, i + 1);
      }
    };
    dfs("", 0);
    return res;
  }
};

class Solution_OLD {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    unordered_map<char, string> dic = {
      {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
      {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> res;
    string cur;
    dfs(digits, dic, res, cur, 0);
    return res;
  }
  void dfs(const string& digits, const unordered_map<char, string>& dic,
           vector<string>& res, string& cur, int idx) {
    if (idx == digits.size()) {
      res.push_back(cur);
      return;
    }
    for (const char c: dic.at(digits.at(idx))) {
      cur.push_back(c);
      dfs(digits, dic, res, cur, idx+1);
      cur.pop_back();
    }
  }
};

int main() {
  Solution s;
  string a = "23";
  vector<string> res = s.letterCombinations(a);
  for (auto i : res) {
    cout << i << endl;
  }
  return 0;
}
