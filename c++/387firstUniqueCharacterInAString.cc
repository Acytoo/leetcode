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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> chars('z'+1);
    for (const char& c : s) ++chars[c];
    for (int i=0, stop=s.size(); i<stop; ++i)
      if (chars[s[i]] == 1) return i;
    return -1;
  }
};

class Solution1 {
public:
  int firstUniqChar(string s) {
    vector<int> chars(26, 0);
    for (const char& c : s) {
      ++chars[c-'a'];
    }
    for (int i=0, stop=s.size(); i<stop; ++i) {
      if (chars[s[i]-'a'] == 1)
        return i;
    }
    return -1;
  }
};

int main() {
  Solution s;
  string a = "leetcodeleet";
  cout << s.firstUniqChar(a) << endl;
  return 0;
}
