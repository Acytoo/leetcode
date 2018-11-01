#include <iostream>
#include <vector>
using namespace std;


/*
从左向右扫,记录一个最大值和最小值,如果继续扫描中遇到更小的,就记录这个最小的,但不更新, 如果遇到更大的,就更新最大值和最小值



 */
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<int>::iterator head = prices.begin();
    vector<int>::iterator tail = prices.end();
    if (prices.size() < 2)
      return 0;
    if (prices.size() < 3)
      {int pro = prices[1] - prices[0];return pro > 0 ? pro : 0;}
    int max =  prices[1], min = prices[0], min_temp = prices[0], max_temp = prices[1];
    
    for (int i=1; i < prices.size(); i++) {
      if (prices[i] < min_temp) {
	min_temp = prices[i];
	
      }
      else
	if (prices[i] >= max) {
	  max = prices[i];
	  min = min_temp;
	  continue;
	}
      if (prices[i] - min_temp > max - min) {
	max = prices[i];
	min = min_temp;
      }
      
    }
    int pro = max - min;
    return pro > 0 ? pro : 0;
  }
};

int main() {
  vector <int> arr = {3,3,5,0,0,3,1,4};
  Solution s;
  cout << s.maxProfit(arr) << endl;
  return 0;
}
