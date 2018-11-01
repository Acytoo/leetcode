#include <iostream>
#include <vector>

using namespace std;
//数组是排序的，那么有两个指针，第一个指针由前到后，第二个指针由后到前，若踬顿在大或者小的情况，则第一个指针（头指针由前向后一个位置，第二个指针在前情况转折处向后扫描，下次变换向前扫，再向后。如此）


public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int head = 0, tail = nums.size() - 1, total = nums[head]+nums[tail];
    while (total != target) {
      if (total < target){
	head++;
	total = nums[head]+nums[tail];
      }
      else {
	tail--;
	total = nums[head]+nums[tail];
      }
    }
    return {head+1, tail+1};
  }
};


int main() {
  vector <int> a = {2,7,8,9};
  int t = 17;
  Solution s;
  vector <int> res = s.twoSum(a, t);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
