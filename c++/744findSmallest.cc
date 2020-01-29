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

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    bool dic[26] {false};
    for (char c: letters)
      dic[c-'a'] = true;
    for (int i=target-'a'+1; i<26; ++i)
      if (dic[i])
        return (char) (i+'a');
    for (int i=0; i<target; ++i)
      if (dic[i])
        return (char) (i+'a');
    return ' ';
  }
};

int main() {
  Solution s;
  
  return 0;
}
