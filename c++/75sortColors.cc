#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return;
    auto p1 = nums.begin(), p2 = nums.end()-1, p3 = nums.begin();
    while (p3 != p2) {
      //      cout << "p1 " << *p1 << " p3 " << *p3 << " p2 " << *p2 << endl;
      if (*p1 == 0) {++p1; p3 = p1; continue;}
      if (*p2 == 2) {--p2; continue;}
      //      p3 = p1;
      if (*p3 == 1) {++p3; continue;}
      if (*p3 == 2) {swap(*p2, *p3); continue;}
      if (*p3 == 0) {swap(*p1, *p3); continue;}
    }
    if (*p3 == 0) swap(*p1, *p3);
    else if (*p3 == 2) swap(*p2, *p3);
  }
};


int main() {
  Solution s;
  vector<int> a = {2,0,2,1,1,1,1,1,0,0,1,2,1,0,1,2,2,2,2,2,0};
  // auto p1 = a.begin(), p2 = a.end()-1;
  // swap (*p1, *p2);

  
  s.sortColors(a);
  for (auto iter = a.cbegin(); iter != a.cend(); iter++)
    cout << *iter << " ";
  cout << endl;
  return 0;
}
