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
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dic(wordList.begin(), wordList.end());
    if (dic.find(endWord) == dic.end()) return 0;

    int level = 0, wordLength = beginWord.size();
    unordered_map<string, int> fromPos;
    fromPos[beginWord] = -1;
    fromPos[endWord] = -1;
    unordered_set<string> front{beginWord};
    unordered_set<string> back{endWord};

    while (!front.empty() && !back.empty()) {
      ++level;
      if (front.size() > back.size()) swap(front, back);

      unordered_set<string> newFront;
      for (string word : front) {
        for (int i=0; i < wordLength; ++i) {
          if (i == fromPos[word]) continue;

          char originalChar = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;
            if (back.find(word) != back.end()) return level+1;

            // not find
            if (dic.find(word) == dic.end()) continue;

            fromPos[word] = i;

            dic.erase(word);
            newFront.insert(word);
          }
          word[i] = originalChar;
        }
        fromPos.erase(word);
      }
      swap(front, newFront);
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<string> str = {"hot","dot","dog","lot","log","cog"};
  int a = s.ladderLength("hit", "cog", str);
  cout << a << endl;
  return 0;
}
