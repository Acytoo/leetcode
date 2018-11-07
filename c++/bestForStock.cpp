#include <iostream>
#include <vector>
//#include <cmath>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ret = 0, i=0, n = prices.size()-1;
      
      while (i < n) 
	ret += max(prices[i+1] - prices[i++], 0);
      return ret;
    }
};

int main() {

  vector <int> a = {};
  Solution s;
  cout << s.maxProfit(a) << endl;
  return 0;
}
