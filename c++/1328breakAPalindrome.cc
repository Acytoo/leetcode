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
  string breakPalindrome(string palindrome) {
    const int n = palindrome.size();
    if (n == 1) return "";
    int mid = n >> 1;
    for (int i = 0; i < mid; ++i)
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }

    palindrome[n - 1] = 'b';
    return palindrome;
  }
};

int main() {
  Solution s;
  
  return 0;
}
