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
  string originalDigits(string s) {
    int letters[26] {0};
    int nums[10] {0};
    for (char c: s)
      ++letters[c-'a'];
    string res = "";
    nums[0] = letters['z'-'a'];
    nums[2] = letters['w'-'a'];
    nums[4] = letters['u'-'a'];
    nums[6] = letters['x'-'a'];
    nums[8] = letters['g'-'a'];
    nums[3] = letters['h'-'a'] - nums[8]; //letters['r'-'a'] - nums[0] - nums[4];
    nums[1] = letters['o'-'a'] - nums[0] - nums[2] - nums[4];
    nums[5] = letters['f'-'a'] - nums[4];
    nums[7] = letters['v'-'a'] - nums[5];
    nums[9] = letters['i'-'a'] - nums[8] - nums[6] - nums[5];
    for (int i=0; i<10; ++i)
      for (int j=0; j<nums[i]; ++j)
        res += (char) ('0'+i);
    return res;
  }
};

int main() {
  Solution s;
  string a = "zoenroe";
  cout << s.originalDigits(a) << endl;
  return 0;
}
