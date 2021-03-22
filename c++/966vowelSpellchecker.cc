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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    auto to_upper = [] (string &a) {
      for (char &c : a) if (c > 'Z') c ^= 32;
    };
    bitset<'Z' + 1> is_vowel;
    is_vowel['A'] = 1; is_vowel['E'] = 1; is_vowel['I'] = 1;
    is_vowel['O'] = 1; is_vowel['U'] = 1;
    auto replace_vowel = [&] (string &a) {
      for (char &c : a) if (is_vowel[c]) c = '*';
    };

    unordered_map<string, int> list;
    for (int i = 0, n = wordlist.size(); i < n; ++i) {
      string tmp = wordlist[i];
      list.emplace(tmp, i);
      to_upper(tmp);
      if (list.count(tmp) == 0) list.emplace(tmp, i);
      replace_vowel(tmp);
      if (list.count(tmp) == 0) list.emplace(tmp, i);
    }
    vector<string> res;
    res.reserve(queries.size());

    for (string &a : queries) {
      if (list.count(a)) {
        res.push_back(wordlist[list[a]]);
        continue;
      }
      to_upper(a);
      if (list.count(a)) {
        res.push_back(wordlist[list[a]]);
        continue;
      }
      replace_vowel(a);
      if (list.count(a)) {
        res.push_back(wordlist[list[a]]);
        continue;
      }
      res.push_back("");
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
