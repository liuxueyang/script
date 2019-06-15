#include <stdio.h>
#include <string.h>
int main(void) {
  char a[20] = "abcd";
  printf("%d, %d", sizeof a, strlen(a));
  return 0;
}
