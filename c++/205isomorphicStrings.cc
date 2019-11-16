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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

// Fantastic solution from leetcode
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> sMap(128, 0), tMap(128, 0);

    for (int i = 0; i < s.length(); ++i) {
      if (sMap[s[i]] != tMap[t[i]]) {
        return false;
      }

      sMap[s[i]] = i + 1;
      tMap[t[i]] = i + 1;
    }

    return true;
  }
};

class Solution1 {
 public:
  bool isIsomorphic(string s, string t) {
    map<char, char> to, from;
    for (int i=0, stop=s.size(); i<stop; ++i) {
      int record = to[s[i]-'a'];
      if (to.find(s[i]) != to.end()) {
        if (to[s[i]] != t[i])
          return false;
      } else {
        if (from.find(t[i]) != from.end()) {
          return false;
        } else {
          to[s[i]] = t[i];
          from[t[i]] = s[i];
        }
      }
    }
    return true;
  }
};


class Solution_for_alphabet_only {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> to(26, -1);
    vector<int> from(26, -1);
    for (int i=0, stop=s.size(); i<stop; ++i) {
      int record = to[s[i]-'a'];
      if (record >= 0) {  // Have a record
        if (t[i]-'a' != record)
          return false;
      } else {
        if (from[t[i]-'a'] >= 0) {
          return false;
        } else {  // New record
          to[s[i]-'a'] = t[i]-'a';
          from[t[i]-'a'] = s[i] - 'a';
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isIsomorphic("hello", "asdde") << endl;
  return 0;
}
