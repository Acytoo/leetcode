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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= words.length <= 1000
// 1 <= words[i].length, chars.length <= 100
// All strings contain lowercase English letters only.
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int letters[26] = {0};
    for (char c: chars)
      ++letters[c-'a'];
    int res = 0;

    for (string word: words) {
      vector<int> tmp(letters, letters+26);
      int stop = word.size(), i = 0;
      for (; i<stop; ++i) {
        --tmp[word[i]-'a'];
        if (tmp[word[i]-'a']<0) break;
      }
      if (i>=stop)
        res += stop;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a= {"cat","bt","hat","tree"};
  string b = "atach";
  cout << s.countCharacters(a, b) << endl;
  return 0;
}
