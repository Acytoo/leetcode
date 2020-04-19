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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From Huahua
class Trie {
 public:
  /** Initialize your data structure here. */
  Trie():root_(new TrieNode()) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *p = root_.get();
    for (const char c: word) {
      if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
      p = p->children[c-'a'];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) const {
    const TrieNode *p = find(word);
    return p && p->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    return find(prefix) != nullptr;
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

int main() {
  // Solution s;
  Trie t;
  
  return 0;
}
