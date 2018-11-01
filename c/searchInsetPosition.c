#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
  int i=0;
  while (i < numsSize && *(nums+i) < target){
    i++;
  }
  return i;
}

int main(){
  int *a, b[4] = {1,3,5,6}, t=4;
  a = b;
  printf("%d\n", searchInsert(a, 4, t));
  return 0;
}
