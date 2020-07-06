#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(), digits.end());
    vector <int>::iterator iter = digits.begin();
    int carry = 1;
    while (carry) {
      if (iter == digits.end()) {
        digits.emplace_back(1);
        break;
      }
      if (*iter == 9) {
        *iter = 0;
      } else {
        ++(*iter);
        carry = 0;
      }
      ++iter;
    }
    reverse(digits.begin(), digits.end());
    return digits;
  }
};

int main() {
  vector <int> a = {9,9,9};
  Solution s;
  vector <int> b = s.plusOne(a);
  for (int i=0; i < b.size(); ++i)
    cout << b[i] << " ";
  cout << endl;

  return 0;
}
