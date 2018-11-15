#include <iostream>
#include <vector>
using namespace std;


static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = -1, gasRest = 0, costMost = 0;
    for (int i = 0; i < gas.size(); i++){
      gasRest += gas[i]-cost[i];
      if (costMost > gasRest){
	costMost = gasRest;
	res = i;
      }
    }
    if (gasRest < 0)
      return -1;
    return res + 1;
  }
};

class Solution1 {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gTotal = 0, cTotal = 0, rest[gas.size()] = {0};
    vector <int> possible;
    for (int i=0; i < gas.size(); i++) {
      gTotal += gas[i];
      cTotal += cost[i];
      rest[i] = gas[i] - cost[i];
      if (rest[i] >= 0) { //  no = 0
        possible.push_back(i);
      }
    }
    if (gTotal < cTotal)
      return -1;
    int len = gas.size(), station = possible.back(), gasAva = 0, res = station;
    while (possible.size() > 1) {
      len = gas.size();
      station = possible.back();
      gasAva = 0;
      res = station;
      possible.pop_back();
      while (len > -1) {
	gasAva += rest[station%gas.size()];
	len--;
	station++;
	if (gasAva < 0)
	  break;
      }
      if (len == -1)
	return res;
    }
    return possible.back();
  }
};



int main() {
  vector <int> a = /*{5,1,2,3,4};*//*{2};*//*{1,2,3,4,5};*/{5,8,2,8};
  vector <int> b = /*{4,4,1,5,1};*//*{2};*//*{3,4,5,1,2};*/{6,5,6,6};
  Solution s;
  cout << s.canCompleteCircuit(a, b) << endl;
  return 0;
}
