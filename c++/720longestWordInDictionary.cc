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

using namespace std;
// Trie tree from leetcode 208
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Trie {
 public:
  Trie():root_(new TrieNode()) {}

  void insert(string word) {
    TrieNode *p = root_.get();
    for (const char c: word) {
      if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
      p = p->children[c-'a'];
    }
    p->is_word = true;
  }

  bool search(string word) const {
    const TrieNode *p = find(word);
    return p && p->is_word;
  }

 private:
  struct TrieNode {
    TrieNode(): is_word(false), children(26, nullptr) {}
    ~TrieNode() {
      for (TrieNode *child: children)
        if (child) delete child;
    }

    bool is_word;
    vector<TrieNode*> children;
  };

  const TrieNode* find(const string &prefix) const {
    const TrieNode *p = root_.get();
    for (const char c: prefix) {
      p = p->children[c-'a'];
      if (p == nullptr) break;
    }
    return p;
  }

  unique_ptr<TrieNode> root_;
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
                                       const int aa = a.size(), bb = b.size();
                                       return aa != bb? aa < bb : a < b;
                                     });
    int len = 1;
    Trie trie;
    vector<string> strs;
    for (const string &word: words) {
      int n = word.size();
      if (n == len) {
        if (n == 1 || trie.search(word.substr(0, n-1))) {
          if (!strs.empty() && strs.back().size() != n) strs.clear();
          strs.emplace_back(move(word));
          trie.insert(word);
        }
      } else if (n == ++len) {
        if (trie.search(word.substr(0, n-1))) {
          trie.insert(word);
          strs.clear();
          strs.emplace_back(move(word));
        }
      } else {
        break;
      }
    }
    return strs.empty()? "": strs.front();
  }
};

int main() {
  Solution s;
  
  return 0;
}
