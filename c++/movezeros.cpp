#include <iostream>
#include <vector>
using namespace std;

//from head to head, scan all the nums. Until find the first 0, shift all the follows with none zero.
// so there might be two iterators, one for zero position, one for scan position. 
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int amount = 0;
    //    vector<int>::iterator tail = nums.end();
    for (vector<int>::iterator head = nums.begin(); head != nums.end(); head++)
      if (*head == 0) {
	amount++;
	head = nums.erase(head)-1;
	//	nums.push_back(0);
      }/*
    for (int i=0; i < amount; i++)
    nums.push_back(0);*/
    for (int i=0; i < nums.size(); ++i)
      cout << nums[i] << " ";
      cout << endl;
  }
};
int main() {
  Solution s;
  vector <int> a = {1,0,2,0,3,4,5,6,0,6,7};
  s.moveZeroes(a);

  return 0;
}
