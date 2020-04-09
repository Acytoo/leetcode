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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool validPalindrome(string s) {
    int l = 0, r = s.size()-1;
    while (l < r) {
      if (s[l] == s[r]) {
        ++l; --r;
      } else {
        bool delete_left = true;
        int left = l, right = r;  // backup l and r
        ++l;
        while (l < r) {
          if (s[l] == s[r]) {
            ++l; --r;
          } else {
            delete_left = false;
            break;
          }
        }
        if (delete_left) return true;
        l = left; r = right;
        --r;
        while (l < r) {
          if (s[l] == s[r]) {
            ++l; --r;
          } else {
            return false;
          }
        }
        return true;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  string a = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
  a = "cuppucu";
  cout << s.validPalindrome(a) << endl;
  return 0;
}
