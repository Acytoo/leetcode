#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    double tmp_x = sqrt(2*candies+0.25)-0.5;
    int x = (int) tmp_x;        // x is the max number of candies distribute in normal sequence, or distribute times, since these two numbers are same.
    int candies_left = candies - (1+x)*x/2;
    int last_person = x % num_people;
    vector<int> res(num_people, 0);
    res[last_person] = candies_left;
    int rounds = (int)x / num_people;
    for (int i=0; i<num_people; ++i) {
      int term = rounds;
      if (i<last_person)
        res[i] += i+1+term*num_people;
      while (term) {
        res[i] += (i+1) + (--term)*num_people;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> res = s.distributeCandies(11, 4);
  for (auto i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
