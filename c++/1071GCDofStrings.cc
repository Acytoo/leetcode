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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) swap(str1, str2);  // str2 is shorter

    const int l1 = str1.size(), l2 = str2.size();
    if (l2 == 0) return str1;

    for (int i=0; i<l2; ++i)
      if (str1[i] != str2[i])
        return "";
    return gcdOfStrings(str1.substr(l2, l1-l2), str2);
  }
};

int main() {
  Solution s;
  string a = "abcabc", b = "abc";
  a = "ababab", b = "ab";
  cout << s.gcdOfStrings(a, b) << endl;
  return 0;
}
