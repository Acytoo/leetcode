#include <iostream>
#include <string>
using namespace std;

static auto x = [](){
  // turn off sync
  std::ios::sync_with_stdio(false);
  // untie in/out streams
  std::cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    if (x < 10)
      return true;
    string str_x = to_string(x);
    int head=0,tail=str_x.size()-1;
    while (head < tail) {
      if (str_x[head] != str_x[tail])
        return false;
      head++;
      tail--;
    }
    return true;
  }
};

int main(){
  Solution s;
  cout << s.isPalindrome(434) << endl;
  return 0;
}
