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
class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary(): root_(new TrieNode()) {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode *p = root_.get();
    for (const char c: word) {
      if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
      p = p->children[c-'a'];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) const {
    const TrieNode *p = root_.get();
    return find(word, p, 0);
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

  const bool find(const string &word, const TrieNode *cur, int i) const {
    if (i == word.size()) return cur->is_word;
    if (word[i] == '.') {
      ++i;
      for (auto *child: cur->children)
        if (child && find(word, child, i)) return true;
    } else {
      int idx = word[i] - 'a';
      return cur->children[idx] && find(word, cur->children[idx], i+1);
    }
    return false;
  }
  unique_ptr<TrieNode> root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  WordDictionary w;
  // Solution s;
  
  return 0;
}
