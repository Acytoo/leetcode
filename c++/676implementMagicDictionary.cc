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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class MagicDictionary {
 public:
  /** Initialize your data structure here. */
  MagicDictionary() {
    // m_.clear();
  }
    
  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    m_.clear();
    for (const string &word: dict) {
      if (m_.find(word.size()) == m_.end())
        m_[word.size()] = {};
      m_[word.size()].emplace_back(move(word));
    }
  }
    
  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    const int kLen = word.size();
    auto it = m_.find(kLen);
    if (it == m_.end()) return false;
    for (const string& str: it->second) {
      int diff = 0;
      for (int i=0; i<kLen; ++i) {
        if (str[i] != word[i]) ++diff;
        if (diff > 1) break;
      }
      if (diff == 1) return true;
    }
    return false;
  }
 private:
  unordered_map<int, vector<string>> m_;  // length -> strings
};

int main() {
  MagicDictionary m;
  vector<string> a = {"ab", "abc", "ert", "yui"};
  m.buildDict(a);
  cout << m.search("yup") << endl;
  return 0;
}
