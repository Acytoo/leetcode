#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(), digits.end());
    vector <int>::iterator iter = digits.begin();
    while (*iter > 8) {
      *iter = 0;
      iter++;
      if (iter == digits.end()) {
        *iter = 0;
        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
      }
    }
    *iter = *iter + 1;
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
