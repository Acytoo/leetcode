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
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> mem;
    return wordBreak(s, wordSet, mem);
  }
 private:
  vector<string> wordBreak(const string& s,
                           const unordered_set <string>& wordSet,
                           unordered_map<string, vector<string>>& mem) {
    auto p = mem.emplace(s, vector<string>());
    vector<string>& res = p.first->second;
    if (!p.second) return res;  // insert failed, already in map

    if (s.empty()) return {};  // insert success

    if (wordSet.find(s) != wordSet.end()) res.push_back(s);  // find s

    for (int i=1, stop=s.size(); i < stop; ++i) {
      const string right = s.substr(i);
      if (wordSet.find(right) == wordSet.end()) continue;

      const string left = s.substr(0, i);
      const vector<string>& leftRes = wordBreak(left, wordSet, mem);

      for (const string& lres : leftRes) {
        res.push_back(lres+" "+right);
      }
    }
    return res;
  }
};


int main() {
  Solution solu;
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  for (auto i : solu.wordBreak(s, wordDict))
    cout << i << endl;
  return 0;
}
