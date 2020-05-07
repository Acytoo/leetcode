#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b)                                \
  ({ __typeof__ (a) _a = (a);                   \
    __typeof__ (b) _b = (b);                    \
    _a > _b ? _a : _b; })

int longestMountain(int* A, int ASize){
  if (!ASize) return 0;
  int inc[ASize], dec[ASize];
  memset(inc, 0, sizeof(inc));
  memset(dec, 0, sizeof(inc));

  for (int i = 1; i < ASize; ++i)
    if (A[i - 1] < A[i]) inc[i] = inc[i - 1] + 1;
  for (int i = ASize - 2; i >= 0; --i)
    if (A[i + 1] < A[i]) dec[i] = dec [i + 1] + 1;

  int res = 0;
  for (int i = 0; i < ASize; ++i)
    if (inc[i] && dec[i])
      res = max(res, inc[i] + dec[i] + 1);
  return res >= 3? res: 0;
}

int main() {
  /* int a[] = {2,1,4,7,3,2,5}; */
  int a[] = {2,2,2};
  printf("%d\n", longestMountain(a, sizeof(a) / sizeof(int)));
  return 0;
}
