#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gTotal = 0, cTotal = 0, bestMount = 0, bestPos = 0;
    for (int i=0; i < gas.size(); i++) {
      gTotal += gas[i];
      cTotal += cost[i];
      int temp = gas[i] - cost[i] + gas[(i+1)%gas.size()];
      if (temp > bestMount) {
	//cout << temp << endl;
	bestMount = temp;
	bestPos = i;
      }
    }
    return gTotal >= cTotal ?  bestPos : -1;
  }
};


int main() {
  vector <int> a = /*{1,2,3,4,5};*/{5,8,2,8};
  vector <int> b = /*{3,4,5,1,2};*/{6,5,6,6};
  Solution s;
  cout << s.canCompleteCircuit(a, b) << endl;
  return 0;
}
