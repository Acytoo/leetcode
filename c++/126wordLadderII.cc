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
  vector<vector<string>> findLadders(string begin_word, string end_word,
                                     vector<string>& word_list) {
    unordered_set<string> dic(word_list.begin(), word_list.end());
    if (dic.find(end_word) == dic.end()) return {};  // end_word is not in the list
    // In case begin_word is in the list, we erase it, so there won't be unnecessary loops
    dic.erase(begin_word);
    int level = 0, word_len = begin_word.size();

    unordered_map<string, int> from_pos;
    from_pos[begin_word] = -1;

    queue<string> q;
    q.push(begin_word);

    unordered_map<string, int> levels{{begin_word, 1}};
    unordered_map<string, vector<string>> children;  // sub path for the former string
    bool end_word_found = false;

    while (!q.empty() && !end_word_found) {
      ++level;

      int level_items = q.size();
      for (int i=0; i<level_items; ++i) {
        string old_word = q.front();  // backup
        string new_word = old_word;
        q.pop();
        for (int pos=0; pos<word_len; ++pos) {
          if (pos == from_pos[old_word]) continue;  // Make the path move forward

          char old_char = old_word[pos];
          for (char c='a'; c<='z'; ++c) {
            if (old_char == c) continue;  // Change the word, skip the same word

            new_word[pos] = c;
            if (new_word == end_word || dic.find(new_word) != dic.end()) {
              levels[new_word] = level + 1;
              children[old_word].push_back(new_word);
              dic.erase(new_word);
              if (new_word == end_word) {
                end_word_found = true;
              } else {
                q.push(new_word);
                from_pos[new_word] = pos;
              }
            } else {
              auto it = levels.find(new_word);
              if (it != levels.end() && it->second == level+1) {
                // "new" word is already in the path
                children[old_word].push_back(new_word);
              }
            }
            new_word[pos] = old_char;  // Restore
          }
        }
      }
    }
    vector<vector<string>> res;
    if (end_word_found) {
      vector<string> path{begin_word};
      dfs(end_word, begin_word, children, path, res);
    }
    return res;
  }

 private:
  void dfs(const string& end_word, const string& cur_word,
           const unordered_map<string, vector<string>>& children,
           vector<string>& path,
           vector<vector<string>>& res) {
    if (cur_word == end_word) {
      res.push_back(vector<string>(path.begin(), path.end()));
      return;
    }
    auto it = children.find(cur_word);
    if (it != children.end()) {
      for (const string& word : it->second) {
        path.push_back(word);
        dfs(end_word, word, children, path, res);
        path.pop_back();
      }
    }
  }
};

int main() {
  Solution s;
  string beginWord = "hit",
           endWord = "cog";
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
  vector<vector<string>> res = s.findLadders(beginWord, endWord, wordList);
  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
