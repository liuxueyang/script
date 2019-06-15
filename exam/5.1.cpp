#include <stdio.h>
void binsearch(int x, int*a, int len) {
  int low=0, high=len-1, mid;
  while (low < high) {
    mid=(low+high)/2;
    if (a[mid]==x) {
      printf("pos=%d\n", mid+1);
      return;
    }
    if (a[mid]>x) high=mid-1;
    else low=mid+1;
  }
  if(a[low]==x) printf("pos=%d\n", low+1);
  else printf("not found!\n");
}
int main(void) {
  int x, a[10]; scanf("%d", &x);
  for(int i=0; i<10; ++i) a[i] = i+1;
  binsearch(x, a, 10);
  return 0;
}
