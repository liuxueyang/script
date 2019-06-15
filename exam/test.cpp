#include <stdio.h>
#include <string.h>
int main(void) {
  char a[20] = "abcd";
  printf("%d, %d\n", sizeof a, strlen(a));

  struct packed_int {
    unsigned a:2;
    unsigned b:3;
    unsigned c:4;
    int I;
  }data;

  data.a=8;
  data.b=2;
  printf("%d\n", data.a+data.b);

  // char a_[3], b_[] = "student";
  // a_ = b_;
  // printf("a=%s", a_);

  static int aa[2][3] = {{1,2,3}, {4,5,6}};
  int m; m=*(*(aa+1)+1);
  m=m*aa[1][1];
  printf("m=%d\n", m);

  int s = 'a'<<3;
  printf("s=%d\n", s);

  int x=0x3, y=0x2;
  x<<=y;
  printf("%d", x);

  return 0;
}
