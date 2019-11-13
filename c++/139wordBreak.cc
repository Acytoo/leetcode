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

// DP improment
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int maxLen = 0;
    for (const string& word : wordDict)
      maxLen = max(maxLen, (int)word.size());

    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i=0; i <= n; ++i) {
      for (int j=i-1; max(0, i-maxLen) <= j; --j) {
        if (dp[j]) {
          const string sub = s.substr(j, i-j);
          if (wordSet.find(sub) != wordSet.end()) {
            dp[i] = true;
            // cout << i << endl;
            break;
          }
        }
      }
    }
    return dp[n];
  }
};

// DP
class Solution3 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i=0; i <= n; ++i) {
      for (int j=0; j <= i; ++j) {  // i=1, j=0
        if (dp[j]) {
          const string sub = s.substr(j, i-j);
          if (wordSet.find(sub) != wordSet.end()) {  // i=4
            dp[i] = true;
            // cout << i << endl;
            break;
          }
        }
      }
    }
    return dp[n];
  }
};


// Since the 1st solution time limit exceeded, we can use a map to memorize some already-checked substring.
class Solution2 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    unordered_map<string, bool> mem;
    return subBreak(s, wordSet, mem);
  }
 private:
  bool subBreak(const string& s, const unordered_set<string>& wordSet,
                unordered_map<string, bool>& mem) {
    // s(left part) is already checked
    auto it = mem.find(s);
    if (it != mem.end()) return it->second;  // true

    if (wordSet.find(s) != wordSet.end()) return mem[s] = true;

    for (int i=1, stop=s.size(); i < stop; ++i) {
      const string right = s.substr(i);

      if (wordSet.find(right) == wordSet.end()) continue;

      const string left = s.substr(0, i);
      if (subBreak(left, wordSet, mem)) return mem[s] = true;
    }

    return mem[s] = false;
  }
};


// Top down, insert breakpoint(s), check weather it's done
// Slow but easy to understand, Time Limit Exceeded...
class Solution1 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return subBreak(s, unordered_set<string>(wordDict.begin(), wordDict.end()));
  }

  bool subBreak(const string& s, const unordered_set<string>& wordSet) {
    // cout << s << endl;
    if (wordSet.find(s) != wordSet.end()) return true;

    for (int i=1, stop=s.size(); i < stop; ++i) {
      const string right = s.substr(i);
      if (wordSet.find(right) == wordSet.end()) continue;  // Next right part

      // Right part is in the dict, let's check left part
      const string left = s.substr(0, i);
      if (subBreak(left, wordSet)) return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  string str_s = "leetcodeleet";
  vector<string> vec_dict = {"leet", "code"};
  cout << s.wordBreak(str_s, vec_dict) << endl;
  // string test = "hello";
  // string res = test.substr(0, 0);
  // cout << test.find(res) << endl;
  // cout << "AdfaD" << endl;
  return 0;
}
