#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1=nums1.size(), l2=nums2.size();
    /*    if (nums1[l1-1] < nums2[0])
	  return (nums1[(l1+1)/2]+nums1[(l1+1)/2+(l1+1)%2])/2;*/
    
    
    if ((l1+l2)%2 == 0) {
      //even : (m1+m2)/2
      
    }
    else {
      //odd
      
    }
  }
};


int main() {


  return 0;
}
